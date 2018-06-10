#include "ui/mainwindow.h"
#include <QApplication>
#include <QDebug>


/* 确定电脑是大端字节序还是小端字节序 */
int check()
{
    int i = 1;				//1在内存中的表示： 0x00000001
    char *pi = (char *)&i;	//将int型的地址强制转换为char型
    return *pi == 0;		//如果读取到的第一个字节为1，则为小端法，为0，则为大端法
}


int main(int argc, char *argv[])
{

    if(check()==1)
        qDebug()<<"big";
    else {
        qDebug()<<"little";
    }


    QApplication a(argc, argv);
    MainWindow w;
    //默认最大化
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
