#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include "qcustomplot.h"
#include "graphic.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

    void addGraph(const QVector<double> &x, const QVector<double> &y);

private:
    Ui::GraphWindow *ui;

    QCPGraph *graphic;
    Graphic *graphClass;
};

#endif // GRAPHWINDOW_H
