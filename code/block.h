// block.h
// 方块属性
#ifndef BLOCK_H
#define BLOCK_H

#include <QString>

class Block {
public:
    Block(const QString &name, int breakCount, int tr, int tl);
    virtual ~Block() = default;

    int getBreakCount() const;
    int getLeftCount() const;
    QString getName() const;
    bool isDestroyed() const;
    void breakBlock(int x);
    int getType() const;
    int getLevel() const;

private:
    QString name;
    int breakCount;
    int currentBreakCount;
    int treasureType;//宝藏种类，0：无宝藏，1：铁，2：金，3：钻石，4：蓝宝石，5：绿宝石，6：红宝石
    int treasureLevel;
};

#endif // BLOCK_H
