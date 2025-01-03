#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QTimer(parent),
timer(parent),
timerLap(parent),
startTime(),
startLapTime(),
lapTime(),
countLaps(0){
}

Stopwatch::~Stopwatch() {}

void Stopwatch::clear() {
    countLaps = 0;
    timer.stop();
    start();
}

void Stopwatch::fixLap()
{
    countLaps++;
    timerLap.stop();
    emit sig_fixLap(countLaps, startLapTime.msecsTo(lapTime));

    timerLap.start(10);
    startLapTime = QTime::currentTime();
    QObject::connect(&timerLap, &QTimer::timeout, this, [&](){
        lapTime = QTime::currentTime();
    });
}

void Stopwatch::start() {
    emit sig_start();
    timer.start(10);
    timerLap.start(10);
    startTime = QTime::currentTime();
    startLapTime = QTime::currentTime();

    QObject::connect(&timer, &QTimer::timeout, this, [&](){
        QTime currentTime = QTime::currentTime();
        emit sig_sendFullTime(startTime.msecsTo(currentTime));
    });

    QObject::connect(&timerLap, &QTimer::timeout, this, [&](){
        lapTime = QTime::currentTime();
    });
    countLaps = 0;
}

void Stopwatch::stop() {
    emit sig_stop();
    timer.stop();
}
