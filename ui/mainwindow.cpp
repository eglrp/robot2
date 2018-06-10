#include "ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "src/powerprogressbar.h"
#include <QDebug>
#include <iostream>
#include <vector>
#include <src/unique.h>
#include "src/netthread.h"
#include <QMessageBox>

using namespace std;
//设置字符编码
#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //网络请求线程
    netThread=new NetThread();

    //连接状态
    connect(netThread,SIGNAL(sig_connected(bool)),this,SLOT(showConnectStatus(bool)));

    //实例化
    powerThread=new PowerProgressBarThread();
    //电量多少
    connect(powerThread,SIGNAL(sig_changePower(float)),this,SLOT(changePowerValue(float)));
    powerThread->start();


    //初始化窗体
    initTableWidget();


    //连接机器人
    connect(ui->action_connect,SIGNAL(triggered()),this,SLOT(connectRobot_slot()));
    connect(ui->action_disconnect,SIGNAL(triggered()),this,SLOT(disconnectRobot_slot()));


}

MainWindow::~MainWindow()
{
    //终止线程
    powerThread->terminate();
    netThread->disconnectRobot();
    netThread->terminate();
    delete ui;
}

/**
 * 连接
 * @brief MainWindow::connectRobot_slot
 */
void MainWindow::connectRobot_slot(){
    netThread->connectRobot();
}

/**
 * 断开连接
 * @brief MainWindow::disconnectRobot_slot
 */
void MainWindow::disconnectRobot_slot(){

    //断开连接
    netThread->disconnectRobot();

}
/**
 * 初始化窗体信息
 * @brief MainWindow::InitTableWidget
 */
