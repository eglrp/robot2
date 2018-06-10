#ifndef NETTHREAD_H
#define NETTHREAD_H
#include <QObject>
#include <QThread>
#include <WinSock2.h>
#include <Windows.h>
<<<<<<< HEAD
=======
#include "unique.h"
>>>>>>> newest commit

class NetThread : public QThread
{
    //只要用到信号和槽必须声明为Qobject对象
    Q_OBJECT
public:
    NetThread();
    ~NetThread();

    SOCKET socket;

    //连接函数
    void connectRobot();
    //断开连接
    void disconnectRobot();
    //返回连接状态
    bool isConnected();
    //发送消息
<<<<<<< HEAD
    void sendMessage(char* cmd,int length);
=======
    void sendMessage(structCmd* Cmd);
>>>>>>> newest commit

signals:
    void sig_connected(bool);
    void sig_disconnected();
    void sig_readData();


private:

    //标识连接状态
    bool m_isConnected;
    //数据总长度
    QByteArray totalLength;
    //数据头部
    QByteArray header;
    //数据
    QByteArray data;

protected:
    void run();

};

#endif // NETTHREAD_H
