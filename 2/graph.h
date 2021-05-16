#ifndef GRAPH_H
#define GRAPH_H
#include <QMainWindow>
#include <mygraf.h>
#include <QGraphicsScene>
#include <string>
#include"graphkv.h"

QT_BEGIN_NAMESPACE
namespace Ui { class graph; }
QT_END_NAMESPACE

class graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    ~graph();
    int colVert=6;
    int n1;
private slots:
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_pushButton_clicked();
    void on_drow_clicked();
private:
    Ui::graph *ui;
    QGraphicsScene  *scene;
    MyPoint         *point;
    GRAPHKV<int> makeGRAPHKV(int colVert);
    void transf3();
    void transf2();
    string transf1();
    GRAPHKV<int> GraphA;

    //GRAPHKV  GraphA;

};

#endif // MAINWINDOW_H
