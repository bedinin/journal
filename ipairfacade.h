#ifndef IPAIRFACADE_H
#define IPAIRFACADE_H

#include <QLabel>
#include "epair.h"
#include "edirectorygroupname.h"

class IPairFacade : public QLabel
{
    Q_OBJECT
private:
    EPair pair;
    QRgb rgb;
public:
    explicit IPairFacade(QWidget *parent = 0);
    EPair getPair();
    void setPair(EPair i_pair);
    void setGroupName(EDirectoryGroupName groupName);;
signals:

public slots:
    void slotSelected(bool select);
private:
    void setColor(bool select);
    QRgb contrastyRgb();
};

#endif // IPAIRFACADE_H
