#include "cjournalcore.h"

CJournalCore::CJournalCore(QObject *parent) :
    QObject(parent)
{
    //Кодировка
    QTextCodec *russian =QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForTr(russian);
    //Создание объекта CMysqlConnect и подключение к БД
    //this->mysql = new CMysqlConnect(this);
    //mysql->setParam("Journal","root","localhost","");
    //mysql->mysqlConnect();
    //this->c_strafe = NULL;
    this->i_facade = NULL;
    //this->i_strafe = NULL;
    //this->i_strafeFasade = NULL;
    this->c_directoryGroupName= NULL;
    this->i_directoryGroupName= NULL;
    //this->c_crossing = NULL;
    this->creater();
    //this->i_strafe->show();
    //this->slotCreateMysqlConnect("Journal","root","localhost","");
    this->showError->show();
    QObject::connect(this,SIGNAL(signalShowError(QString)),this->showError,SLOT(slotShowError(QString)));
    this->slotShowIFacade();
    this->slotShowIDetailedStrafe();
    //this->createDirectoryGroupName();
    //this->createOptions();
    //this->slotShowDirectoryGroupName();
    //this->createFacade();
    //this->createStrafe();
    //this->i_strafe->slotGetStrafe("0");
    /*this->strafe = new IStrafe();
    this->strafe->show();
    IPair *pair = new IPair();
    EPair ePair;
    ePair.setPair("1");
    ePair.setStrafe("2");
    ePair.setPlint("3");
    pair->setPair(&ePair);
    //pair->show();
    this->strafe->slotSetPair(2,2,pair);
    this->strafe->slotSetName("10");
    IDirectoryGroupName *dn = new IDirectoryGroupName();
    dn->show();*/
};

//

CJournalCore::~CJournalCore(){

    this->mysql.mysqlDisconnect();
    /*this->deleteDirectoryGroupName();
    this->deleteOptions();
    this->deleteFacade();
    this->deleteStrafe();


    //QObject::disconnect(this->c_directoryGroupName);
    //QObject::disconnect(this->i_directoryGroupName);
    //delete this->c_directoryGroupName;
    //delete this->i_directoryGroupName;*/
    if(this->c_options != NULL){
        QObject::disconnect(this->c_options);
        delete this->c_options;
    }
    for(int i = 0; i<this->c_strafe.count();i++){
        QObject::disconnect(this->c_strafe.at(i));
        delete this->c_strafe.at(i);
    }
    if(this->i_facade != NULL){
        QObject::disconnect(this->i_facade);
        delete this->i_facade;
    }
    if(this->i_detailedStrafe != NULL){
        QObject::disconnect(this->i_detailedStrafe);
        delete this->i_detailedStrafe;
    }
    for(int i = 0; i<this->c_crossing.count();i++){
        QObject::disconnect(this->c_crossing.at(i));
        delete this->c_crossing.at(i);
    }
    /*
      //Удаляется во время удаления i_detailedStrafe
    for(int i = 0; i<this->i_strafe.count();i++){
        QObject::disconnect(this->i_strafe.at(i));
        delete this->i_strafe.at(i);
    }
    */
    /*
      //Удаляется во время удаления i_facade
    for(int i = 0; i<this->i_strafeFasade.count();i++){
        QObject::disconnect(this->i_strafeFasade.at(i));
        delete this->i_strafeFasade.at(i);
    }*/

    if(this->c_directoryGroupName != NULL){
        QObject::disconnect(this->c_directoryGroupName);
        delete this->c_directoryGroupName;
    }
    if(this->i_directoryGroupName != NULL){
        QObject::disconnect(this->i_directoryGroupName);
        delete this->i_directoryGroupName;
    }
    /*if(this->c_crossing != NULL){
        QObject::disconnect(this->c_crossing);
        delete this->c_crossing;
    }*/
};

void CJournalCore::slotCreateMysqlConnect(QString DatabaseName,
                                      QString UserName,
                                      QString HostName,
                                      QString Password)
{
    this->mysql.setParam(DatabaseName,UserName,HostName,Password);
    if(this->mysql.mysqlConnect() == false){
        emit this->signalErrorMysql(this->mysql.getError());
    }
    else{
        query = this->mysql.getQuery();
    }

}

void CJournalCore::createCDirectoryGroupName()
{
    this->c_directoryGroupName = new CDirectoryGroupName();
}

void CJournalCore::slotShowError(QString i_error)
{
    this->i_directoryGroupName->slotError(i_error);
    emit this->signalShowError(i_error);
}

