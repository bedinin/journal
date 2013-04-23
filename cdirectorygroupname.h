#ifndef CDIRECTORYGROUPNAME_H
#define CDIRECTORYGROUPNAME_H

#include <QObject>
#include "global.h"
#include "cmysqlconnect.h"
#include "elistdirectorygroupname.h"

class CDirectoryGroupName : public QObject
{
    Q_OBJECT
public:
    explicit CDirectoryGroupName(QObject *parent = 0);
private:
        QString stringError(QString bdError);

signals:
    void signalReturnLoadAllDirectory(EListDirectoryGroupName list);
    void signalReturnLoadDirectory(EDirectoryGroupName directory);
    void signalReturnAddDirectory(QString result, EDirectoryGroupName directory);
    void signalError(QString);
    void signalReturnDeleteDirectory(QString);
    void signalReturnEditDirectory(QString result, EDirectoryGroupName directory);

public slots:
    void slotLoadAllDirectory();
    void slotLoadDirectory(QString id);
    void slotAddDirectory(EDirectoryGroupName directory);
    void slotDeleteDirectory(EDirectoryGroupName directory);
    void slotEditDirectory(EDirectoryGroupName directory);
};

#endif // CDIRECTORYGROUPNAME_H
