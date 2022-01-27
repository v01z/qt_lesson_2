#ifndef TASK2_H
#define TASK2_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class task2;
}

class task2 : public QDialog
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    ~task2();

private slots:
    void on_btnClose_clicked();

    void on_btnChangeTxt_clicked();

    void on_btnUp_clicked();

    void on_btnDown_clicked();

    void on_btnAdd_clicked();

    void on_btnDel_clicked();

    void on_cbxViewModeSwitcher_clicked();

private:
    Ui::task2 *ui;
    QStandardItemModel *model;

};

#endif // TASK2_H
