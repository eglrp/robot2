#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <src/powerprogressbar.h>
#include <QTableWidgetItem>
#include "src/netthread.h"


namespace Ui {
class MainWindow;
class QLabel;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void connectRobot_slot();
    void disconnectRobot_slot();

    //订阅状态
    void showConnectStatus(bool isConnected);
    //电量改变
    void changePowerValue(float powerValue);

    //订阅状态
    void changeSubscribe_slot(QTableWidgetItem*item);

    //地图列表
    void showMenuMap_slot(QPoint pos);
    void rightClickActionMap(QAction* act);

    //导航点
    void showMenuNavigation_slot(QPoint pos);
    void rightClickActionNavigation(QAction* act);

    //充电桩
    void showMenuChargingPile_slot(QPoint pos);
    void rightClickActionCharging(QAction *act);

private:
    void showConnectLabel();
    void showPowerValue();
    void initTableWidget();

private:
    NetThread* netThread;

    //连接状态标签
    QLabel * statusLabel;
    //电量进度条
    QProgressBar* powerProgress;
    //进度条线程
    PowerProgressBarThread* powerThread;

    //订阅消息的代号--MapGenerateOnline
    std::vector<QString> subscribeItems;
    //订阅消息的名称--开始在线制图
    std::vector<QString> subscribeItemText;
    //订阅消息的协议号--
    std::vector<int> subscribeTextProtocal;
    //订阅消息容器的大小--默认为1
    std::vector<int> subscribeItemSize;

    //地图
    std::vector<QString> mapList;
    std::vector<QString> mapRightMenu;
    int mapRightMenuIndex;

    //导航点
    std::vector<QString> navigationList;
    std::vector<QString> navigationRightMenu;
    int navigationRightMenuIndex;

    //充电桩
    std::vector<QString> chargingPileList;
    std::vector<QString> chargingPileRMenu;
    int chargingPileRMenuIndex;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
