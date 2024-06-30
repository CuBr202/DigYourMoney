// mainwindow.cpp
#include "mainwindow.h"
//#include "titlewindow.h"
#include "gamewindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

int gl[7]={0};//从挖矿界面向主界面传递挖到的矿数量
int speedMultiplier=1;//传递临时加速信号
float xtimer=0;

//构造函数，游戏100ms更新一次
MainWindow::MainWindow(QWidget *parent,PlayerData pld) : QWidget(parent), ui(new Ui::MainWindow),gameTimer(new QTimer(this)),accTimer(new QTimer(this))
{
    pl=pld;
    ui->setupUi(this);
    // Connect the QTimer signal to the updateGameEvents slot


    connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateGameEvents);
    connect(accTimer, &QTimer::timeout, this, &MainWindow::accEnd);

    // Start the timer with a timeout interval of 1000 ms (1 second)
    gameTimer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGameEvents()
{
    xtimer+=1.08;
    //更新playerdata
    pl.handleGameEvents(gl,speedMultiplier);

    //更新左右资源栏UI
    ui->labelNumMoney->setText( "    Total Money     " + Sci(pl.getMoney())+"\n"
                               +"   Income Speed     " + Sci(pl.getSpeed()*speedMultiplier));
    ui->labelNumResources->setText( "Resources\nIron        "+ QString::number(pl.getIron())+"\n"
                                              +"Gold        "+ QString::number(pl.getGold())+"\n"
                                              +"Diamond     "+ QString::number(pl.getDiamond())+"\n"
                                              +"Ruby        "+ QString::number(pl.getRuby())+"\n"

                                   );

    //更新accelerate UI
    if(speedMultiplier==10)
    {
        ui->labelAcc->setText("Acceleration\nTime Left\n\n"+QString::number(float(10.0-xtimer/10),'f',1)+'s');
    }

    if(speedMultiplier==1)
        ui->labelAcc->setText("Acceleration 10x\n\nConsume\n1 ruby");


    //更新Unbreaking UI
    if(pl.getPickUnbreak()==1)
    {
        ui->labelUnbreak->setText("Unbreaking: lv.1\n\nNext level\n1m money\n10 iron\n5 gold");
    }
    else if(pl.getPickUnbreak()==2)
    {
        ui->labelUnbreak->setText("Unbreaking: lv.2\n\nNext level\n100m money\n50 iron\n20 gold\n5 diamond");
    }
    else if(pl.getPickUnbreak()==3)
    {
        ui->labelUnbreak->setText("Unbreaking: lv.3\n\nMax level");
    }


    //更新Speed UI
    if(pl.getPickSpeed()==1)
    {

        ui->labelSpeed->setText("Speed: lv.1\n\nNext level\n1m money\n5 iron\n10 gold");
    }
    else if(pl.getPickSpeed()==2)
    {
        ui->labelSpeed->setText("Speed: lv.2\n\nNext level\n100m money\n5 iron\n10 gold\n20 diamond");
    }
    else if(pl.getPickSpeed()==3)
    {
        ui->labelSpeed->setText("Speed: lv.3\n\nMax level");
    }

}

void MainWindow::on_gambleButton_clicked()
{
    GameWindow *gw=new GameWindow(nullptr,this->pl.getPickUnbreak(),this->pl.getPickSpeed());
    gw->show();
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("demo.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
        QMessageBox::information(this, "Save Failed","Game failed to save!");
        return;
    }
    QTextStream stream(&file);
    stream<<pl.getMoney()<<" "<<pl.getIron()<<" "<<pl.getGold()<<" "<<pl.getDiamond()<<" "<<pl.getRuby()<<" "
           <<pl.getSpeedBase()<<" "<<pl.getSpeedMult()<<" "<<pl.getPickSpeed()<<" "<<pl.getPickUnbreak();
    //关闭文件
    file.close();

    this->close();
}

void MainWindow::on_pushUnsaveButton_clicked()
{
    this->close();
}


void MainWindow::on_mainButton_clicked()
{
    pl.addtoMoney(pl.getSpeed()/5);
}


