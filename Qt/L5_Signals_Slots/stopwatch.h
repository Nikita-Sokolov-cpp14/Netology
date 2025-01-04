#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Stopwatch : public QTimer
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject* parent = nullptr);
    ~Stopwatch();

    void start();
    void stop();
    void clear();
    void fixLap();

signals:
    void sig_sendFullTime(const int msec);
    void sig_fixLap(const int lap, const int msec);

private:
    QTimer timer;
    QTimer timerLap;
    QTime startTime;
    QTime startLapTime;
    QTime lapTime;

    int countLaps;
};

#endif // STOPWATCH_H
