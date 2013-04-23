#include "ipairfacade.h"

IPairFacade::IPairFacade(QWidget *parent) :
    QLabel(parent)
{
    this->rgb = qRgb(255,255,255);
    this->setColor(false);
}

EPair IPairFacade::getPair()
{
    return this->pair;
}

void IPairFacade::setPair(EPair i_pair)
{
    this->pair = i_pair;
}

void IPairFacade::setColor(bool select)
{
    QRgb currentRGB;
    if(select){
        currentRGB = this->contrastyRgb();
    }
    else{
        currentRGB = this->rgb;
    }
    QString formatColor = QString("IPairFacade { background-color: rgb(%1, %2, %3);")+
                          QString("selection-color: rgb(0,0,0);")+
                          QString("selection-background-color: rgb(0, 0, 0);}");
    this->setStyleSheet(formatColor.arg(QString::number(qRed(currentRGB))).
                                    arg(QString::number(qGreen(currentRGB))).
                                    arg(QString::number(qBlue(currentRGB))));
}

void IPairFacade::setGroupName(EDirectoryGroupName groupName)
{
    this->pair.setGroup_id(groupName.getId());
    this->rgb = groupName.getColor().toUInt();
    this->setColor(false);
}

void IPairFacade::slotSelected(bool select)
{
    this->setColor(select);
}

QRgb IPairFacade::contrastyRgb()
{//255 -
    QRgb r =  255 -qRed(this->rgb),
        g = 255 -qGreen(this->rgb),
        b = 255 ;//- qBlue(this->rgb);

    return qRgb(r,g,b);
}
