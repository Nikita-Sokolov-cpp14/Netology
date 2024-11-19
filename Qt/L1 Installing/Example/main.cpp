#include "mainwindow.h"
#include <QApplication>

#include "QMessageBox"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    QMessageBox msb;
    msb.setText("Hello graphic box");

    msb.show();
    return a.exec();
}
