#ifndef ELISTPAIR_H
#define ELISTPAIR_H
#include <QtCore>
#include <QList>
#include "epair.h"
class EListPair
{
private:
    QList<EPair> list;
    QString strafe;
    int plintCount,
            pairCount;
public:
    EListPair(); // Ещё что то
    void addPair(EPair);
    EPair getPair(int index);
//    EPair getPair(QString name);
    void deletePair(int index);
    void deletePair(QString name);
    void setStrafe(QString i_strafe);
    void setPair(EPair pair);
    void setPlintCount(int count);
    void setPairCount(int count);
    int getPlintCount();
    int getPairCount();
    QString getStrafe();
    int rowCount();
    void clear();
};

#endif // ELISTPAIR_H
