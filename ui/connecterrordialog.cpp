#include "connecterrordialog.h"
#include "ui_connecterrordialog.h"

ConnectErrorDialog::ConnectErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectErrorDialog)
{
    ui->setupUi(this);
}

ConnectErrorDialog::~ConnectErrorDialog()
{
    delete ui;
}