void MainWindow::initTableWidget(){

    //状态栏显示机器人电量
    showPowerValue();

    //状态栏显示网络连接状态
    showConnectLabel();

    subscribeItemText.clear();
    subscribeItemSize.clear();
    subscribeTextProtocal.clear();
    subscribeItems.clear();

    subscribeItemText.push_back("开始在线制图");
    subscribeItems.push_back("MapGenerateOnline");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_GENERATE_ONLINE);

    subscribeItemText.push_back("结束在线制图");
    subscribeItems.push_back("MapFinishOnline");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_FINISH_ONLINE );

    subscribeItemText.push_back("开始离线制图");
    subscribeItems.push_back("MapGenerateOffline");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_GENERATE_OFFLINE);

    subscribeItemText.push_back("结束离线制图");
    subscribeItems.push_back("MapFinishOffline");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_FINISH_OFFLINE);

    subscribeItemText.push_back("地图列表");
    subscribeItems.push_back("MapGetList");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_GET_LIST);

    subscribeItemText.push_back("地图操作");
    subscribeItems.push_back("MapOperation");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_RENAME);

    subscribeItemText.push_back("地图导入");
    subscribeItems.push_back("MapImport");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_IMPORT);

    subscribeItemText.push_back("地图导出");
    subscribeItems.push_back("MapExport");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(MAP_EXPORT);

    subscribeItemText.push_back("开始导航");
    subscribeItems.push_back("NavigateStart");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_START);

    subscribeItemText.push_back("结束导航");
    subscribeItems.push_back("NavigateStop");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_STOP);

    subscribeItemText.push_back("添加导航点");
    subscribeItems.push_back("NavigatePosAdd");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_POS_ADD);

    subscribeItemText.push_back("删除导航点");
    subscribeItems.push_back("NavigatePosDelete");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_POS_DELETE);

    subscribeItemText.push_back("查询导航点");
    subscribeItems.push_back("NavigatePosGet");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_POS_GET);

    subscribeItemText.push_back("清空导航点");
    subscribeItems.push_back("NavigatePosEmpty");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_POS_EMPTY);

    subscribeItemText.push_back("保存导航点");
    subscribeItems.push_back("NavigatePosSave");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(NAVIGATE_POS_SAVE);

    subscribeItemText.push_back("添加充电桩");
    subscribeItems.push_back("ChargingPileAdd");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(CHARGINGPILE_ADD);

    subscribeItemText.push_back("删除充电桩");
    subscribeItems.push_back("ChargingPileDelete");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(CHARGINGPILE_DELETE);

    subscribeItemText.push_back("查询充电桩");
    subscribeItems.push_back("ChargingPileGet");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(CHARGINGPILE_GET);

    subscribeItemText.push_back("巡逻");
    subscribeItems.push_back("Patrol");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(PATROL_START);

    subscribeItemText.push_back("开始自动充电");
    subscribeItems.push_back("ChargingStart");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(CHARGING_START);

    subscribeItemText.push_back("结束自动充电");
    subscribeItems.push_back("ChargingStop");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(CHARGING_STOP);

    subscribeItemText.push_back("机器人定位");
    subscribeItems.push_back("RobotPosition");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_POSITION);

    subscribeItemText.push_back("机器人Odom数据");
    subscribeItems.push_back("RobotOdom");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_ODOM);

    subscribeItemText.push_back("机器人制图数据");
    subscribeItems.push_back("RobotMap");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_MAP);

    subscribeItemText.push_back("机器人激光数据");
    subscribeItems.push_back("RobotLaser");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_LASER);


    subscribeItemText.push_back("机器人全局路径");
    subscribeItems.push_back("RobotGlobalPath");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_GLOBAL_PATH);


    subscribeItemText.push_back("机器人局部路径");
    subscribeItems.push_back("RobotLocalPath");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_LOCAL_PATH);


    subscribeItemText.push_back("机器人电量");
    subscribeItems.push_back("RobotElectricity");
    subscribeItemSize.push_back(1);
    subscribeTextProtocal.push_back(ROBOT_ELECTRICITY);


    ui->tableWidget_subscribe->setColumnCount(1);
    ui->tableWidget_subscribe->setRowCount(subscribeItemText.size());

    QTableWidgetItem *checkBox;
    //QTableWidgetItem *textNumCount;
    checkBox = new QTableWidgetItem("订阅消息");
    checkBox->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    ui->tableWidget_subscribe->setHorizontalHeaderItem(0, checkBox);

    //消息
    for(int i=0; i<subscribeItemText.size(); i++)
    {
        checkBox = new QTableWidgetItem(subscribeItemText[i]);
        //设置单选框的属性
        checkBox->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );
        //设置文字的位置
        checkBox->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        //单选框勾选的状态
        checkBox->setCheckState(Qt::Unchecked);
        ui->tableWidget_subscribe->setItem(i, 0, checkBox);
  }

  connect(ui->tableWidget_subscribe,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(changeSubscribe_slot(QTableWidgetItem*)));


  //获取地图列表
  {
      ui->tableWidget_map->setRowCount(5);
      ui->tableWidget_map->setColumnCount(1);
      QTableWidgetItem *item;
      item = new QTableWidgetItem("地图名称");
      item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
      ui->tableWidget_map->setHorizontalHeaderItem(0, item);


      mapRightMenu.push_back("重命名");
      mapRightMenu.push_back("删除");
      mapRightMenu.push_back("导出");
      mapRightMenu.push_back("导入");
      mapRightMenu.push_back("刷新");

      ui->tableWidget_map->setMouseTracking(true);
      ui->tableWidget_map->setEditTriggers(QAbstractItemView::NoEditTriggers);
      ui->tableWidget_map->setContextMenuPolicy(Qt::CustomContextMenu);

      //信号和槽
      connect(ui->tableWidget_map,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showMenuMap_slot(QPoint)));


  }

  //获取导航点
  {
      ui->tableWidget_navigation_point->setRowCount(5);
      ui->tableWidget_navigation_point->setColumnCount(1);

      QTableWidgetItem *item;
      item = new QTableWidgetItem("导航点");
      item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
      ui->tableWidget_navigation_point->setHorizontalHeaderItem(0, item);

      navigationRightMenu.push_back("添加");
      navigationRightMenu.push_back("删除");
      navigationRightMenu.push_back("清空");
      navigationRightMenu.push_back("保存");
      navigationRightMenu.push_back("刷新");

      ui->tableWidget_navigation_point->setMouseTracking(true);
      ui->tableWidget_navigation_point->setEditTriggers(QAbstractItemView::NoEditTriggers);
      ui->tableWidget_navigation_point->setContextMenuPolicy(Qt::CustomContextMenu);

      connect(ui->tableWidget_navigation_point,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showMenuNavigation_slot(QPoint)));


  }

  //获取充电桩
  {
      ui->tableWidget_charging_pile->setRowCount(5);
      ui->tableWidget_charging_pile->setColumnCount(1);
      QTableWidgetItem *item;
      item = new QTableWidgetItem("充电桩");
      item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
      ui->tableWidget_charging_pile->setHorizontalHeaderItem(0, item);


      chargingPileRMenu.push_back("添加");
      chargingPileRMenu.push_back("删除");
      chargingPileRMenu.push_back("刷新");

      ui->tableWidget_charging_pile->setMouseTracking(true);
      ui->tableWidget_charging_pile->setEditTriggers(QAbstractItemView::NoEditTriggers);
      ui->tableWidget_charging_pile->setContextMenuPolicy(Qt::CustomContextMenu);

      connect(ui->tableWidget_charging_pile,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showMenuChargingPile_slot(QPoint)));




  }



}
/**
 * 订阅消息
 * @brief MainWindow::changeSubscribe_slot
 * @param item
 */
