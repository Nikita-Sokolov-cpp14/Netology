#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent),
ui(new Ui::MainWindow),
stopwatch(NULL),
timerState(Is_off) {
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);

    ui->pb_lap->setEnabled(false);
    ui->pb_clear->setEnabled(false);
    ui->lab_fulTime->setText("0:00:000");

    QObject::connect(stopwatch, &Stopwatch::sig_sendFullTime, this, &MainWindow::rcvFullTime);
    QObject::connect(stopwatch, &Stopwatch::sig_fixLap, this, &MainWindow::rcvLap);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::rcvFullTime(const int msecs) {
    ui->lab_fulTime->setText(convertMsecToMSMSEC(msecs));
}

void MainWindow::rcvLap(const int lap, const int msec) {
    ui->tb_TImeBrowser->append(QString("Круг №%1. Время: %2").arg(lap).arg(convertMsecToMSMSEC(msec)));
}

void MainWindow::on_pb_start_clicked() {
    if (timerState == Is_off) {
        stopwatch->start();

        ui->pb_start->setText("Стоп");
        ui->pb_lap->setEnabled(true);
        ui->pb_clear->setEnabled(true);
        timerState = Is_on;
    } else {
        stopwatch->stop();

        ui->pb_start->setText("Старт");
        ui->pb_lap->setEnabled(false);
        ui->pb_clear->setEnabled(false);
        timerState = Is_off;
    }
}

void MainWindow::on_pb_clear_clicked() {
    ui->tb_TImeBrowser->clear();
    stopwatch->clear();
}

void MainWindow::on_pb_lap_clicked() {
    stopwatch->fixLap();
}

QString MainWindow::convertMsecToMSMSEC(const int msec) {
    int ms = msec % 1000;
    int sec = (msec / 1000) % 60;
    int min = (msec / (60 * 1000)) % 60;

    QString stringTime = QString("%1:%2:%3").arg(min).arg(sec).arg(ms);

    return stringTime;
}

