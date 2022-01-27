#include "task1.h"
#include "ui_task1.h"

task1::task1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task1)
{
    ui->setupUi(this);
    parseText = new ParseText();
    if (!parseText) close();
}

task1::~task1()
{
    if(parseText) {
        delete parseText;
        parseText = nullptr;
    }

    delete ui;
}

void task1::on_btnClose_clicked()
{
   close();
}

void task1::on_plainTextEdit_textChanged()
{
   if (parseText->findAndReplace(ui->plainTextEdit->toPlainText()))
       ui->plainTextEdit->setPlainText(parseText->getText());
}



