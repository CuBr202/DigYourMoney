// titlewindow.cpp
#include "titlewindow.h"
#include "mainwindow.h"
#include "ui_titlewindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


TitleWindow::TitleWindow(QWidget *parent) : QWidget(parent), ui(new Ui::TitleWindow)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    //setFixedSize(256,192);
    ui->setupUi(this);
}

TitleWindow::~TitleWindow()
{
    delete ui;
}

void TitleWindow::on_startButton_clicked()
{
    MainWindow *mw=new MainWindow;
    mw->show();
    this->close();

}

void TitleWindow::on_continueButton_clicked()
{
    //接收stream容器
    long long a,f;
    int b,c,d,e,h,i;
    double g;

    //读取文件
    QFile file("demo.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
        QMessageBox::information(this, "Open Failed","Save failed to open!");
    }
    PlayerData pl;
    QTextStream stream(&file);
    stream>>a>>b>>c>>d>>e>>f>>g>>h>>i;

    qDebug()<<a<<b<<c<<d<<e<<f<<g<<h<<i;
    //载入数据
    pl.addtoMoney(a);
    pl.addtoIron(b);
    pl.addtoGold(c);
    pl.addtoDiamond(d);
    pl.addtoRuby(e);
    pl.setSpeedBase(f);
    pl.setSpeedMult(g);
    pl.addPickSpeed(h);
    pl.addPickUnbreak(i);
    file.close();
    MainWindow *mw=new MainWindow(nullptr,pl);
    mw->show();
    this->close();
}


void TitleWindow::on_exitButton_clicked()
{
    this->close();
}




void TitleWindow::on_authorButton_clicked()
{
    QMessageBox::information(this, "About", "欢迎来到Dig Your Money!\n"
                                            "这是一个轻松简单的放置游戏\n"
                                            "详细游戏规则与方法见readme.md\n\n"
                                            "作者：CuBr202\n"
                                            "github: https://github.com/CuBr202/DigYourMoney");
}

