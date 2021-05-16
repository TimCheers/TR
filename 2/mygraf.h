#ifndef MYGRAF_H
#define MYGRAF_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class MyPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyPoint(QObject *parent = 0);
    ~MyPoint();
     void myPainter();
public:
    void draw(QPainter *painter, QPaintEvent *event);
    QBrush front;
    void getlen(int len1, int mat1[20][20]);
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QBrush back;
    QFont glFont;
    QPen textPen;
    int len;
    int matrix[20][20];
};


#endif // MYGRAPHICVIEW_H
