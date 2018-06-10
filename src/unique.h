#pragma once

#include <QString>
#include <QPointF>
#include <vector>

//协议
enum Protocal {

    SUBSCRIBE                   = 0,        //订阅

    MAP_GENERATE_ONLINE         = 16,       //开始在线制图
    MAP_GENERATE_OFFLINE        = 17,       //开始离线制图
    MAP_FINISH_ONLINE           = 18,       //结束在线制图
    MAP_FINISH_OFFLINE          = 45,       //结束离线制图
    MAP_SAVE_ONLINE             = 19,       //保存在线制图
    MAP_GET_LIST                = 20,       //获取地图列表
    MAP_DELETE                  = 21,       //删除指定地图
    MAP_RENAME                  = 21,       //重命名指定地图
    MAP_IMPORT                  = 22,       //导入地图
    MAP_EXPORT                  = 23,       //导出地图

    CONTROL_MOVING              = 26,       //运动控制

    NAVIGATE_START              = 24,       //导航开始
    NAVIGATE_STOP               = 25,       //导航结束
    NAVIGATE_POS_ADD            = 27,       //添加导航点
    NAVIGATE_POS_DELETE         = 28,       //删除导航点
    NAVIGATE_POS_GET            = 29,       //查询导航点
    NAVIGATE_POS_EMPTY          = 30,       //清空导航点
    NAVIGATE_POS_SAVE           = 31,       //保存导航点

    CHARGINGPILE_ADD            = 32,       //充电桩添加
    CHARGINGPILE_DELETE         = 33,       //充电桩删除
    CHARGINGPILE_EDIT           = 34,       //充电桩编辑
    CHARGINGPILE_GET            = 35,       //充电桩查询

    PATROL_START                = 36,       //开始巡逻
    PATROL_STOP                 = 36,       //结束巡逻

    CHARGING_START              = 37,       //开始自动充电
    CHARGING_STOP               = 38,       //结束自动充电

    TTS_PLAY                    = 39,       //语音开始合成
    TTS_STOP                    = 40,       //语音结束合成
    TTS_VOLUME                  = 41,       //语音音量

    ROBOT_POSITION              = 128,      //机器人定位
    ROBOT_ODOM                  = 129,      //Odom数据
    ROBOT_MAP                   = 130,      //机器人制图
    ROBOT_LASER                 = 131,      //机器人激光数据
    ROBOT_GLOBAL_PATH           = 132,      //全局路径
    ROBOT_LOCAL_PATH            = 133,      //局部路径
    ROBOT_ELECTRICITY           = 134,      //电量

    OPERATION_FEEDBACK          = 135       //操作反馈
};

struct structCmd
{
    //命令的内容
    char* cmd;
    //命令长度
    int length;
<<<<<<< HEAD
=======

>>>>>>> newest commit
    structCmd() {cmd=NULL;length=0;}
    ~structCmd(){delete cmd;}
};


namespace Unique {


    /**
     * @brief command
     * @param protocal---协议
     * @param number-----容量
     * @param jsonStr----数据内容
     * @return 指令
     */
    structCmd* command(int protocal,int number,QString jsonStr="");

    /**
     * 订阅消息的指令
     * @brief subscribeMessage
     * @param topic----所订阅的消息
     * @param topicID--消息的ID
     * @param numbers--消息的容器的大小
     * @return---返回生成的数据包
     */
    structCmd* subscribeMessage(std::vector<QString> topic,std::vector<int> topicID,std::vector<int> numbers);
}
