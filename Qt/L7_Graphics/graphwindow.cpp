#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

    graphClass = new Graphic(ui->GraphWidget, 1);
}

GraphWindow::~GraphWindow()
{
    delete ui;
    delete graphClass;
}

void GraphWindow::addGraph(const QVector<double> &x, const QVector<double> &y)
{
    graphClass->ClearGraph(ui->GraphWidget);
    graphClass->AddDataToGrahp(x, y, 0);
    graphClass->UpdateGraph(ui->GraphWidget);
}
