/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "mymapview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_connect;
    QAction *action_disconnect;
    QAction *action_online_map_start;
    QAction *action_online_map_stop;
    QAction *action_outline_map_start;
    QAction *action_outline_map_stop;
    QAction *action_online_map_save;
    QAction *action_navigation_start;
    QAction *action_navigation_stop;
    QAction *action_patrol_start;
    QAction *action_patrol_stop;
    QAction *actioncharging_start;
    QAction *actioncharging_stop;
    QAction *action_charging_suspend;
    QAction *action_merging_start;
    QAction *action_merging_stop;
    QAction *action_nomal_subscribe;
    QAction *action_volume_0;
    QAction *action_volume_10;
    QAction *action_volume_20;
    QAction *action_volume_30;
    QAction *action_volume_40;
    QAction *action_volume_50;
    QAction *action_volume_60;
    QAction *action_volume_70;
    QAction *action_volume_80;
    QAction *action_volume_90;
    QAction *action_volume_100;
    QWidget *centralWidget;
    QTableWidget *tableWidget_subscribe;
    QTableWidget *tableWidget_map;
    QTableWidget *tableWidget_charging_pile;
    QTableWidget *tableWidget_navigation_point;
    MyMapView *graphicsView;
    QMenuBar *menu;
    QMenu *menu_robot;
    QMenu *menu_map;
    QMenu *menu_navigation;
    QMenu *menu_patrol;
    QMenu *menu_charging;
    QMenu *menu_voice;
    QMenu *menu_volume_sound;
    QMenu *menu_subscribe;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1423, 977);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        MainWindow->setMouseTracking(true);
        action_connect = new QAction(MainWindow);
        action_connect->setObjectName(QStringLiteral("action_connect"));
        QFont font1;
        action_connect->setFont(font1);
        action_disconnect = new QAction(MainWindow);
        action_disconnect->setObjectName(QStringLiteral("action_disconnect"));
        action_online_map_start = new QAction(MainWindow);
        action_online_map_start->setObjectName(QStringLiteral("action_online_map_start"));
        action_online_map_stop = new QAction(MainWindow);
        action_online_map_stop->setObjectName(QStringLiteral("action_online_map_stop"));
        action_outline_map_start = new QAction(MainWindow);
        action_outline_map_start->setObjectName(QStringLiteral("action_outline_map_start"));
        action_outline_map_stop = new QAction(MainWindow);
        action_outline_map_stop->setObjectName(QStringLiteral("action_outline_map_stop"));
        action_online_map_save = new QAction(MainWindow);
        action_online_map_save->setObjectName(QStringLiteral("action_online_map_save"));
        action_navigation_start = new QAction(MainWindow);
        action_navigation_start->setObjectName(QStringLiteral("action_navigation_start"));
        action_navigation_stop = new QAction(MainWindow);
        action_navigation_stop->setObjectName(QStringLiteral("action_navigation_stop"));
        action_patrol_start = new QAction(MainWindow);
        action_patrol_start->setObjectName(QStringLiteral("action_patrol_start"));
        action_patrol_stop = new QAction(MainWindow);
        action_patrol_stop->setObjectName(QStringLiteral("action_patrol_stop"));
        actioncharging_start = new QAction(MainWindow);
        actioncharging_start->setObjectName(QStringLiteral("actioncharging_start"));
        actioncharging_stop = new QAction(MainWindow);
        actioncharging_stop->setObjectName(QStringLiteral("actioncharging_stop"));
        action_charging_suspend = new QAction(MainWindow);
        action_charging_suspend->setObjectName(QStringLiteral("action_charging_suspend"));
        action_merging_start = new QAction(MainWindow);
        action_merging_start->setObjectName(QStringLiteral("action_merging_start"));
        action_merging_stop = new QAction(MainWindow);
        action_merging_stop->setObjectName(QStringLiteral("action_merging_stop"));
        action_nomal_subscribe = new QAction(MainWindow);
        action_nomal_subscribe->setObjectName(QStringLiteral("action_nomal_subscribe"));
        action_volume_0 = new QAction(MainWindow);
        action_volume_0->setObjectName(QStringLiteral("action_volume_0"));
        action_volume_10 = new QAction(MainWindow);
        action_volume_10->setObjectName(QStringLiteral("action_volume_10"));
        action_volume_20 = new QAction(MainWindow);
        action_volume_20->setObjectName(QStringLiteral("action_volume_20"));
        action_volume_30 = new QAction(MainWindow);
        action_volume_30->setObjectName(QStringLiteral("action_volume_30"));
        action_volume_40 = new QAction(MainWindow);
        action_volume_40->setObjectName(QStringLiteral("action_volume_40"));
        action_volume_50 = new QAction(MainWindow);
        action_volume_50->setObjectName(QStringLiteral("action_volume_50"));
        action_volume_60 = new QAction(MainWindow);
        action_volume_60->setObjectName(QStringLiteral("action_volume_60"));
        action_volume_70 = new QAction(MainWindow);
        action_volume_70->setObjectName(QStringLiteral("action_volume_70"));
        action_volume_80 = new QAction(MainWindow);
        action_volume_80->setObjectName(QStringLiteral("action_volume_80"));
        action_volume_90 = new QAction(MainWindow);
        action_volume_90->setObjectName(QStringLiteral("action_volume_90"));
        action_volume_100 = new QAction(MainWindow);
        action_volume_100->setObjectName(QStringLiteral("action_volume_100"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget_subscribe = new QTableWidget(centralWidget);
        tableWidget_subscribe->setObjectName(QStringLiteral("tableWidget_subscribe"));
        tableWidget_subscribe->setGeometry(QRect(60, 30, 231, 891));
        tableWidget_map = new QTableWidget(centralWidget);
        tableWidget_map->setObjectName(QStringLiteral("tableWidget_map"));
        tableWidget_map->setGeometry(QRect(350, 700, 241, 221));
        tableWidget_charging_pile = new QTableWidget(centralWidget);
        tableWidget_charging_pile->setObjectName(QStringLiteral("tableWidget_charging_pile"));
        tableWidget_charging_pile->setGeometry(QRect(350, 170, 241, 221));
        tableWidget_navigation_point = new QTableWidget(centralWidget);
        tableWidget_navigation_point->setObjectName(QStringLiteral("tableWidget_navigation_point"));
        tableWidget_navigation_point->setGeometry(QRect(350, 430, 241, 221));
        graphicsView = new MyMapView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(680, 280, 256, 192));
        MainWindow->setCentralWidget(centralWidget);
        menu = new QMenuBar(MainWindow);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(0, 0, 1423, 25));
        menu_robot = new QMenu(menu);
        menu_robot->setObjectName(QStringLiteral("menu_robot"));
        menu_map = new QMenu(menu);
        menu_map->setObjectName(QStringLiteral("menu_map"));
        menu_navigation = new QMenu(menu);
        menu_navigation->setObjectName(QStringLiteral("menu_navigation"));
        menu_patrol = new QMenu(menu);
        menu_patrol->setObjectName(QStringLiteral("menu_patrol"));
        menu_charging = new QMenu(menu);
        menu_charging->setObjectName(QStringLiteral("menu_charging"));
        menu_voice = new QMenu(menu);
        menu_voice->setObjectName(QStringLiteral("menu_voice"));
        menu_volume_sound = new QMenu(menu);
        menu_volume_sound->setObjectName(QStringLiteral("menu_volume_sound"));
        menu_subscribe = new QMenu(menu);
        menu_subscribe->setObjectName(QStringLiteral("menu_subscribe"));
        MainWindow->setMenuBar(menu);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menu->addAction(menu_robot->menuAction());
        menu->addAction(menu_map->menuAction());
        menu->addAction(menu_navigation->menuAction());
        menu->addAction(menu_patrol->menuAction());
        menu->addAction(menu_charging->menuAction());
        menu->addAction(menu_voice->menuAction());
        menu->addAction(menu_volume_sound->menuAction());
        menu->addAction(menu_subscribe->menuAction());
        menu_robot->addAction(action_connect);
        menu_robot->addSeparator();
        menu_robot->addAction(action_disconnect);
        menu_map->addAction(action_online_map_start);
        menu_map->addSeparator();
        menu_map->addAction(action_online_map_stop);
        menu_map->addSeparator();
        menu_map->addAction(action_outline_map_start);
        menu_map->addSeparator();
        menu_map->addAction(action_outline_map_stop);
        menu_map->addSeparator();
        menu_map->addAction(action_online_map_save);
        menu_navigation->addAction(action_navigation_start);
        menu_navigation->addSeparator();
        menu_navigation->addAction(action_navigation_stop);
        menu_patrol->addAction(action_patrol_start);
        menu_patrol->addSeparator();
        menu_patrol->addAction(action_patrol_stop);
        menu_charging->addAction(actioncharging_start);
        menu_charging->addSeparator();
        menu_charging->addAction(actioncharging_stop);
        menu_charging->addSeparator();
        menu_charging->addAction(action_charging_suspend);
        menu_voice->addAction(action_merging_start);
        menu_voice->addSeparator();
        menu_voice->addAction(action_merging_stop);
        menu_volume_sound->addAction(action_volume_0);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_10);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_20);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_30);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_40);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_50);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_60);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_70);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_80);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_90);
        menu_volume_sound->addSeparator();
        menu_volume_sound->addAction(action_volume_100);
        menu_subscribe->addAction(action_nomal_subscribe);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\274\230\345\212\233\345\205\213\346\234\272\345\231\250\344\272\272", nullptr));
        action_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        action_disconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", nullptr));
        action_online_map_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\234\250\347\272\277\345\210\266\345\233\276", nullptr));
        action_online_map_stop->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\345\234\250\347\272\277\345\210\266\345\233\276", nullptr));
        action_outline_map_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\246\273\347\272\277\345\210\266\345\233\276", nullptr));
        action_outline_map_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\246\273\347\272\277\345\210\266\345\233\276", nullptr));
        action_online_map_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\234\250\347\272\277\345\210\266\345\233\276", nullptr));
        action_navigation_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\257\274\350\210\252", nullptr));
        action_navigation_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\257\274\350\210\252", nullptr));
        action_patrol_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\267\241\351\200\273", nullptr));
        action_patrol_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\267\241\351\200\273", nullptr));
        actioncharging_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\205\205\347\224\265", nullptr));
        actioncharging_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\205\205\347\224\265", nullptr));
        action_charging_suspend->setText(QApplication::translate("MainWindow", "\347\273\210\346\255\242\345\205\205\347\224\265", nullptr));
        action_merging_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\220\210\346\210\220", nullptr));
        action_merging_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\220\210\346\210\220", nullptr));
        action_nomal_subscribe->setText(QApplication::translate("MainWindow", "\345\270\270\347\224\250\350\256\242\351\230\205", nullptr));
        action_volume_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        action_volume_10->setText(QApplication::translate("MainWindow", "10%", nullptr));
        action_volume_20->setText(QApplication::translate("MainWindow", "20%", nullptr));
        action_volume_30->setText(QApplication::translate("MainWindow", "30%", nullptr));
        action_volume_40->setText(QApplication::translate("MainWindow", "40%", nullptr));
        action_volume_50->setText(QApplication::translate("MainWindow", "50%", nullptr));
        action_volume_60->setText(QApplication::translate("MainWindow", "60%", nullptr));
        action_volume_70->setText(QApplication::translate("MainWindow", "70%", nullptr));
        action_volume_80->setText(QApplication::translate("MainWindow", "80%", nullptr));
        action_volume_90->setText(QApplication::translate("MainWindow", "90%", nullptr));
        action_volume_100->setText(QApplication::translate("MainWindow", "100%", nullptr));
        menu_robot->setTitle(QApplication::translate("MainWindow", "\346\234\272\345\231\250\344\272\272", nullptr));
        menu_map->setTitle(QApplication::translate("MainWindow", "\345\210\266\345\233\276", nullptr));
        menu_navigation->setTitle(QApplication::translate("MainWindow", "\345\257\274\350\210\252", nullptr));
        menu_patrol->setTitle(QApplication::translate("MainWindow", "\345\267\241\351\200\273", nullptr));
        menu_charging->setTitle(QApplication::translate("MainWindow", "\345\205\205\347\224\265", nullptr));
        menu_voice->setTitle(QApplication::translate("MainWindow", "\350\257\255\351\237\263", nullptr));
        menu_volume_sound->setTitle(QApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        menu_subscribe->setTitle(QApplication::translate("MainWindow", "\350\256\242\351\230\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
