#ifndef CJOURNALCORE_H
#define CJOURNALCORE_H

#include <QtGui>
#include "global.h"
#include "cmysqlconnect.h"
#include "ishowerror.h"
#include "istrafe.h"
#include "ipair.h"
#include "idirectorygroupname.h"
#include "cdirectorygroupname.h"
#include "istrafefacade.h"
#include "ifacade.h"
#include "coptions.h"
#include "cstrafe.h"
#include "istrafe.h"
#include "ccrossing.h"
#include "idetailedstrafe.h"
#include "icrossing.h"

class CJournalCore : public QObject
{
    Q_OBJECT
private:
    bool errorConnect; //false = не подключено, true = подключено к БД
    CMysqlConnect mysql;
    IShowError *showError;
    IDetailedStrafe *i_detailedStrafe;
    QList<IStrafe*> i_strafe;
    IFacade *i_facade;
    QList<IStrafeFacade*> i_strafeFasade;
    QList<CStrafe*> c_strafe;
    QList<CCrossing*> c_crossing;
    CDirectoryGroupName *c_directoryGroupName;
    IDirectoryGroupName *i_directoryGroupName;
    COptions *c_options;
    EOptions options;
public:
    explicit CJournalCore(QObject *parent = 0);
    ~CJournalCore();
private:
    void creater();
    void createCDirectoryGroupName();       //Создаёт объект CDirectoryGroupName
    void createIDirectoryGroupName();       //Создаёт объект IDirectoryGroupName
    void createDirectoryGroupNameConnect(); //Соединяет сигналы и слоты. Запускает объекты(Run())

    void createOptions();                   //Создаёт объект COptions, соединяет с CJournalCore. Подоётся сигнал signalLoadOptions()

    void createCStrafe();                   //Создаёт объекты CStrafe и добавляет в список c_strafe

    void createIStrafeFacade();             //Создаёт объекты IStrafeFacade и добавляет в список i_strafeFasade
    void createIStrafeFacadeConnect();      //Соединяет сигналы и слоты. Запускает объекты(Run())
    void createIFacade();                   //Создаёт объект IFacade и связывает объекты IStrafeFacade с CStrafe,COptions !!!Запускать после createOptions, createCStrafe, createIStrafeFacade

    //
    void createIDetailedStrafe();           //Создаёт объект IDetailedStrafe и связывает объекты IStrafe с CStrafe,COptions !!!Запускать после createOptions, createCStrafe, createIStrafe
    void createIStrafe();                   //Создаёт объекты IStrafe и добавляет в список i_strafe
    void createIStrafeConnect();            //Соединяет сигналы и слоты. Запускает объекты(Run())


signals:
    void signalShowError(QString);
    void signalErrorMysql(QString);
    void signalLoadOptions();

public slots:    
    void slotCreateMysqlConnect(QString DatabaseName,
                                QString UserName,
                                QString HostName,
                                QString Password);
    void slotShowError(QString);
    void slotShowDirectoryGroupName();
    void slotShowIFacade();
    void slotShowIDetailedStrafe();
    void slotReturnOptions(QString,EOptions);
    void slotICrossingConnect(ICrossing *val);      //Создаёт объекты CCrossing
};

#endif // CJOURNALCORE_H
