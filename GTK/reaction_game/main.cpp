#include <gtk/gtk.h>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <random>

using namespace std;

const int MAX_CIRCLES = 15;
const int GAME_DURATION = 60;
const int CLICK_DISPLAY_TIME = 200;
const char HIGHSCORE_FILE[] = "scores.txt";

struct Circle {
    double x;
    double y;
    double radius;
    gint64 creation_time;
    bool active;
    bool clicked;
    gint64 click_time;
};

class GameManager {
public:
    vector<Circle> circles;
    int score = 0;
    int time_left = GAME_DURATION;
    int difficulty = 4000;
    int spawn_delay = 800;
    double circle_radius = 35;
    int total_clicks = 0;
    int successful_clicks = 0;
    int total_circles = 0;
    int missed_circles = 0;

    GtkWidget *score_label;
    GtkWidget *time_label;
    GtkWidget *combo_box;
    GtkWidget *drawing_area;

    guint spawn_timer = 0;
    guint update_timer = 0;
    guint countdown_timer = 0;

    GameManager() {
        circles.resize(MAX_CIRCLES);
    }

    void reset() {
        score = 0;
        time_left = GAME_DURATION;
        total_clicks = 0;
        successful_clicks = 0;
        total_circles = 0;
        missed_circles = 0;

        for (auto& circle : circles) {
            circle.active = false;
            circle.clicked = false;
        }

        gtk_label_set_text(GTK_LABEL(score_label), "Wynik: 0");
        gtk_label_set_text(GTK_LABEL(time_label), "Czas: 01:00");
    }

    void save_highscore(const string& name, float accuracy, const string& difficulty) {
        ofstream file(HIGHSCORE_FILE, ios::app);
        if (file) {
            time_t now = time(nullptr);
            tm* t = localtime(&now);
            file << put_time(t, "%d-%m-%Y %H:%M") << "|"
                 << name << "|" << score << "|"
                 << fixed << setprecision(2) << accuracy << "|"
                 << difficulty << "\n";
        }
    }

    static gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
        GameManager *gm = static_cast<GameManager*>(data);

        cairo_set_source_rgb(cr, 1, 1, 1);
        cairo_paint(cr);

