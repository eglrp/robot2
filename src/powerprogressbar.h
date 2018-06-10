#ifndef POWERPROGRESSBAR_H
#define POWERPROGRESSBAR_H

#include <QThread>
class PowerProgressBarThread:public QThread
{
    Q_OBJECT

public:
    PowerProgressBarThread();
    ~PowerProgressBarThread();

signals:
    //电量改变的信号
    void sig_changePower(float);


public:
    //当前电量的大小
    float powerValue;
    virtual void run();
};

#endif // POWERPROGRESSBAR_H
