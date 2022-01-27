#include "task3.h"
#include "ui_task3.h"

task3::task3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);

     model = new QStandardItemModel(this);
    if (!model) close();

    ui->tableView->setModel(model);

    std::vector< QList<QStandardItem*> > MachinePark;

    for (const auto elem: LAN_NET_PARK)
    {
        QList<QStandardItem*> temp;

        temp.append(new QStandardItem(elem.Number));
        temp.append(new QStandardItem(elem.Hostname));
        temp.append(new QStandardItem(elem.IPaddress));
        temp.append(new QStandardItem(elem.MACaddress));

        model->appendRow(temp);
    }

    ui->tableView->setStyleSheet("QTableView {selection-background-color: red;}");

}

task3::~task3()
{
    if (model) {
        model->clear();
        delete model;
        model = nullptr;
    }

    delete ui;
}

void task3::on_btnClose_clicked()
{
   close();
}