void MainWindow::changeSubscribe_slot(QTableWidgetItem *item){


    //订阅的消息
    std::vector<QString> topic;
    //订阅消息的ID
    std::vector<int> topicID;
    //每个消息容器的大小
    std::vector<int> numbers;


    //当单选框状态改变，将执行此槽函数
    //遍历所有item，如果为选中的状态，将会加入数组中
    for(int i=0; i<subscribeItems.size(); i++)
    {
        if(ui->tableWidget_subscribe->item(i, 0)->checkState() == Qt::CheckState::Checked)
        {
            topic.push_back(subscribeItems[i]);
            topicID.push_back(subscribeTextProtocal[i]);
            //容器的大小都为1
            numbers.push_back(1);
        }
    }

    //标识是否有订阅消息
    bool flag=false;

    if(netThread->isConnected()){

        //当单选框状态改变，将执行此槽函数
        //遍历所有item，如果为选中的状态，将会加入数组中
        for(int i=0; i<subscribeItems.size(); i++)
        {
            if(ui->tableWidget_subscribe->item(i, 0)->checkState() == Qt::CheckState::Checked)
            {
                topic.push_back(subscribeItems[i]);
                topicID.push_back(subscribeTextProtocal[i]);
                //容器的大小都为1
                numbers.push_back(1);
                flag=true;
            }
        }
        if(flag)
            netThread->sendMessage(Unique::subscribeMessage(topic,topicID,numbers));

    }else{
        QMessageBox::warning(NULL,"提示", "请先连接网络！",NULL,NULL);
    }



    qDebug()<<subscribeItems[item->row()];
    qDebug()<<item->row();
}
/**
 * 地图列表
 * 显示右键菜单
 * @brief MainWindow::ShowMenuMap_slot
 * @param pos
 */
void MainWindow::showMenuMap_slot(QPoint pos){
    //设置菜单选项
    QModelIndex index= ui->tableWidget_map->indexAt(pos);
    //菜单
    QMenu *menu = new QMenu(ui->tableWidget_map);
    //绑定数据源
    for(int i=0;i<mapRightMenu.size();i++)
        menu->addAction(mapRightMenu[i]);
    //绑定右键菜单点击信号和槽函数
    connect(menu,SIGNAL(triggered(QAction*)),SLOT(rightClickActionMap(QAction*)));

    //使item不可选
    if(!index.isValid())
    {
        menu->actions()[0]->setEnabled(false);  //重命名
        menu->actions()[1]->setEnabled(false);  //删除
        menu->actions()[2]->setEnabled(false);  //导出
    }

    mapRightMenuIndex = index.row();
    menu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    delete menu;
}

/**
 *
 * @brief MainWindow::RightClickActionMap
 * @param act---右键点击菜单的动作
 */
void MainWindow::rightClickActionMap(QAction *act){
    qDebug()<<act->text();
}

/**
 * 导航列表
 * @brief MainWindow::showMenuNavigation_slot
 * @param pos
 */
void MainWindow::showMenuNavigation_slot(QPoint pos){

    //设置菜单选项
    QModelIndex index= ui->tableWidget_navigation_point->indexAt(pos);
    //菜单
    QMenu *menu = new QMenu(ui->tableWidget_navigation_point);
    //绑定数据源
    for(int i=0;i<navigationRightMenu.size();i++)
        menu->addAction(navigationRightMenu[i]);
    //绑定右键菜单点击信号和槽函数
    connect(menu,SIGNAL(triggered(QAction*)),SLOT(rightClickActionNavigation(QAction*)));

    //使item不可选
    if(!index.isValid())
    {
        menu->actions()[1]->setEnabled(false);  //删除
    }

    navigationRightMenuIndex = index.row();
    menu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    delete menu;
}

