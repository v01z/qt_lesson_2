#ifndef TASK1_H
#define TASK1_H

#include <QDialog>
#include "parsetext.h"

namespace Ui {
class task1;
}

class task1 : public QDialog
{
    Q_OBJECT

public:
    explicit task1(QWidget *parent = nullptr);
    ~task1();

private slots:
    void on_btnClose_clicked();
    void on_plainTextEdit_textChanged();

private:
    Ui::task1 *ui;
    ParseText *parseText;
};

#endif // TASK1_H
