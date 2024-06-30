// gamewindow.cpp
#include "gamewindow.h"
#include <QMessageBox>

const int pickBase=120;//pickaxe基础耐久
int pickCounter=0;
extern int gl[7];

GameWindow::GameWindow(QWidget *parent,int a,int b) :
    QWidget(parent),
    pu(a),
    ps(b),
    rows(8),  // 设置行数
    cols(12)   // 设置列数

{
    gridLayout = new QGridLayout(this);

    createWorld();

    setLayout(gridLayout);

    setFixedSize(512,384);

}

GameWindow::~GameWindow() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete blocks[i][j];
        }
    }
}

void GameWindow::createWorld() {
    for (int i = 0; i < rows; ++i) {
        std::vector<Block*> blockRow;
        std::vector<QPushButton*> buttonRow;
        for (int j = 0; j < cols; ++j) {
            Block *block;
            int p=QRandomGenerator::global()->bounded(5);//blocktype
            int a=QRandomGenerator::global()->bounded(99);//treasuretype
            int b=QRandomGenerator::global()->bounded(99);//treasurelevel
            int m,n;//type,level: empty,iron,gold,diamond,sapphire,ruby,emerald
            if (p >= 3)
            {
                if(a<80)        m=0;
                else if(a<90)   m=1;
                else if(a<95)   m=2;
                else if(a<97)   m=3;
                else if(a<98)   m=4;
                else if(a<99)   m=5;
                else            m=6;

                if(m==1)        n=1+(b+1)/50;
                else            n=1;

                block = new Block("Dirt", 12, m, n);
            }
            else if(p==1 || p==2)
            {
                if(a<50)        m=0;
                else if(a<70)   m=1;
                else if(a<80)   m=2;
                else if(a<88)   m=3;
                else if(a<92)   m=4;
                else if(a<96)   m=5;
                else            m=6;

                if(m==1)        n=1+(b+1)/25;
                else if(m==2)   n=1+(b+1)/50;
                else            n=1;

                block = new Block("Stone", 36, m ,n);
            }
            else
            {
                if(a<10)        m=0;
                else if(a<40)   m=1;
                else if(a<60)   m=2;
                else if(a<70)   m=3;
                else if(a<80)   m=4;
                else if(a<90)   m=5;
                else            m=6;

                if(m==1)        n=1+(b+1)/10;
                else if(m==2)   n=1+(b+1)/20;
                else if(m==3)   n=1+(b+1)/33;
                else            n=1;

                block = new Block("Bedrock", 144, m ,n);
            }
            blockRow.push_back(block);

            QPushButton *button = new QPushButton(this);
            button->setFixedSize(50, 50);
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, this, &GameWindow::handleBlockClick);
            buttonRow.push_back(button);

            updateButton(button, block);
        }
        blocks.push_back(blockRow);
        buttons.push_back(buttonRow);
    }
}

void GameWindow::handleBlockClick() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QString s[7]={"","iron","gold","diamond","sapphire","ruby","emerald"};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (buttons[i][j] == button) {
                Block *block = blocks[i][j];
                block->breakBlock(ps+1);
                pickCounter+=4-pu;
                if(pickCounter>pickBase)
                {
                    QMessageBox::information(this, "Pickaxe broken!","Your pickaxe has broken!");
                    gl[0]=114514;
                    pickCounter=0;
                    this->close();
                    return;
                }
                updateButton(button, block);
                if (block->isDestroyed()&&block->getType()!=0) {
                    QMessageBox::information(this, "Treasure Found!",
                    "You Found "+QString::number(block->getLevel())+" "+s[block->getType()]+" in "+block->getName());
                    gl[block->getType()]+=block->getLevel();
                }
                return;
            }
        }
    }
}

void GameWindow::updateButton(QPushButton *button, Block *block) {
    if (block->isDestroyed()) {
        button->setText("X");
        button->setEnabled(false);
    } else {
        button->setText(block->getName() + "\n" + QString::number(block->getLeftCount()));
    }
}
