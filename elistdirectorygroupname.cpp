#include "elistdirectorygroupname.h"

EListDirectoryGroupName::EListDirectoryGroupName()
{
}

void EListDirectoryGroupName::addDirectory(EDirectoryGroupName directory)
{
    this->list.append(directory);
}

EDirectoryGroupName EListDirectoryGroupName::getDirectory(int index)
{
    if(index >= 0 && index < this->list.count()){
        return this->list.at(index);
    }
    EDirectoryGroupName ret;
    ret.setName("EDirectoryGroupName::ErrorIndex");
    ret.setComment("EDirectoryGroupName::ErrorIndex");
    ret.setId("-1");
    return ret;
}

EDirectoryGroupName EListDirectoryGroupName::getDirectory(QString name)
{
    for(int i=0;i<this->rowCount();i++){
        EDirectoryGroupName dir = list.at(i);
        //QString str = list.at(i).getName();
        if(dir.getName() == name){
            return list.at(i);
        }
    }
    EDirectoryGroupName ret;
    ret.setName("EDirectoryGroupName::ErrorIndex");
    ret.setComment("EDirectoryGroupName::ErrorIndex");
    ret.setId("-1");
    return ret;
}

EDirectoryGroupName EListDirectoryGroupName::getDirectoryID(QString id)
{
    for(int i=0;i<this->rowCount();i++){
        EDirectoryGroupName dir = list.at(i);
        //QString str = list.at(i).getName();
        if(dir.getId() == id){
            return list.at(i);
        }
    }
    EDirectoryGroupName ret;
    ret.setName("EDirectoryGroupName::ErrorIndex");
    ret.setComment("EDirectoryGroupName::ErrorIndex");
    ret.setId("-1");
    return ret;
}

int EListDirectoryGroupName::rowCount()
{
    return list.count();
}

void EListDirectoryGroupName::clear()
{
    this->list.clear();
}
