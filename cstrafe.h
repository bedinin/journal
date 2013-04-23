#ifndef CSTRAFE_H
#define CSTRAFE_H

#include <QObject>
#include "global.h"
#include "cmysqlconnect.h"
#include "elistpair.h"
#include "eoptions.h"

class CStrafe : public QObject
{
    Q_OBJECT
private:
    //EListPair list;
    EOptions options;
    QString strafe;
public:
    explicit CStrafe(QObject *parent = 0);
    void setName(QString val);
    QString getName();
signals:
    void signalReturnLoadStrafe(EListPair listStrafe);
    void signalError(QString);
    void signalReturnEditPair(QString result, EPair pair);
    void signalGetOptions();
    //void signalReturnStrafeCount(int);

public slots:
    void slotLoadStrafe();
    void slotEditPair(EPair pair);
    //void slotGetStrafeCount();
    void slotReturnOptions(QString,EOptions);
    void slotRun();
private:
    QString stringError(QString dbError);
    //int getIndexStrafe(QString id); //Возвращает индекс в списке list по id стрейфа
    //int dbLoadStrafe(QString id);   //Возвращает индекс в списке list
    //QString dbEditPair(EPair pair); //Возвращает ответ БД
};

#endif // CSTRAFE_H
