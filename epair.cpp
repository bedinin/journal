#include "epair.h"

EPair::EPair()
{
};

//***SET***

void EPair::setComment(QString val)
{
    this->comment = val;
};

void EPair::setGroup_id(QString val)
{
    this->group_id = val;
};

void EPair::setPlint_name_id(QString val)
{
    this->plint_name_id = val;
};

void EPair::setExt_id(QString val)
{
    this->ext_id = val;
};

void EPair::setValue(QString val)
{
    this->value = val;
};

void EPair::setFlag_value(QString val)
{
    this->flag_value = val;
};

void EPair::setPair(QString val)
{
    this->pair = val;
};

void EPair::setPlint(QString val)
{
    this->plint = val;
};

void EPair::setStrafe(QString val)
{
    this->strafe = val;
};

void EPair::setID(QString val)
{
    this->id = val;
};

//***GET***

QString  EPair::getComment()
{
    return this->comment;
};

QString  EPair::getPlint_name_id()
{
    return this->plint_name_id;
};

QString  EPair::getExt_id()
{
    return this->ext_id;
};

QString  EPair::getValue()
{
    return this->value;
};

QString  EPair::getFlag_value()
{
    return this->flag_value;
};

QString  EPair::getPair()
{
    return this->pair;
};

QString  EPair::getPlint()
{
    return this->plint;
};

QString  EPair::getStrafe()
{
    return this->strafe;
};

QString  EPair::getID()
{
    return this->id;
};

QString  EPair::getGroup_id()
{
    return this->group_id;
};
/*
EPair& EPair::operator =(EPair &val)
{
    this->id = val.id;
    this->strafe = val.strafe;
    this->plint = val.plint;
    this->pair = val.pair;
    this->flag_value = val.flag_value;
    this->value = val.value;
    this->ext_id = val.ext_id;
    this->plint_name_id = val.plint_name_id;
    this->comment = val.comment;
    return *this;
};*/