void MainWindow::on_unbreakButton_clicked()
{
    if(pl.getPickUnbreak()==0&&(pl.getMoney()>10e3&&pl.getIron()>=2))
    {
        pl.addPickUnbreak(1);
        pl.addtoMoney(-10e3);
        pl.addtoIron(-2);
        //ui->labelUnbreak->setText("Unbreaking: lv.1\n\nNext level\n1m money\n10 iron\n5 gold");
    }
    else if(pl.getPickUnbreak()==1&&(pl.getMoney()>10e5&&pl.getIron()>=10&&pl.getGold()>=5))
    {
        pl.addPickUnbreak(1);
        pl.addtoMoney(-10e5);
        pl.addtoIron(-10);
        pl.addtoGold(-5);
        //ui->labelUnbreak->setText("Unbreaking: lv.2\n\nNext level\n100m money\n50 iron\n20 gold\n5 diamond");
    }
    else if(pl.getPickUnbreak()==2&&(pl.getMoney()>10e7&&pl.getIron()>=50&&pl.getGold()>=20&&pl.getDiamond()>=5))
    {
        pl.addPickUnbreak(1);
        pl.addtoMoney(-10e7);
        pl.addtoIron(-50);
        pl.addtoGold(-20);
        pl.addtoDiamond(-5);
        //ui->labelUnbreak->setText("Unbreaking: lv.3\n\nMax level");
    }
    else
    {
        qDebug()<<pl.getPickUnbreak()<<pl.getMoney()<<pl.getIron()<<pl.getGold()<<pl.getDiamond();
        QMessageBox::information(this, "Not Enough!","Your haven't gained enough resources for this upgrade!");
    }
}


void MainWindow::on_speedButton_clicked()
{
    if(pl.getPickSpeed()==0&&(pl.getMoney()>10e3&&pl.getGold()>=2))
    {
        pl.addPickSpeed(1);
        pl.addtoMoney(-10e3);
        pl.addtoGold(-2);
        ui->labelSpeed->setText("Speed: lv.1\n\nNext level\n1m money\n5 iron\n10 gold");
    }
    else if(pl.getPickSpeed()==1&&(pl.getMoney()>10e5&&pl.getGold()>=10&&pl.getIron()>=5))
    {
        pl.addPickSpeed(1);
        pl.addtoMoney(-10e5);
        pl.addtoIron(-5);
        pl.addtoGold(-10);
        ui->labelSpeed->setText("Speed: lv.2\n\nNext level\n100m money\n5 iron\n10 gold\n20 diamond");
    }
    else if(pl.getPickSpeed()==2&&(pl.getMoney()>10e7&&pl.getIron()>=5&&pl.getGold()>=10&&pl.getDiamond()>=20))
    {
        pl.addPickSpeed(1);
        pl.addtoMoney(-10e7);
        pl.addtoIron(-5);
        pl.addtoGold(-10);
        pl.addtoDiamond(-20);
        ui->labelSpeed->setText("Speed: lv.3\n\nMax level");
    }
    else
    {
        qDebug()<<pl.getPickSpeed()<<pl.getMoney()<<pl.getIron()<<pl.getGold()<<pl.getDiamond();
        QMessageBox::information(this, "Not Enough!","Your haven't gained enough resources for this upgrade!");
    }
}


void MainWindow::on_accButton_clicked()
{
    if(pl.getRuby()>0&& !accTimer->isActive())
    {
        xtimer=0;
        speedMultiplier=10;
        accTimer->start(10000);
        pl.addtoRuby(-1);
    }
    else if(accTimer->isActive())
    {
        QMessageBox::information(this, "Accelerating!","You're currently accelerating! Please wait this to end for another acceleration.");
    }
    else
    {
        QMessageBox::information(this, "Not Enough!","Your haven't gained enough ruby for acceleration!");
    }
}

void MainWindow::accEnd()
{
    accTimer->stop();
    speedMultiplier=1;
}


//k m g t p e max:9.223e
QString Sci(long long x)
{
    if(x<1000)
        return QString::number(x);
    char s[7]={' ','k','m','g','t','p','e'};
    double temp=double(x);
    char p;
    for(int i=0;i<=6;i++)
    {
        if(temp>1000)
        {
            temp=temp/1000;
        }
        else
        {
            p=s[i];
            break;
        }
    }
    return QString::number(temp,'f',3)+p;
}



