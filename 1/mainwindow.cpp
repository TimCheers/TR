#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    ui->deg1->setValidator (new QDoubleValidator (this));
    ui->min1->setValidator (new QDoubleValidator (this));
    ui->sec1->setValidator (new QDoubleValidator (this));
    ui->deg2->setValidator (new QDoubleValidator (this));
    ui->min2->setValidator (new QDoubleValidator (this));
    ui->sec2->setValidator (new QDoubleValidator (this));
    flag=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_clear_clicked()
{
    if(flag==2)
    {
        ui->Result->setText("");
        flag--;
    }
    if(flag==1)
    {
        ui->deg1->clear();
        ui->min1->clear();
        ui->sec1->clear();
        ui->deg2->clear();
        ui->min2->clear();
        ui->sec2->clear();
        ui->Sign1->setChecked(0);
        ui->Sign2->setChecked(0);
        flag++;
    }

}
QString MainWindow::CulcRes()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    QString S="Error!";
    TypeOper=(ui->TypeOp->currentText());
    if(TypeOper=="addition")
    {
        Res=A+B;
        if(B.get_Numb()>=0)
        {
            S =QString::number(A.get_Numb())+"° + "+QString::number(B.get_Numb())+"°";
        }
        else
        {
            S =QString::number(A.get_Numb())+"° + ("+QString::number(B.get_Numb())+")°";
        }
    }
    if (TypeOper=="subtraction")
    {
        Res=A-B;
        if(B.get_Numb()>=0)
        {
            S =QString::number(A.get_Numb())+"° - "+QString::number(B.get_Numb())+"°";
        }
        else
        {
            S =QString::number(A.get_Numb())+"° - ("+QString::number(B.get_Numb())+")°";
        }
    }
    if(TypeOper=="division")
    {
        Res=A/B;
        if(B.get_Numb()>=0)
        {
            S =QString::number(A.get_Numb())+"° / "+QString::number(B.get_Numb())+"°";
        }
        else
        {
            S =QString::number(A.get_Numb())+"° / ("+QString::number(B.get_Numb())+")°";
        }
    }
    if(TypeOper=="multiplication")
    {
        Res=A*B;
        if(B.get_Numb()>=0)
        {
            S =QString::number(A.get_Numb())+"° * "+QString::number(B.get_Numb())+"°";
        }
        else
        {
            S =QString::number(A.get_Numb())+"° * ("+QString::number(B.get_Numb())+")°";
        }
    }
    return S;
}
void MainWindow::on_CulcRes_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    TypeOper=(ui->TypeOp->currentText());
    if(TypeOper=="addition")
    {
        Res=A+B;
        QString S;
        if(B.get_Numb()>=0)
        {
            S =QString::number(A.get_Numb())+"° + "+QString::number(B.get_Numb())+"° = " +QString::number(Res.get_Numb())+"°";
        }
        else
        {
            S =QString::number(A.get_Numb())+"° + ("+QString::number(B.get_Numb())+")° = " +QString::number(Res.get_Numb())+"°";
        }
        ui->Result->setText(S);
    }
    if (TypeOper=="subtraction")
    {
         Res=A-B;
         QString S;
         if(B.get_Numb()>=0)
         {
             S =QString::number(A.get_Numb())+"° - "+QString::number(B.get_Numb())+"° = " +QString::number(Res.get_Numb())+"°";
         }
         else
         {
             S =QString::number(A.get_Numb())+"° - ("+QString::number(B.get_Numb())+")° = " +QString::number(Res.get_Numb())+"°";
         }
         ui->Result->setText(S);
    }
    if(TypeOper=="division")
    {
        Res=A/B;
        QString S="Error!";
        if(B.get_Numb()!=0)
        {
            if(B.get_Numb()>0)
            {
                S =QString::number(A.get_Numb())+"° / "+QString::number(B.get_Numb())+"° = " +QString::number(Res.get_Numb())+"°";
            }
            else
            {
                S =QString::number(A.get_Numb())+"° / ("+QString::number(B.get_Numb())+")° = " +QString::number(Res.get_Numb())+"°";
            }
            ui->Result->setText(S);
        }
        else
        {
            ui->Result->setText(S);
        }

    }
    if(TypeOper=="multiplication")
    {
        Res=A*B;
        QString S;
        if(B.get_Numb()>=0)
        {
            S =QString::number(A.get_Numb())+"° * "+QString::number(B.get_Numb())+"° = " +QString::number(Res.get_Numb())+"°";
        }
        else
        {
            S =QString::number(A.get_Numb())+"° * ("+QString::number(B.get_Numb())+")° = " +QString::number(Res.get_Numb())+"°";
        }
        ui->Result->setText(S);
    }
}

