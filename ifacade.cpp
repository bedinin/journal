#include "ifacade.h"

IFacade::IFacade(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    this->count = 0;
}

void IFacade::addWidget(QWidget *wdg)
{
    QHBoxLayout *lo = dynamic_cast<QHBoxLayout*>(this->layout());
    lo->addWidget(wdg);
    this->count++;
}