/**
 *
 * @brief MainWindow::rightClickActionNavigation
 * @param act
 */
void MainWindow::rightClickActionNavigation(QAction *act){

    qDebug()<<act->text();
}
/**
 * 充电桩
 * @brief MainWindow::showMenuChargingPile_slot
 * @param pos
 */
void MainWindow::showMenuChargingPile_slot(QPoint pos){

    //设置菜单选项
    QModelIndex index= ui->tableWidget_charging_pile->indexAt(pos);
    //菜单
    QMenu *menu = new QMenu(ui->tableWidget_charging_pile);
    //绑定数据源
    for(int i=0;i<chargingPileRMenu.size();i++)
        menu->addAction(chargingPileRMenu[i]);
    //绑定右键菜单点击信号和槽函数
    connect(menu,SIGNAL(triggered(QAction*)),SLOT(rightClickActionCharging(QAction*)));

    //使item不可选
    if(!index.isValid())
    {
        menu->actions()[1]->setEnabled(false);  //删除
    }

    chargingPileRMenuIndex = index.row();
    menu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    delete menu;
}
/**
 * @brief MainWindow::rightClickActionCharging
 * @param act
 */
void MainWindow::rightClickActionCharging(QAction *act){

}
/**
 * 状态栏显示连接状态
 * @brief MainWindow::showConnectStatus
 * @param isConnected---连接状态
 */
void MainWindow::showConnectStatus(bool isConnected){

    if(isConnected){
        statusLabel->setText("已连接");
        statusLabel->setStyleSheet("background-color: skyblue;color:white");

        }
    else{
        statusLabel->setStyleSheet("background-color: skyblue;color:red");
        statusLabel->setText("未连接");
        }
}

/**
 * 显示连接状态
 * @brief MainWindow::showConnectLabel
 */
void MainWindow::showConnectLabel(){

    //标签
    QLabel *statusConnect = new QLabel(this);
    statusConnect->setAlignment(Qt::AlignCenter);
    statusConnect->setText("连接状态：");
    ui->statusBar->addWidget(statusConnect);

    //连接状态标签
    statusLabel=new QLabel();
    statusLabel->setMinimumSize(150, 20); // 设置标签最小大小
    //背景颜色
    statusLabel->setStyleSheet("background-color: skyblue;color:red");
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setFrameShape(QFrame::WinPanel); // 设置标签形状
    statusLabel->setFrameShadow(QFrame::Sunken); //
    //默认未连接
    statusLabel->setText("未连接");
    //添加到状态栏
    ui->statusBar->addWidget(statusLabel);



}
/**
 * 配置进度条信息
 * @brief MainWindow::showPowerValue
 * @param value---电量值
 */
void MainWindow::showPowerValue(){

    //float powerValue=25;
    //qDebug()<<powerValue;
    QLabel *permanent = new QLabel(this);
    permanent->setAlignment(Qt::AlignCenter);
    permanent->setText("机器人电量：");
    ui->statusBar->addPermanentWidget(permanent);
    powerProgress=new QProgressBar(this);
    //进度条的长宽
    powerProgress->setMaximumSize(200,18);
    //最小值
    powerProgress->setMinimum(0);
    //最小值
    powerProgress->setMaximum(100);
    //放在状态栏的右边
    ui->statusBar->addPermanentWidget(powerProgress);
    powerProgress->setStyleSheet("QProgressBar::chunk{background-color: rgb(0, 0, 0);width:10px;margin:1px;} QProgressBar{text-align: center;}");
    powerProgress->setValue(0);

}
/**
 * @brief MainWindow::changePowerValue
 * @param powerValue--当前机器人的电量
 */
void MainWindow::changePowerValue(float powerValue){


    if(powerValue>=0&&powerValue<=20){
        //小于20%进度条将变成红色
        powerProgress->setStyleSheet("QProgressBar::chunk{background-color: rgb(255, 0, 0);width:10px;margin:1px;} QProgressBar{text-align: center;}");
    }else {
        //颜色正常
        powerProgress->setStyleSheet("QProgressBar::chunk{background-color: rgb(0,128,0);width:10px;margin:1px;} QProgressBar{text-align: center;}");

    }
    //设置数值
    powerProgress->setValue(powerValue);
}
