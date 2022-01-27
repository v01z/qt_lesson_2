#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnTask1_clicked()
{
   task1 form;
   form.setModal(true);
   form.exec();
}


void MainWindow::on_btnTask2_clicked()
{
   task2 form;
   form.setModal(true);
   form.exec();

}


void MainWindow::on_btnTask3_clicked()
{
   task3 form;
   form.setModal(true);
   form.exec();

}


void MainWindow::on_btnExit_clicked()
{
   QApplication::quit();
}

