#ifndef TASK3_H
#define TASK3_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class task3;
}

class task3 : public QDialog
{
    Q_OBJECT

public:
    explicit task3(QWidget *parent = nullptr);
    ~task3();

private slots:
    void on_btnClose_clicked();

private:
    Ui::task3 *ui;
    QStandardItemModel *model;
};

struct HostInfo {
    QString Number;
    QString Hostname;
    QString IPaddress;
    QString MACaddress;
};

const std::vector <HostInfo> LAN_NET_PARK = {
    { "N", "Host name", "IP address", "MAC address" },
    { "1", "Router", "192.168.0.1", "AA:BB:CC:DD:1A:1B" },
    { "2", "Server", "192.168.0.2", "A1:B2:C1:DD:3A:4C" },
    { "3", "Desktop1", "192.168.0.15", "B1:A2:C1:C5:A4:1C" },
    { "4", "Destkop2", "192.168.0.16", "A1:C5:21:C1:BA:C4" },
    { "5", "Desktop3", "192.168.0.17", "B4:A1:2C:C3:A4:22" }
};

#endif // TASK3_H
