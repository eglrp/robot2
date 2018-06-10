#include "netthread.h"
#include <iostream>
#include <QDebug>
#include <QMessageBox>
using namespace std;
//使用Windows网络编程
#pragma comment(lib,"ws2_32.lib")
#pragma execution_character_set("utf-8")

NetThread::NetThread()
{
    m_isConnected=false;

}

NetThread::~NetThread(){
    disconnectRobot();
}

/**
 * 连接函数
 * @brief NetThread::connectRobot
 */
void NetThread::connectRobot(){

    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
        cout<<"WSAStartup failed"<<endl;
        return ;
    }

    socket=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(socket==INVALID_SOCKET){
        cout<<"socket failed!"<<endl;
        return ;
    }

    SOCKADDR_IN addrSer;
    addrSer.sin_family=AF_INET;
    addrSer.sin_port=htons(8000);
    addrSer.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    int ret=::connect(socket,(SOCKADDR*)&addrSer,sizeof(SOCKADDR));

    if(ret==SOCKET_ERROR){
        cout<<"socket connect failed"<<endl;

        //提示框----连接不成功时提示检查网络连接
        QMessageBox::warning(NULL,"提示", "连接错误，请检查网络连接！",NULL,NULL);
        WSACleanup();
        closesocket(socket);
        return ;
    }

    m_isConnected=true;
    emit sig_connected(m_isConnected);
    return ;


}

/**
 * 断开连接
 * @brief NetThread::disconnectRobot
 */
void NetThread::disconnectRobot(){

    WSACleanup();
    closesocket(socket);
    m_isConnected=false;
    emit sig_connected(m_isConnected);
    cout<<"disconnect"<<endl;
}
/**
 * @brief NetThread::isConnected
 * @return---返回网络连接状态
 */
bool NetThread::isConnected(){
    return m_isConnected;
}

/**
 * 发送函数
 * @brief NetThread::sendMessage
 * @param cmd------待发送的数据
 * @param length---数据长度
 */



void NetThread::sendMessage(structCmd* Cmd){

    char* m_cmd = Cmd->cmd;
    int length = Cmd->length;

    for(int i=0;i<length;i++)
        cout<<m_cmd[i];
    cout<<endl;

    if(isConnected()){

        for(int i=0; i<length/512+1; i++)
        {
            int ml = 0;
            if((length - i*512) / 512 > 0)
                ml = 512;
            else
                ml = length % 512;
            int ret = send(socket, m_cmd+i*512, ml, 0);
            if(ret == SOCKET_ERROR)
            {
                qDebug() << "Send Cmd error";
                return;
            }
            else if( ret == 0 )
            {
                 m_isConnected= false;
                emit sig_disconnected();
                return;
            }
        }

    }
}

void NetThread::run(){

}
