#ifndef ELISTSTRAFE_H
#define ELISTSTRAFE_H
#include <QtCore>
#include <QList>
#include "elistpair.h"

class EListStrafe
{
private:
    QList<EListPair> list;
public:
    EListStrafe();
    void addStrafe(EListPair);
    EListPair getStrafe(QString name);
    EListPair getStrafe(int index);
    void deleteStrafe(QString name);
    int rowCount();
    void clear();
};

#endif // ELISTSTRAFE_H
