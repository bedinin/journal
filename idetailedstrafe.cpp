#include "idetailedstrafe.h"

IDetailedStrafe::IDetailedStrafe(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    this->count = 0;
    this->table->clear();
}

void IDetailedStrafe::addWidget(QWidget *wdg)
{
    this->table-
    /*
    QHBoxLayout *lo = dynamic_cast<QHBoxLayout*>(this->layout());
    lo->addWidget(wdg);
    this->count++;*/
}

