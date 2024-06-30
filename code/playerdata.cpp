#include "playerdata.h"

PlayerData::PlayerData(){
    money=0;
    iron=0;
    gold=0;
    diamond=0;
    ruby=0;
    speedMult=1;
    speedBase=5;


    unbreakLevel=0;
    speedLevel=0;
}

long long PlayerData::getMoney() const{return money;}
int PlayerData::getIron() const{return iron;}
int PlayerData::getGold() const{return gold;}
int PlayerData::getDiamond() const{return diamond;}
int PlayerData::getRuby() const{return ruby;}
long long PlayerData::getSpeedBase() const{return speedBase;}
double PlayerData::getSpeedMult() const{return speedMult;}
long long PlayerData::getSpeed(){return speedBase*speedMult;}



void PlayerData::addtoMoney(long long x){ money+=x;}
void PlayerData::addtoIron(int x){iron+=x;}
void PlayerData::addtoGold(int x){gold+=x;}
void PlayerData::addtoDiamond(int x){diamond+=x;}
void PlayerData::addtoRuby(int x){ruby+=x;}

void PlayerData::setSpeedBase(long long x){speedBase=x;}
void PlayerData::setSpeedMult(double x){speedMult=x;}

int PlayerData::getPickUnbreak()const{return unbreakLevel;}
int PlayerData::getPickSpeed()  const{return speedLevel;}

void PlayerData::addPickUnbreak(int x){unbreakLevel+=x;}
void PlayerData::addPickSpeed(int x)  {speedLevel+=x;}

void PlayerData::handleGameEvents(int x[7],int sm)
{
    money+=this->getSpeed()*sm;
    if(x[0]==114514&&(x[1]!=0||x[2]!=0||x[3]!=0||x[4]!=0||x[5]!=0||x[6]!=0))
    {

        iron+=x[1];
        gold+=x[2];
        diamond+=x[3];
        ruby+=x[5];

        speedBase+=5*x[4];
        speedMult*=pow(1.2,x[6]);
        for(int i=0;i<7;i++)
            x[i]=0;

    }
    else
        return;



}

