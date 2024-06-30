// main.cpp
//放置类挖宝游戏主程序
//#include "mainwindow.h"
#include "titlewindow.h"
//#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TitleWindow titleWindow;

    titleWindow.show();

    return a.exec();
}
