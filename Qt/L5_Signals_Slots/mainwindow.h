#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE

enum TimerState {
    Is_on,
    Is_off
};

namespace Ui {

class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void rcvOnStart();
    void rcvOnStop();
    void rcvFullTime(const int msecs);
    void rcvLap(const int lap, const int msec);

    void on_pb_start_clicked();

    void on_pb_clear_clicked();

    void on_pb_lap_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    TimerState timerState;

    QString convertMsecToMSMSEC(const int msec);
};
#endif // MAINWINDOW_H
