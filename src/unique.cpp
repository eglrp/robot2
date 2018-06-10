#include "unique.h"
#include <iostream>
#include <QDebug>

using namespace std;



/**
 * @brief Unique::command
 * @param protocal
 * @param number
 * @param jsonStr
=======
#include <QDebug>
using namespace std;



/**
 * @brief Unique::command
 * @param protocal---订阅消息的协议
 * @param number-----消息的容量
 * @param jsonStr----消息的json格式
>>>>>>> newest commit
 * @return
 */
structCmd* Unique::command(int protocal, int number, QString jsonStr){
    char dataHeader[54];
    dataHeader[53] = '\0';
    //将header字符串写入dataheader
    sprintf(dataHeader, "{\"Protocal\":%4d,\"Number\":%8d,\"Length\":%8d}", protocal, number, jsonStr.length());

    char dataLength[sizeof(int)];
    for (int i = 0; i < sizeof(int); i++)
    {
        dataLength[i] = jsonStr.length()+53 >> (sizeof(int) -1 - i) * 8 & 0xff;
    }

    structCmd *Cmd = new structCmd();
    //命令总长度
    Cmd->length = 57+jsonStr.length();
    //命令的内容

    Cmd->cmd = new char[Cmd->length];

    //数据的长度header+data
    memcpy(Cmd->cmd,    dataLength, 4);
    //header
    memcpy(Cmd->cmd+4,  dataHeader, 53);
    //data
    memcpy(Cmd->cmd+57, jsonStr.toStdString().data(), jsonStr.toStdString().length());
    return Cmd;
}



/**
 * @brief Unique::subscribeMessage
 * @param topic-----消息
 * @param topicID---消息的id
 * @param numbers---消息的容量
 * @return 返回--指令
 */

structCmd* Unique::subscribeMessage(std::vector<QString> topic, std::vector<int> topicID, std::vector<int> numbers){

    structCmd *Cmd = new structCmd();

    if(topic.size() != topicID.size() || topicID.size()!=numbers.size())
        return Cmd;

    // 取消订阅
    if(topic.size() == 0)
    {
        QString jsonStr = "";
        jsonStr += "{";
        jsonStr += "\"topic_number\":" + QString("0")     + ",";
        jsonStr += "\"spilt_char\":"   + QString("\",\"") + ",";
        jsonStr += "\"topic\":"        + QString("\"\"")  + ",";
        jsonStr += "\"topicID\":"      + QString("[]")    + ",";
        jsonStr += "\"numbers\":"      + QString("[]")    + "";
        jsonStr += "}";


        return command(SUBSCRIBE, 0, jsonStr);

    }

    //订阅
    QString topicStr = "";
    QString topicIDArray = "[";
    QString numbersArray = "[";
    for(int i=0; i<topic.size(); i++)
    {
        topicStr += topic[i] + ",";
        topicIDArray += QString::number(topicID[i]) + ",";
        numbersArray += QString::number(numbers[i]) + ",";
    }
    topicStr.resize(topicStr.length()-1);
    topicIDArray[topicIDArray.length()-1] = QChar(']');
    numbersArray[numbersArray.length()-1] = QChar(']');

    QString jsonStr = "";
    jsonStr += "{";
    jsonStr += "\"topic_number\":" + QString::number(topic.size())              + ",";//消息的数量
    jsonStr += "\"spilt_char\":"   + QString("\",\"")                           + ",";//消息之间的分隔符
    jsonStr += "\"topic\":"        + QString("\"") + topicStr + QString("\"")   + ",";//消息的名称
    jsonStr += "\"topicID\":"      + topicIDArray                               + ",";//消息的ID
    jsonStr += "\"numbers\":"      + numbersArray                               + ""; //每个消息容器的大小
    jsonStr += "}";


    qDebug()<<jsonStr<<endl;

    //返回完整数据包
    return command(SUBSCRIBE, 0, jsonStr);

}
