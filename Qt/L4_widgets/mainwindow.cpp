#include "mainwindow.h"
#include "./ui_mainwindow.h"

struct Passenger {
    QString firstName;
    QString lastName;
    QDate birthDate;
};

Passenger passenger;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->PBPassengers->setValue(0);
    ui->PBPassengers->setMaximum(10);
    ui->PBPassengers->setMinimum(0);
    ui->PBPassengers->setFormat("%v");
    ui->de_birthDate->setDate(QDate(2000, 12, 31));
    ui->le_FirstName->setText("<fisrt_name>");
    ui->le_LastName->setText("<last_name>");
    ui->te_passengers->setReadOnly(true);
    ui->pb_enableLog->setCheckable(true);
    ui->pb_enableLog->setEnabled(true);
    ui->rb_there->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_le_FirstName_textChanged(const QString &arg1)
{
    passenger.firstName = ui->le_FirstName->text();
}

void MainWindow::on_le_LastName_textChanged(const QString &arg1)
{
    passenger.lastName = ui->le_LastName->text();
}

void MainWindow::on_de_birthDate_dateChanged(const QDate &date)
{
    passenger.birthDate = ui->de_birthDate->date();
}

void MainWindow::on_lb_addPassenger_clicked()
{
    int pasNumber = ui->PBPassengers->value();
    if (pasNumber >= 10) {
        pasNumber = 0;
        ui->PBPassengers->setValue(0);
        ui->te_passengers->clear();
        return;
    }

    ++pasNumber;
    ui->PBPassengers->setValue(pasNumber);
    if (ui->pb_enableLog->isChecked()) {
        ui->te_passengers->append(QString("Passenger %1").arg(pasNumber));
        ui->te_passengers->append(passenger.firstName);
        ui->te_passengers->append(passenger.lastName);
        ui->te_passengers->append(passenger.birthDate.toString());
        ui->te_passengers->append("");
    }
}

void MainWindow::on_pb_clear_clicked()
{
    ui->te_passengers->clear();
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->cb_routes->currentText();

    if (ui->rb_there->isChecked()) {
        text += " (туда)";
    } else {
        text += " (туда-обратно)";
    }

    ui->le_route->setText(text);
}

