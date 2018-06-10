#include "src/powerprogressbar.h"

PowerProgressBarThread::PowerProgressBarThread()
{
    //初始值
    powerValue=0;
}
PowerProgressBarThread::~PowerProgressBarThread(){
    powerValue=0;
}

void PowerProgressBarThread::run() {

    while (1) {
        if(powerValue<=100){

            powerValue+=5;
            msleep(1000);
            emit sig_changePower(powerValue);
        }
    }

}