void MainWindow::on_btn_cos_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="cos(" +CulcRes()+") = "+ QString::number(Res.get_cos());
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="cos(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_cos());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="cos(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_cos());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="cos(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_cos());
        ui->Result->setText(S);
    }
}

void MainWindow::on_btn_sin_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="sin(" +CulcRes()+") = "+ QString::number(Res.get_sin());
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="sin(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_sin());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="sin(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_sin());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="sin(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_sin());
        ui->Result->setText(S);
    }
}

void MainWindow::on_btn_tg_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="tg(" +CulcRes()+") = "+ QString::number(Res.get_tg());
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="tg(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_tg());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="tg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_tg());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="tg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_tg());
        ui->Result->setText(S);
    }
}

void MainWindow::on_btn_ctg_clicked()
{
    CulcRes();
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="ctg(" +CulcRes()+") = "+ QString::number(Res.get_ctg());
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="ctg(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_ctg());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="ctg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_ctg());
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="ctg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_ctg());
        ui->Result->setText(S);
    }
}

void MainWindow::on_Sign1_toggled(bool checked)
{
    if(checked==1)
    {
        QString CH=ui->deg1->text();
        ui->deg1->setText("-"+CH);
        CH=ui->min1->text();
        ui->min1->setText("-"+CH);
        CH=ui->sec1->text();
        ui->sec1->setText("-"+CH);
    }
    else
    {
        QString CH=ui->deg1->text();
        CH.remove(0,1);
        ui->deg1->setText(CH);

        CH=ui->min1->text();
        CH.remove(0,1);
        ui->min1->setText(CH);

        CH=ui->sec1->text();
        CH.remove(0,1);
        ui->sec1->setText(CH);
    }

}
void MainWindow::on_Sign2_toggled(bool checked)
{
    if(checked==1)
    {
        QString CH=ui->deg2->text();
        ui->deg2->setText("-"+CH);
        CH=ui->min2->text();
        ui->min2->setText("-"+CH);
        CH=ui->sec2->text();
        ui->sec2->setText("-"+CH);
    }
    else
    {
        QString CH=ui->deg2->text();
        CH.remove(0,1);
        ui->deg2->setText(CH);

        CH=ui->min2->text();
        CH.remove(0,1);
        ui->min2->setText(CH);

        CH=ui->sec2->text();
        CH.remove(0,1);
        ui->sec2->setText(CH);
    }
}
void MainWindow::on_btn_arccos_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="arccos(" +CulcRes()+") = "+ QString::number(Res.get_arccos())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="arccos(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_arccos())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="arccos(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arccos())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="arccos(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arccos())+"°";
        ui->Result->setText(S);
    }
}
void MainWindow::on_btn_arcsin_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="arcsin(" +CulcRes()+") = "+ QString::number(Res.get_arcsin())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="arcsin(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_arcsin())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="arcsin(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arcsin())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="arcsin(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arcsin())+"°";
        ui->Result->setText(S);
    }
}
void MainWindow::on_btn_arctg_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="arctg(" +CulcRes()+") = "+ QString::number(Res.get_arctg())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="arctg(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_arctg())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="arctg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arctg())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="arctg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arctg())+"°";
        ui->Result->setText(S);
    }
}
void MainWindow::on_btn_arcctg_clicked()
{
    deg A(ui->deg1->text().toFloat(),ui->min1->text().toFloat(),ui->sec1->text().toFloat());
    deg B(ui->deg2->text().toFloat(),ui->min2->text().toFloat(),ui->sec2->text().toFloat());
    if(A.get_Numb()!=0 && B.get_Numb()!=0)
    {
        QString S ="arcctg(" +CulcRes()+") = "+ QString::number(Res.get_arcctg())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()!=0&&B.get_Numb()==0)
    {
        QString S ="arcctg(" +QString::number(A.get_Numb())+") = "+ QString::number(A.get_arcctg())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()!=0)
    {
        QString S ="arcctg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arcctg())+"°";
        ui->Result->setText(S);
    }
    if(A.get_Numb()==0&&B.get_Numb()==0)
    {
        QString S ="arcctg(" +QString::number(B.get_Numb())+") = "+ QString::number(B.get_arcctg())+"°";
        ui->Result->setText(S);
    }
}