void CJournalCore::slotShowDirectoryGroupName()
{
    this->i_directoryGroupName->show();
}

void CJournalCore::createOptions()
{
    this->c_options = new COptions(this);
    QObject::connect(this,SIGNAL(signalLoadOptions()),this->c_options,SLOT(slotLoadOptions()));
    QObject::connect(this->c_options,SIGNAL(signalReturnOptions(QString,EOptions)),this,SLOT(slotReturnOptions(QString,EOptions)));
    emit this->signalLoadOptions();
}

void CJournalCore::slotReturnOptions(QString i_return, EOptions i_options)
{
    if(i_return == "NORMAL"){
        this->options = i_options;
    }
}

void CJournalCore::createIFacade()
{
    this->i_facade = new IFacade();
    if((this->c_strafe.count() == this->i_strafeFasade.count()) && (this->c_strafe.count() == options.getStrafeCount().toInt())){
        for(int i=0;i<options.getStrafeCount().toInt();i++){
            IStrafeFacade *strafe = this->i_strafeFasade.at(i);
            strafe->setParent(this->i_facade);
            this->i_facade->addWidget(strafe);
        }
    }
}

void CJournalCore::createIStrafe()
{
    for(int i = 0; i<this->i_strafe.count();i++){
        this->i_strafe.at(i)->setParent(NULL);
        delete this->i_strafe.at(i);
    }
    this->i_strafe.clear();
    for(int i=0;i<options.getStrafeCount().toInt();i++){
        IStrafe *strafe = new IStrafe();
        strafe->setName(QString::number(i));
        this->i_strafe.append(strafe);
    }
    //this->showError->slotShowError(options.getStrafeCount());
    //for(int i=0;i<options.getStrafeCount().toInt();i++){
        //IStrafe *strafeFasade = new IStrafeFacade(this->i_facade);
        //i_strafe
        //i_strafe->slotRun();
        //this->i_facade->addWidget(strafeFasade);
        //strafeFasade->slotGetStrafe(QString::number(i));
    //}
    //this->i_strafe->show();
}

void CJournalCore::creater()
{
    this->slotCreateMysqlConnect("Journal","root","localhost","");

    this->showError = new IShowError();

    this->createCDirectoryGroupName();
    this->createIDirectoryGroupName();
    this->createDirectoryGroupNameConnect();

    this->createOptions();

    this->createCStrafe();

    this->createIStrafeFacade();
    this->createIStrafeFacadeConnect();
    this->createIFacade();

    this->createIStrafe();
    this->createIStrafeConnect();
    this->createIDetailedStrafe();

    //this->createCCrossing();

    //this->i_strafe = new IStrafe();
    //this->c_strafe = new CStrafe();
    //this->i_facade = new IFacade();
    //this->c_crossing = new CCrossing();

    //this->createOptions();
    //this->createCDirectoryGroupName();

    //this->createIFacade();
    //this->createDetailedStrafe();
    //this->createCrossing();
}

void CJournalCore::slotICrossingConnect(ICrossing *val)
{

    CCrossing *cCrossing = new CCrossing();
    cCrossing->slotRun();
    this->c_crossing.append(cCrossing);
    //ICrossing *cr = new ICrossing();
    QObject::connect(val,SIGNAL(signalLoadCrossing(EPair)),cCrossing,SLOT(slotLoadCrossing(EPair)));
    QObject::connect(val,SIGNAL(signalAddCrossing(EPair,EPair)),cCrossing,SLOT(slotAddCrossing(EPair,EPair)));
    QObject::connect(val,SIGNAL(signalDeleteCrossing(EPair,EPair)),cCrossing,SLOT(slotDeleteCrossing(EPair,EPair)));

    QObject::connect(cCrossing,SIGNAL(signalReturnLoadCrossing(EListPair)),val,SLOT(slotReturnLoadCrossing(EListPair)));
    QObject::connect(cCrossing,SIGNAL(signalReturnAddCrossing(QString,EPair)),val,SLOT(slotReturnAddCrossing(QString,EPair)));
    QObject::connect(cCrossing,SIGNAL(signalReturnDeleteCrossing(QString,EPair)),val,SLOT(slotReturnDeleteCrossing(QString,EPair)));

    for(int i = 0; i<this->i_strafe.count();i++){
        IStrafe *strafe = dynamic_cast<IStrafe*>(this->i_strafe.at(i));
        QObject::connect(cCrossing,SIGNAL(signalUpdate()),strafe,SLOT(slotGetStrafe()));
    }
    //val->slotRun();
    //val->show();
}

