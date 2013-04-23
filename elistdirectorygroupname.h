#ifndef ELISTDIRECTORYGROUPNAME_H
#define ELISTDIRECTORYGROUPNAME_H
#include <QtCore>
#include <QList>
#include "edirectorygroupname.h"
class EListDirectoryGroupName
{
private:
        QList<EDirectoryGroupName> list;
public:
    EListDirectoryGroupName();
    void addDirectory(EDirectoryGroupName);
    EDirectoryGroupName getDirectory(int index);
    EDirectoryGroupName getDirectory(QString name);
    EDirectoryGroupName getDirectoryID(QString id);
    void deleteDirectory(int index);
    int rowCount();
    void clear();
};

#endif // ELISTDIRECTORYGROUPNAME_H
