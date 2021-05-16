#include "graph.h"
#include"graphkv.h"
#include "ui_graph.h"
int** TMP;
int* RES;
int*** MATRIX;
graph::graph(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::graph)
{
    ui->setupUi(this);
    GraphA=makeGRAPHKV(colVert);
    transf1();
}
void graph:: transf2()
{
    n1 = colVert;
    TMP = new int* [n1];
    RES = new int[n1];
    MATRIX = new int** [n1];
    for (int i = 0; i <= n1; i++)
    {
        TMP[i] = new int[n1];
    }
    for (int i = 0; i < n1; i++)
    {
        MATRIX[i] = new int* [n1];
        for (int j = 0; j < n1; j++)
        {
            if (GraphA.SMatrix[i][j] == 0)
            {
                MATRIX[i][j] = nullptr;
                continue;
            }
            MATRIX[i][j] = new int(GraphA.SMatrix[i][j]);
        }
    }
}
void graph::transf3()
{
    for (int l = 0; l < n1; l++)
        {
            for (int i = 0; i < n1; i++)
            {
                int min = 100000;
                for (int j = 0; j < n1; j++)
                {
                    if (MATRIX[i][j] && min > *MATRIX[i][j])
                    {
                        min = *MATRIX[i][j];
                    }
                }
                for (int j = 0; j < n1; j++)
                {
                    if (MATRIX[i][j])
                    {
                        *MATRIX[i][j] -= min;
                    }
                }
            }
            for (int j = 0; j < n1; j++)
            {
                int min = 100000;
                for (int i = 0; i < n1; i++)
                {
                    if (MATRIX[i][j] && min > *MATRIX[i][j])
                    {
                        min = *MATRIX[i][j];
                    }
                }
                for (int i = 0; i < n1; i++)
                {
                    if (MATRIX[i][j])
                    {
                        *MATRIX[i][j] -= min;
                    }
                }
            }

            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    TMP[i][j] = 0;
                }
            }

            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n1; j++)
                {
                    if (MATRIX[i][j] && !*MATRIX[i][j])
                    {
                        int hmin = 100000;
                        int vmin = 100000;

                        for (int l = 0; l < n1; l++)
                            if (l != i && MATRIX[l][j] && hmin > *MATRIX[l][j])
                            {
                                hmin = *MATRIX[l][j];
                            }
                        for (int l = 0; l < n1; l++)
                        {
                            if (l != j && MATRIX[i][l] && vmin > *MATRIX[i][l])
                            {
                                vmin = *MATRIX[i][l];
                            }
                        }

                        TMP[i][j] = hmin + vmin;
                    }
                }

            int mcost = 0, mi = 0, mj = 0;
            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n1; j++)
                    if (MATRIX[i][j] && mcost < TMP[i][j])
                    {
                        mcost = TMP[i][j];
                        mi = i;
                        mj = j;
                    }
            RES[mi] = mj;

            for (int i = 0; i < n1; i++)
                MATRIX[i][mj] = nullptr;

            for (int i = 0; i < n1; i++)
                MATRIX[mi][i] = nullptr;

            MATRIX[mj][mi] = nullptr;
        }
}
string graph:: transf1()
{
    string S;
    transf2();
    int s = 0;
    transf3();
    cout << "\nSegments of paths: ";
    cout<<endl<<endl;
    for (int i = 0, j = 0; i < n1; i++)
    {
        j = RES[i];
        cout << i + 1 << " -> " << j + 1 << '\t';
        s += GraphA.SMatrix[i][j];
    }
    cout << endl;
    cout << "\nShortest way: ";
    S+="Shortest way: ";
    int temp = 0;
    for (int l = 0; l < n1;)
    {
        for (int i = 0, j = 0; i < n1; i++)
        {
            if (temp == 0 || i + 1 == temp)
            {
                S+=to_string(i + 1);
                if (temp == 0)
                {
                    //S+=to_string(i + 1);
                    cout << i + 1;
                }
                j = RES[i];
                temp = j + 1;
                if (temp > 0)
                {
                    cout << " -> " << temp;
                    S+=" -> ";
                }
                l++;
            }
        }
    }
    S+=to_string(1);
    cout << "\nDistance: " << s;
    S+= "\nDistance: "+to_string(s);
    cout << endl;
    return S;
}
GRAPHKV<int> graph:: makeGRAPHKV(int colVert)
{
    GRAPHKV<int> GRAPHKV;
    int  sourceVertex, targetVertex, edgeWeight;
    for (int i = 1; i <= colVert; ++i)
    {
        int* vertPtr = &i;
        GRAPHKV.PushVert(*vertPtr);
    }
    sourceVertex=1;
    int* sourceVertPtr = &sourceVertex;
    targetVertex=3;
    int* targetVertPtr = &targetVertex;
    edgeWeight=13;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=1;
    sourceVertPtr = &sourceVertex;
    targetVertex=2;
    targetVertPtr = &targetVertex;
    edgeWeight=28;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=1;
    sourceVertPtr = &sourceVertex;
    targetVertex=4;
    targetVertPtr = &targetVertex;
    edgeWeight=15;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=1;
    sourceVertPtr = &sourceVertex;
    targetVertex=6;
    targetVertPtr = &targetVertex;
    edgeWeight=16;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=3;
    sourceVertPtr = &sourceVertex;
    targetVertex=5;
    targetVertPtr = &targetVertex;
    edgeWeight=30;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=5;
    sourceVertPtr = &sourceVertex;
    targetVertex=2;
    targetVertPtr = &targetVertex;
    edgeWeight=21;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=5;
    sourceVertPtr = &sourceVertex;
    targetVertex=4;
    targetVertPtr = &targetVertex;
    edgeWeight=39;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=2;
    sourceVertPtr = &sourceVertex;
    targetVertex=4;
    targetVertPtr = &targetVertex;
    edgeWeight=20;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=4;
    sourceVertPtr = &sourceVertex;
    targetVertex=6;
    targetVertPtr = &targetVertex;
    edgeWeight=31;
    GRAPHKV.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);
    cout << endl;
    return GRAPHKV;
}
graph::~graph()
{
    delete ui;
}
void graph::on_btn1_clicked()
{
    string S =GraphA.ShowMatrix();
    QFont font = ui->res->font();
    font.setPointSize(10);
    ui->res->setFont(font);
    ui->res->setText(QString::fromStdString(S));
    this->update();
}
void graph::on_btn2_clicked()
{
    string S =transf1();
    ui->res2->setText(QString::fromStdString(S));
    this->update();
}
void graph::on_pushButton_clicked()
{
    int  sourceVertex, targetVertex, edgeWeight;
    sourceVertex=ui->initial->text().toInt();
    int* sourceVertPtr = &sourceVertex;
    targetVertex=ui->final_2->text().toInt();
    int* targetVertPtr = &targetVertex;
    if (sourceVertex > colVert || targetVertex > colVert)
    {
        colVert++;
        int* vertPtr = &colVert;
        GraphA.PushVert(*vertPtr);
    }
    edgeWeight=ui->edge->text().toInt();
    GraphA.PushEdg(*sourceVertPtr, *targetVertPtr, edgeWeight);
    this->update();
}
void graph::on_drow_clicked()
{
    scene = new QGraphicsScene();
    point = new MyPoint();
    point->getlen(colVert,GraphA.SMatrix);
    ui->graphicsView->setScene(scene);
    scene->addItem(point);
}


