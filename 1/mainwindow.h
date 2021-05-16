#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deg.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //void prob();
    void on_CulcRes_clicked();
    void on_btn_cos_clicked();
    QString CulcRes();
    void on_btn_sin_clicked();
    void on_btn_tg_clicked();
    void on_btn_ctg_clicked();
    void on_Sign1_toggled(bool checked);
    void on_Sign2_toggled(bool checked);
    void on_btn_arccos_clicked();
    void on_btn_arcsin_clicked();
    void on_btn_arctg_clicked();
    void on_btn_arcctg_clicked();
    void on_clear_clicked();
private:
    Ui::MainWindow *ui;
    QString TypeOper;
    deg Res;
    deg A;
    deg B;
    int flag;
};
#endif // MAINWINDOW_H