        for (const auto& circle : gm->circles) {
            if (circle.active) {
                cairo_set_source_rgb(cr, circle.clicked ? 0 : 0, circle.clicked ? 1 : 0, circle.clicked ? 0 : 1);
                cairo_arc(cr, circle.x, circle.y, circle.radius, 0, 2 * G_PI);
                cairo_fill_preserve(cr);
                cairo_set_source_rgb(cr, 0, 0, 0);
                cairo_stroke(cr);
            }
        }
        return FALSE;
    }

    static gboolean click_callback(GtkWidget *widget, GdkEventButton *event, gpointer data) {
        GameManager *gm = static_cast<GameManager*>(data);
        gm->total_clicks++;

        if (event->button == GDK_BUTTON_PRIMARY) {
            for (auto& circle : gm->circles) {
                if (circle.active && !circle.clicked) {
                    double dx = event->x - circle.x;
                    double dy = event->y - circle.y;
                    if ((dx*dx + dy*dy) <= (circle.radius * circle.radius)) {
                        circle.clicked = true;
                        circle.click_time = g_get_monotonic_time();
                        gm->score++;
                        gm->successful_clicks++;

                        string score_text = "Wynik: " + to_string(gm->score);
                        gtk_label_set_text(GTK_LABEL(gm->score_label), score_text.c_str());
                        gtk_widget_queue_draw(gm->drawing_area);
                        return TRUE;
                    }
                }
            }
        }
        return FALSE;
    }

    static gboolean update_circles(gpointer data) {
        GameManager *gm = static_cast<GameManager*>(data);
        gint64 now = g_get_monotonic_time();
        gboolean redraw = FALSE;

        for (auto& circle : gm->circles) {
            if (circle.active) {
                if (circle.clicked) {
                    if ((now - circle.click_time) > CLICK_DISPLAY_TIME * 1000) {
                        circle.active = false;
                        redraw = TRUE;
                    }
                } else if ((now - circle.creation_time) > gm->difficulty * 1000) {
                    circle.active = false;
                    gm->missed_circles++;
                    redraw = TRUE;
                }
            }
        }

        if (redraw) gtk_widget_queue_draw(gm->drawing_area);
        return G_SOURCE_CONTINUE;
    }

    static gboolean spawn_circle(gpointer data) {
    GameManager *gm = static_cast<GameManager*>(data);
    GtkAllocation allocation;
    gtk_widget_get_allocation(gm->drawing_area, &allocation);

    if (allocation.width < 2*gm->circle_radius || allocation.height < 2*gm->circle_radius) {
        return G_SOURCE_CONTINUE;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> x_dist(gm->circle_radius, allocation.width - gm->circle_radius);
    std::uniform_real_distribution<double> y_dist(gm->circle_radius, allocation.height - gm->circle_radius);

    const int MAX_ATTEMPTS = 50;
    const double MIN_DISTANCE_SQ = pow(2 * gm->circle_radius, 2);

    for (auto& circle : gm->circles) {
        if (!circle.active) {
            bool position_found = false;
            double new_x, new_y;

            for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
                new_x = x_dist(gen);
                new_y = y_dist(gen);
                bool collision = false;

                for (const auto& other : gm->circles) {
                    if (other.active) {
                        double dx = new_x - other.x;
                        double dy = new_y - other.y;
                        if (dx*dx + dy*dy < MIN_DISTANCE_SQ) {
                            collision = true;
                            break;
                        }
                    }
                }

                if (!collision) {
                    position_found = true;
                    break;
                }
            }

            if (position_found) {
                circle.x = new_x;
                circle.y = new_y;
                circle.radius = gm->circle_radius;
                circle.creation_time = g_get_monotonic_time();
                circle.active = true;
                circle.clicked = false;
                gm->total_circles++;
                gtk_widget_queue_draw(gm->drawing_area);
            }
            break;
        }
    }
    return G_SOURCE_CONTINUE;
}

    static gboolean countdown(gpointer data) {
        GameManager *gm = static_cast<GameManager*>(data);

        if (gm->time_left > 0) {
            gm->time_left--;
            int minutes = gm->time_left / 60;
            int seconds = gm->time_left % 60;
            ostringstream oss;
            oss << "Czas: " << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << seconds;
            gtk_label_set_text(GTK_LABEL(gm->time_label), oss.str().c_str());
        } else {
            g_source_remove(gm->spawn_timer);
            g_source_remove(gm->update_timer);
            g_source_remove(gm->countdown_timer);

            float accuracy = gm->total_clicks > 0 ?
                (static_cast<float>(gm->successful_clicks) / gm->total_clicks) * 100 : 0.0f;

            int total_active = gm->successful_clicks + gm->missed_circles;
            float miss_rate = total_active > 0 ?
                (static_cast<float>(gm->missed_circles) / total_active) * 100 : 0.0f;

            GtkWidget *dialog = gtk_message_dialog_new(
                GTK_WINDOW(gtk_widget_get_toplevel(gm->drawing_area)),
                GTK_DIALOG_DESTROY_WITH_PARENT,
                GTK_MESSAGE_INFO,
                GTK_BUTTONS_OK,
                "KONIEC GRY!\n\n"
                "Statystyki:\n"
                "• Wynik: %d\n"
                "• Celność: %.1f%% (%d/%d)\n"
                "• Pominięte: %d (%.1f%%)\n"
                "• Łącznie kółek: %d",
                gm->score,
                accuracy,
                gm->successful_clicks,
                gm->total_clicks,
                gm->missed_circles,
                miss_rate,
                gm->total_circles
            );
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);

            GtkWidget *name_dialog = gtk_dialog_new_with_buttons(
                "Zapisz wynik",
                GTK_WINDOW(gtk_widget_get_toplevel(gm->drawing_area)),
                GTK_DIALOG_MODAL,
                "Zapisz",
                GTK_RESPONSE_ACCEPT,
                "Anuluj",
                GTK_RESPONSE_REJECT,
                NULL);

            GtkWidget *content = gtk_dialog_get_content_area(GTK_DIALOG(name_dialog));
            GtkWidget *entry = gtk_entry_new();
            gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Wprowadź swoje imię");
            gtk_container_add(GTK_CONTAINER(content), entry);
            gtk_widget_show_all(name_dialog);

            if (gtk_dialog_run(GTK_DIALOG(name_dialog)) == GTK_RESPONSE_ACCEPT) {
                const char *name = gtk_entry_get_text(GTK_ENTRY(entry));
                const char *difficulty = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(gm->combo_box));
                if (strlen(name) > 0) {
                    gm->save_highscore(name, accuracy, difficulty);
                }
            }

            gtk_widget_destroy(name_dialog);
            gm->reset();
        }
        return G_SOURCE_CONTINUE;
    }

    static void start_game(GtkButton *button, gpointer data) {
        GameManager *gm = static_cast<GameManager*>(data);

        if (gm->spawn_timer) g_source_remove(gm->spawn_timer);
        if (gm->update_timer) g_source_remove(gm->update_timer);
        if (gm->countdown_timer) g_source_remove(gm->countdown_timer);

        //gm->reset();

        const gchar *difficulty = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(gm->combo_box));
        if (strcmp(difficulty, "Średni") == 0) {
            gm->difficulty = 3000;
            gm->spawn_delay = 700;
            gm->circle_radius = 25;
        }
        else if (strcmp(difficulty, "Trudny") == 0) {
            gm->difficulty = 1500;
            gm->spawn_delay = 400;
            gm->circle_radius = 15;
        }
        else {
            gm->difficulty = 4000;
            gm->spawn_delay = 800;
            gm->circle_radius = 35;
        }

        gm->spawn_timer = g_timeout_add(gm->spawn_delay, spawn_circle, gm);
        gm->update_timer = g_timeout_add(100, update_circles, gm);
        gm->countdown_timer = g_timeout_add_seconds(1, countdown, gm);
    }

    static void show_highscores(GtkButton *button, gpointer data) {
        GameManager *gm = static_cast<GameManager*>(data);

        GtkWidget *dialog = gtk_dialog_new_with_buttons(
            "Najlepsze wyniki",
            GTK_WINDOW(gtk_widget_get_toplevel(gm->drawing_area)),
            GTK_DIALOG_MODAL,
            "OK",
            GTK_RESPONSE_ACCEPT,
            NULL);

        gtk_window_set_default_size(GTK_WINDOW(dialog), 800, 500);

        GtkWidget *content = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
        GtkWidget *text_view = gtk_text_view_new();
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

        PangoFontDescription *font_desc = pango_font_description_from_string("Monospace 12");
        gtk_widget_override_font(text_view, font_desc);
        pango_font_description_free(font_desc);

        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                      GTK_POLICY_ALWAYS,
                                      GTK_POLICY_ALWAYS);

        stringstream ss;
        ss << left
           << setw(18) << "Data"
           << setw(15) << "Gracz"
           << setw(8) << "Wynik"
           << setw(10) << "Celność"
           << "Poziom\n";
        ss << "--------------------------------------------------------------------\n";

        ifstream file(HIGHSCORE_FILE);
        if (file) {
            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                string date, name, difficulty;
                int score;
                float accuracy;
                char separator;

                if (getline(iss, date, '|') &&
                    getline(iss, name, '|') &&
                    (iss >> score >> separator) &&
                    (iss >> accuracy >> separator) &&
                    getline(iss, difficulty)) {

                    if (name.length() > 12) {
                        name = name.substr(0, 9) + "...";
                    }

                    ss << left
                       << setw(18) << date.substr(0, 16)
                       << setw(15) << name
                       << setw(8) << score
                       << fixed << setprecision(1)
                       << accuracy << setw(5)<< "%"
                        << difficulty
                       << "\n";
                }
            }
        } else {
            ss << "Brak zapisanych wyników";
        }

        gtk_text_buffer_set_text(buffer, ss.str().c_str(), -1);

        gtk_container_add(GTK_CONTAINER(scrolled), text_view);
        gtk_container_add(GTK_CONTAINER(content), scrolled);
        gtk_widget_set_hexpand(scrolled, TRUE);
        gtk_widget_set_vexpand(scrolled, TRUE);

        gtk_widget_show_all(dialog);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
};

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Test reakcji");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    auto gm = make_unique<GameManager>();

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    GtkWidget *left_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gm->combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(gm->combo_box), "Łatwy");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(gm->combo_box), "Średni");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(gm->combo_box), "Trudny");
    gtk_combo_box_set_active(GTK_COMBO_BOX(gm->combo_box), 0);

    GtkWidget *start_button = gtk_button_new_with_label("Start");
    gtk_box_pack_start(GTK_BOX(left_box), gm->combo_box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(left_box), start_button, FALSE, FALSE, 0);

    GtkWidget *center_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gm->score_label = gtk_label_new("Wynik: 0");
    gm->time_label = gtk_label_new("Czas: 01:00");
    gtk_box_pack_start(GTK_BOX(center_box), gm->score_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(center_box), gm->time_label, FALSE, FALSE, 0);

    GtkWidget *scores_button = gtk_button_new_with_label("Wyniki");

    gtk_box_pack_start(GTK_BOX(hbox), left_box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), center_box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0), TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(hbox), scores_button, FALSE, FALSE, 0);

    gm->drawing_area = gtk_drawing_area_new();
    gtk_widget_set_hexpand(gm->drawing_area, TRUE);
    gtk_widget_set_vexpand(gm->drawing_area, TRUE);
    gtk_widget_add_events(gm->drawing_area, GDK_BUTTON_PRESS_MASK);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(start_button, "clicked", G_CALLBACK(GameManager::start_game), gm.get());
    g_signal_connect(scores_button, "clicked", G_CALLBACK(GameManager::show_highscores), gm.get());
    g_signal_connect(gm->drawing_area, "draw", G_CALLBACK(GameManager::draw_callback), gm.get());
    g_signal_connect(gm->drawing_area, "button-press-event", G_CALLBACK(GameManager::click_callback), gm.get());

    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), gm->drawing_area, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
