#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include<cmath>

class PlayerData
{
public:
    PlayerData();

    //get资源值
    long long getMoney() const;
    int getIron() const;
    int getGold() const;
    int getDiamond() const;
    int getRuby() const;
    long long getSpeedBase() const;
    double getSpeedMult() const;
    long long getSpeed();

    void addtoMoney(long long x);
    void addtoIron(int x);
    void addtoGold(int x);
    void addtoDiamond(int x);
    void addtoRuby(int x);
    void setSpeedBase(long long x);
    void setSpeedMult(double x);

    //get稿子值
    int getPickUnbreak()const;
    int getPickSpeed()  const;

    void addPickUnbreak(int x);
    void addPickSpeed(int x);

    void handleGameEvents(int x[7],int sm);

private:
    long long money;//钱数
    int iron;
    int gold;
    int diamond;//3种夺宝资源
    int ruby;//特殊稀有资源
    double speedMult;//赚钱速率，乘区
    long long speedBase;//赚钱速率，加区

    int unbreakLevel;
    int speedLevel;//稿子耐久，急迫等级
};

#endif // PLAYERDATA_H
