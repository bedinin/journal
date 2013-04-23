#ifndef CCROSSING_H
#define CCROSSING_H

#include <QObject>
#include "global.h"
#include "cmysqlconnect.h"
#include "eliststrafe.h"
#include "eoptions.h"

class CCrossing : public QObject
{
    Q_OBJECT
private:
public:
    explicit CCrossing(QObject *parent = 0);
signals:
    void signalReturnLoadCrossing(EListPair listStrafe);
    void signalError(QString);
    void signalReturnAddCrossing(QString result, EPair pair);
    void signalReturnDeleteCrossing(QString result, EPair pair);
    void signalUpdate();
    //void signalGetOptions();
    //void signalReturnStrafeCount(int);

public slots:
    void slotLoadCrossing(EPair i_pair);
    void slotAddCrossing(EPair pair,EPair to_pair);
    void slotDeleteCrossing(EPair pair,EPair to_pair);
    //void slotGetStrafeCount();
    //void slotReturnOptions(QString,EOptions);
    void slotRun();
private:
    QString stringError(QString dbError);
    //int getIndexStrafe(QString id); //Возвращает индекс в списке list по id стрейфа
    void dbLoadCrossing(EPair i_pair);   //Возвращает индекс в списке list
    QString dbAddCrossing(EPair pair,EPair to_pair); //Возвращает ответ БД
    QString dbDeleteCrossing(EPair pair,EPair to_pair); //Возвращает ответ БД
};

#endif // CCROSSING_H
