#include "elistpair.h"

EListPair::EListPair()
{
    this->setPairCount(-1);
    this->setPlintCount(-1);
}

void EListPair::addPair(EPair pair)
{
    this->list.append(pair);
}

EPair EListPair::getPair(int index)
{
    if(index >= 0 && index < this->list.count()){
        return this->list.at(index);
    }
    EPair ret;
    ret.setValue("EListPair::ErrorIndex");
    ret.setComment("EListPair::ErrorIndex");
    ret.setID("-1");
    return ret;
}
/*
EPair EListPair::getPair(QString name)
{
    for(int i=0;i<this->rowCount();i++){
        EPair dir = list.at(i);
        if(dir.getStrafe() == name){
            return list.at(i);
        }
    }
    EPair ret;
    ret.setValue("EListPair::ErrorIndex");
    ret.setComment("EListPair::ErrorIndex");
    ret.setID("-1");
    return ret;
}
*/
int EListPair::rowCount()
{
    return list.count();
}

void EListPair::deletePair(int index)
{
    if(index >= 0 && index < this->list.count()){
        this->list.removeAt(index);
    }
}

void EListPair::deletePair(QString name)
{
    for(int i=0;i<this->rowCount();i++){
        EPair dir = list.at(i);
        if(dir.getStrafe() == name){
            this->list.removeAt(i);
            break;
        }
    }
}

void EListPair::clear()
{
    this->list.clear();
}

void EListPair::setStrafe(QString i_strafe)
{
    this->strafe = i_strafe;
}

QString EListPair::getStrafe()
{
    return strafe;
}

void EListPair::setPair(EPair pair)
{
    for(int i=0;i<this->rowCount();i++){
        EPair dir = list.at(i);
        if(dir.getStrafe() == pair.getStrafe() &&
           dir.getPlint() == pair.getPlint() &&
           dir.getPair() == pair.getPair()){

            list.replace(i,pair);
        }
    }
}

void EListPair::setPlintCount(int count)
{
    this->plintCount = count;
}

void EListPair::setPairCount(int count)
{
    this->pairCount = count;
}

int EListPair::getPlintCount()
{
    return this->plintCount;
}

int EListPair::getPairCount()
{
    return this->pairCount;
}