void CJournalCore::createCStrafe()
{
    for(int i = 0; i<this->c_strafe.count();i++){
        this->c_strafe.at(i)->setParent(NULL);
        delete this->c_strafe.at(i);
    }
    this->c_strafe.clear();
    for(int i=0;i<options.getStrafeCount().toInt();i++){
        CStrafe *strafe = new CStrafe();
        strafe->setName(QString::number(i));

        QObject::connect(strafe,SIGNAL(signalGetOptions()),
                        this->c_options,SLOT(slotLoadOptions()));
        QObject::connect(this->c_options,SIGNAL(signalReturnOptions(QString,EOptions)),
                        strafe,SLOT(slotReturnOptions(QString,EOptions)));
        QObject::connect(strafe,SIGNAL(signalError(QString)),
                         this->showError,SLOT(slotShowError(QString)));
        strafe->slotRun();
        this->c_strafe.append(strafe);
    }
}

void CJournalCore::createIDetailedStrafe()
{
    this->i_detailedStrafe = new IDetailedStrafe();
    if((this->c_strafe.count() == this->i_strafe.count()) && (this->c_strafe.count() == options.getStrafeCount().toInt())){
        for(int i=0;i<options.getStrafeCount().toInt();i++){
            IStrafe *strafe = this->i_strafe.at(i);
            strafe->setParent(this->i_detailedStrafe);
            this->i_detailedStrafe->addWidget(strafe);
        }
    }
    else{
        qDebug() << "Error CJournalCore::createIDetailedStrafe >> " << "this->c_strafe.count() == this->i_strafe->count() == options.getStrafeCount()";
    }
}

void CJournalCore::createIDirectoryGroupName()
{
    this->i_directoryGroupName = new IDirectoryGroupName();
}

void CJournalCore::createDirectoryGroupNameConnect()
{
    QObject::connect(this->c_directoryGroupName,SIGNAL(signalError(QString)),
                     this,SLOT(slotShowError(QString)));
    QObject::connect(this->i_directoryGroupName,SIGNAL(signalLoadAllDirectory()),
                     this->c_directoryGroupName,SLOT(slotLoadAllDirectory()));
    QObject::connect(this->c_directoryGroupName,SIGNAL(signalReturnLoadAllDirectory(EListDirectoryGroupName)),
                     this->i_directoryGroupName,SLOT(slotReturnLoadAllDirectory(EListDirectoryGroupName)));

    QObject::connect(this->i_directoryGroupName,SIGNAL(signalAddDirectory(EDirectoryGroupName)),
                     this->c_directoryGroupName,SLOT(slotAddDirectory(EDirectoryGroupName)));
    QObject::connect(this->c_directoryGroupName,SIGNAL(signalReturnAddDirectory(QString,EDirectoryGroupName)),
                     this->i_directoryGroupName,SLOT(slotReturnAddDirectory(QString,EDirectoryGroupName)));

    QObject::connect(this->i_directoryGroupName,SIGNAL(signalEditDirectory(EDirectoryGroupName)),
                     this->c_directoryGroupName,SLOT(slotEditDirectory(EDirectoryGroupName)));
    QObject::connect(this->c_directoryGroupName,SIGNAL(signalReturnEditDirectory(QString,EDirectoryGroupName)),
                     this->i_directoryGroupName,SLOT(slotReturnEditDirectory(QString,EDirectoryGroupName)));

    QObject::connect(this->i_directoryGroupName,SIGNAL(signalDeleteDirectory(EDirectoryGroupName)),
                     this->c_directoryGroupName,SLOT(slotDeleteDirectory(EDirectoryGroupName)));
    QObject::connect(this->c_directoryGroupName,SIGNAL(signalReturnDeleteDirectory(QString)),
                     this->i_directoryGroupName,SLOT(slotReturnDeleteDirectory(QString)));

    this->i_directoryGroupName->slotRun();
}

void CJournalCore::createIStrafeFacade()
{
    for(int i = 0; i<this->i_strafeFasade.count();i++){
        this->i_strafeFasade.at(i)->setParent(NULL);
        delete this->i_strafeFasade.at(i);
    }
    this->i_strafeFasade.clear();
    for(int i=0;i<options.getStrafeCount().toInt();i++){
        IStrafeFacade *strafe = new IStrafeFacade();
        strafe->setName(QString::number(i));
        this->i_strafeFasade.append(strafe);
    }
}

