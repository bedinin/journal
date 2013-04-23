#ifndef IPAIR_H
#define IPAIR_H

#include <QLabel>
#include "epair.h"
#include "edirectorygroupname.h"

class IPair : public QLabel
{
    Q_OBJECT
private:
    EPair pair;
    QRgb rgb;
public:
    explicit IPair(QWidget *parent = 0);
    EPair getPair();
    void setPair(EPair i_pair);
    void setGroupName(EDirectoryGroupName groupName);
signals:

public slots:
    void slotSelected(bool select);
private:
    void setColor(bool select);
    QRgb contrastyRgb();
};

#endif // IPAIR_H
