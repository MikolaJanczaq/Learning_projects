#ifndef RENTBOOKDIALOG_H
#define RENTBOOKDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class RentBookDialog;
}

class RentBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RentBookDialog(QWidget *parent = nullptr);
    ~RentBookDialog();

    void setBookDetails(const QString &title, const QString &author);
    void setPersonName(const QString &name);
    QDate getReturnDate() const;

private:
    Ui::RentBookDialog *ui;
};

#endif // RENTBOOKDIALOG_H
