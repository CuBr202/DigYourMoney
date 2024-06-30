// gamewindow.h
// 挖宝界面
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QRandomGenerator>
#include <vector>
#include "block.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    int pu,ps;
    explicit GameWindow(QWidget *parent = nullptr,int a=0,int b=0);
    ~GameWindow();

private slots:
    void handleBlockClick();

private:
    QGridLayout *gridLayout;
    std::vector<std::vector<Block*>> blocks;
    std::vector<std::vector<QPushButton*>> buttons;
    int rows;
    int cols;

    void createWorld();
    void updateButton(QPushButton *button, Block *block);
};

#endif // GAMEWINDOW_H