void CJournalCore::createIStrafeFacadeConnect()
{
   qDebug() <<  "c_strafe.count() >> " << this->c_strafe.count();
    qDebug() <<  "i_strafeFasade.count() >> " << this->i_strafeFasade.count();
    qDebug() <<  "options.getStrafeCount().toInt() >> " << options.getStrafeCount().toInt();
 /**/
    if((this->c_strafe.count() == this->i_strafeFasade.count()) && (this->c_strafe.count() == options.getStrafeCount().toInt())){
        for(int i=0;i<options.getStrafeCount().toInt();i++){
            IStrafeFacade *i_strafeTmp = this->i_strafeFasade.at(i);
            CStrafe *c_strafeTmp = this->c_strafe.at(i);
            //IStrafeFacade *strafe = new IStrafeFacade(this->i_facade);
            QObject::connect(i_strafeTmp,SIGNAL(signalGetListDirectoryGroupName()),
                         this->c_directoryGroupName,SLOT(slotLoadAllDirectory()));
            QObject::connect(this->c_directoryGroupName,SIGNAL(signalReturnLoadAllDirectory(EListDirectoryGroupName)),
                         i_strafeTmp,SLOT(slotGetListDirectoryGroupName(EListDirectoryGroupName)));

            QObject::connect(i_strafeTmp,SIGNAL(signalGetStrafe()),
                        c_strafeTmp,SLOT(slotLoadStrafe()));
            QObject::connect(c_strafeTmp,SIGNAL(signalReturnLoadStrafe(EListPair)),
                        i_strafeTmp,SLOT(slotReturnGetStrafe(EListPair)));
            QObject::connect(i_strafeTmp,SIGNAL(signalEditPair(EPair)),
                         c_strafeTmp,SLOT(slotEditPair(EPair)));
            QObject::connect(c_strafeTmp,SIGNAL(signalReturnEditPair(QString,EPair)),
                         i_strafeTmp,SLOT(slotReturnEditPair(QString,EPair)));
            i_strafeTmp->slotRun();
            i_strafeTmp->slotGetStrafe();
        }
    }
    else{
        qDebug() << "Error >>> CJournalCore::createIStrafeFacadeConnect";
    }
}

void CJournalCore::createIStrafeConnect()
{
    /*qDebug() <<  "c_strafe.count() >> " << this->c_strafe.count();
    qDebug() <<  "i_strafe.count() >> " << this->i_strafe.count();
    qDebug() <<  "options.getStrafeCount().toInt() >> " << options.getStrafeCount().toInt();
*/
    if((this->c_strafe.count() == this->i_strafe.count()) && (this->c_strafe.count() == options.getStrafeCount().toInt())){
        for(int i=0;i<options.getStrafeCount().toInt();i++){
            IStrafe *i_strafeTmp = this->i_strafe.at(i);
            CStrafe *c_strafeTmp = this->c_strafe.at(i);

            QObject::connect(i_strafeTmp,SIGNAL(signalGetListDirectoryGroupName()),
                     this->c_directoryGroupName,SLOT(slotLoadAllDirectory()));
            QObject::connect(this->c_directoryGroupName,SIGNAL(signalReturnLoadAllDirectory(EListDirectoryGroupName)),
                     i_strafeTmp,SLOT(slotGetListDirectoryGroupName(EListDirectoryGroupName)));

            QObject::connect(i_strafeTmp,SIGNAL(signalGetStrafe()),
                    c_strafeTmp,SLOT(slotLoadStrafe()));
            QObject::connect(c_strafeTmp,SIGNAL(signalReturnLoadStrafe(EListPair)),
                    i_strafeTmp,SLOT(slotReturnGetStrafe(EListPair)));
            QObject::connect(i_strafeTmp,SIGNAL(signalEditPair(EPair)),
                     c_strafeTmp,SLOT(slotEditPair(EPair)));
            QObject::connect(c_strafeTmp,SIGNAL(signalReturnEditPair(QString,EPair)),
                     i_strafeTmp,SLOT(slotReturnEditPair(QString,EPair)));
            QObject::connect(i_strafeTmp,SIGNAL(signalICrossingConnect(ICrossing*)),this,SLOT(slotICrossingConnect(ICrossing*)));
            i_strafeTmp->slotRun();
            i_strafeTmp->slotGetStrafe();
        }
    }
    else{
        qDebug() << "Error >>> CJournalCore::createIStrafeConnect";
    }
}

void CJournalCore::slotShowIFacade()
{
    this->i_facade->show();
}

void CJournalCore::slotShowIDetailedStrafe()
{
    this->i_detailedStrafe->show();
}

