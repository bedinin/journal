#include "eoptions.h"

EOptions::EOptions()
{
    this->strafe_count  = "";
    this->plint_count   = "";
    this->pair_count    = "";
    this->cross_name    = "";
}

void EOptions::setStrafeCount(QString name)
{
    this->strafe_count = name;
}

void EOptions::setPlintCount(QString name)
{
    this->plint_count = name;
}

void EOptions::setPairCount(QString name)
{
    this->pair_count = name;
}

void EOptions::setCrossName(QString name)
{
    this->cross_name = name;
}

QString EOptions::getStrafeCount()
{
    return this->strafe_count;
}

QString EOptions::getPlintCount()
{
    return this->plint_count;
}

QString EOptions::getPairCount()
{
    return this->pair_count;
}

QString EOptions::getCrossName()
{
    return this->cross_name;
}
