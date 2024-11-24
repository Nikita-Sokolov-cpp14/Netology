#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dlg = new Dialog(this);
}

MainWindow::~MainWindow()
{
    delete dlg;
    delete ui;
}

void MainWindow::on_pbtn_cratedb_pressed()
{
    dlg->show();
}

