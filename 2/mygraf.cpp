#include "mygraf.h"
#include"graph.h"
MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    front=QBrush(QColor(127,255,212));
    back=QBrush(QColor(200,200,200));
    textPen=QPen(QColor(33,33,33));
    glFont.setPixelSize(20);
}
MyPoint::~MyPoint()
{

}
QRectF MyPoint::boundingRect() const
{
    return QRectF(0,0,100,100);
}
using namespace std;
void MyPoint::getlen(int len1, int mat1[20][20])
{
    this->len=len1;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            matrix[i][j]=mat1[i][j];
        }
    }
}
int R=250;
int r=30;
double pi=3.1415;
int HeightText=30;
int xa=20;
int ya=10;
double angle=pi/8;
int ls=14;
int disp=80;
void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(front);
    painter->setPen(textPen);
    painter->setFont(glFont);
    textPen.setWidth(4);
    int tmpMass[20][20]={0};
    for (int i=0;i<len;i++)
    {
        double a=pi*3/2+pi*2/len*i;
        int xc=cos(a)*R+xa;
        int yc=sin(a)*R+ya;
        int c1=xc-20;
        int c2=yc-HeightText/2;
        int c3=40;
        int c4=HeightText;
        QString text; text.setNum(i+1);
        painter->drawEllipse(QRectF(xc-r,yc-r,2*r,2*r));
        painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
        for (int k=0;k<len;k++)
        {
            if (matrix[i][k]!=0)
            {
                double a2=pi*3/2+pi*2/len*k;
                double xc2=cos(a2)*R+xa;
                double yc2=sin(a2)*R+ya;
                double l=sqrt((xc2-xc)*(xc2-xc)+(yc2-yc)*(yc2-yc));
                int xl1=(xc2-xc)/l*r+xc;
                int yl1=(yc2-yc)/l*r+yc;
                int xl2=xc2-(xc2-xc)/l*r;
                int yl2=yc2-(yc2-yc)/l*r;
                painter->drawLine(xl1,yl1,xl2,yl2);
                double b;
                if      (xc2==xl2 && yl2<yc2) b=pi*3/2;
                else if (yc2==yl2 && xl2<xc2) b=pi;
                else if (xc2==xl2 && yl2>yc2) b=pi/2;
                else if (yc2==yl2 && xl2>xc2) b=0;
                else if (xl2>xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi*2;
                else if (xl2<xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                else if (xl2<xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                else if (xl2>xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2));
                int xs1=cos(b+angle)*ls+xl2;
                int ys1=sin(b+angle)*ls+yl2;
                int xs2=cos(b-angle)*ls+xl2;
                int ys2=sin(b-angle)*ls+yl2;
                painter->drawLine(xl2,yl2,xs1,ys1);
                painter->drawLine(xl2,yl2,xs2,ys2);
                if(tmpMass[i][k]!=1)
                {
                    c1=(xl2+xl1)/2-20+qrand()%disp-disp/2;
                    c2=(yl2+yl1)/2-HeightText/2+qrand()%disp-disp/2;
                    c3=40;
                    c4=HeightText;
                    text.setNum(matrix[i][k]);
                    painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
                    tmpMass[k][i]=1;
                }
            }
        }
    }
}
