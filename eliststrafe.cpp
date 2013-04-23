#include "eliststrafe.h"

EListStrafe::EListStrafe()
{
}

void EListStrafe::addStrafe(EListPair listPair)
{
    this->list.append(listPair);
}

EListPair EListStrafe::getStrafe(int index)
{
    if(index >= 0 && index < this->list.count()){
        return list.at(index);
    }
    EListPair ret;
    ret.setStrafe("-1");
    return ret;
}
EListPair EListStrafe::getStrafe(QString name)
{
    for(int i=0;i<this->rowCount();i++){
        EListPair dir = list.at(i);
        if(dir.getStrafe() == name){
            return list.at(i);
        }
    }
    EListPair ret;
    ret.setStrafe("-1");
     return ret;
}

void EListStrafe::deleteStrafe(QString name)
{
    for(int i=0;i<this->rowCount();i++){
        EListPair dir = list.at(i);
        if(dir.getStrafe() == name){
            this->list.removeAt(i);
            break;
        }
    }
}
int EListStrafe::rowCount()
{
    return list.count();
}

void EListStrafe::clear()
{
    this->list.clear();
}
