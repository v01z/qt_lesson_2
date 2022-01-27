#include "task2.h"
#include "ui_task2.h"
#include "codinglang.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>

//В зависимости от настроек IDE относительные пути для
//исполняемого файла могут отличаться
const QString DATA_PATH { "../qt_2/data/" };

task2::task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    if (!model) close();

    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "cpp.png"), "C++"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "python.png"), "Python"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "java.png"), "Java"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "csharp.png"), "C#"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "php.png"), "PHP"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "js.png"), "JavaScript"));

}

task2::~task2()
{
    if (model) {
        model->clear();
        delete model;
        model = nullptr;
    }

    delete ui;
}

void task2::on_btnClose_clicked()
{
   close();
}


void task2::on_btnChangeTxt_clicked()
{

    QModelIndex indx { ui->listView->currentIndex() };

    if (!indx.isValid())
    {
         QMessageBox::warning(this, "Wrong way.",
            "There is no item to change.");
        return;

    }

    QStandardItem *itm { model->itemFromIndex(indx) };

    bool ok { false };
    QString newStr { QInputDialog::getText(this, "Changing text.",
        "Change this text if you want:", QLineEdit::Normal, itm->text(), &ok) };
    if (ok && !newStr.isEmpty())
    {
        itm->setText(newStr);
    }


}


void task2::on_btnUp_clicked()
{

    CodingLang temp;

    QModelIndex indx { ui->listView->currentIndex() };
    QStandardItem *itm { model->itemFromIndex(indx) };

    temp.setIcon(itm->icon());
    temp.setName(itm->text());



    QModelIndex indx_prev = ui->listView->model()->index(indx.row() - 1, 0);

    if (!indx_prev.isValid())
    {
        QMessageBox::warning(this, "Wrong way.",
            "There is no previous item.");
        return;
    }

    QStandardItem *itm_prev { model->itemFromIndex(indx_prev) };

    itm->setIcon (itm_prev->icon());
    itm->setText(itm_prev->text());

    itm_prev->setIcon(temp.getIcon());
    itm_prev->setText(temp.getName());

    ui->listView->setCurrentIndex(indx_prev);

}


void task2::on_btnDown_clicked()
{

    CodingLang temp;

    QModelIndex indx { ui->listView->currentIndex() };
    QStandardItem *itm { model->itemFromIndex(indx) };

    temp.setIcon(itm->icon());
    temp.setName(itm->text());


    QModelIndex indx_next = ui->listView->model()->index(indx.row() + 1, 0);

    if (!indx_next.isValid())
    {
        QMessageBox::warning(this, "Wrong way.",
            "There is no next item.");
        return;
    }

    QStandardItem *itm_next { model->itemFromIndex(indx_next) };

    itm->setIcon (itm_next->icon());
    itm->setText(itm_next->text());

    itm_next->setIcon(temp.getIcon());
    itm_next->setText(temp.getName());

    ui->listView->setCurrentIndex(indx_next);

}


void task2::on_btnAdd_clicked()
{

    CodingLang newLang;
    bool ok { false };

    newLang.setName(QInputDialog::getText(this, "Changing text.",
        "Change this text if you want:", QLineEdit::Normal, "", &ok));

    if (ok && !newLang.getName().isEmpty())
    {
        newLang.setIcon(QIcon(QFileDialog::getOpenFileName(this, "Choosing image.", "",
            "Address Book (*.png);;All Files (*)")));

        if (!newLang.getIcon().isNull())
            model->appendRow(new QStandardItem(newLang.getIcon(), newLang.getName()));
    }
}


void task2::on_btnDel_clicked()
{
    if (model->rowCount() < 1)
    {
         QMessageBox::warning(this, "U doing wrong.",
            "There is no item to delete.");
        return;

    }

    QModelIndex indx { ui->listView->currentIndex() };
    QStandardItem *itm { model->itemFromIndex(indx) };

    model->removeRow(itm->row());

}


void task2::on_cbxViewModeSwitcher_clicked()
{
   if (ui->cbxViewModeSwitcher->isChecked())
       ui->listView->setViewMode(QListView::IconMode);
   else
       ui->listView->setViewMode(QListView::ListMode);
}

