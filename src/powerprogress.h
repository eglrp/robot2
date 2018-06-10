#ifndef POWERPROGRESS_H
#define POWERPROGRESS_H
#include <QThread>

class PowerProgress : public QThread
{
    Q_OBJECT
public:
    PowerProgress();
    ~PowerProgress();

signals:
    void sig_powerChange();

private:
    //当前的电量
    int powerValue;
    void run();
};

#endif // POWERPROGRESS_H
