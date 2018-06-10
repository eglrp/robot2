#ifndef MYMAPVIEW_H
#define MYMAPVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QList>

class MyMapView : public QGraphicsView
{
    Q_OBJECT
public:
    MyMapView(QWidget *parent=0);



private:

    const int m_radius = 5;
    const int mapZValue = 0;
    const int navigatePosZValue = 1;
    const int ChargingPileZValue = 2;
    const int PathZValue = 3;
    const int RobotZValue = 10;
};

#endif // MYMAPVIEW_H
