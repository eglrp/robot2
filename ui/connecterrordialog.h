#ifndef CONNECTERRORDIALOG_H
#define CONNECTERRORDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectErrorDialog;
}

class ConnectErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectErrorDialog(QWidget *parent = 0);
    ~ConnectErrorDialog();

private:
    Ui::ConnectErrorDialog *ui;
};

#endif // CONNECTERRORDIALOG_H
