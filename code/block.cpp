// block.cpp
#include "block.h"

Block::Block(const QString &name, int breakCount, int tr, int tl)
    : name(name), breakCount(breakCount), currentBreakCount(0), treasureType(tr), treasureLevel(tl){}

int Block::getBreakCount() const{return breakCount;}

int Block::getLeftCount() const {return breakCount-currentBreakCount;}

QString Block::getName() const  {return name;}

bool Block::isDestroyed() const {return currentBreakCount >= breakCount;}

int Block::getType() const  {return treasureType;}
int Block::getLevel() const {return treasureLevel;}

void Block::breakBlock(int x) {
    if (currentBreakCount < breakCount) {
        currentBreakCount+=x;
    }
}
