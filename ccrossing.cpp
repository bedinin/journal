#include "ccrossing.h"

CCrossing::CCrossing(QObject *parent) :
    QObject(parent)
{
}

void CCrossing::dbLoadCrossing(EPair i_pair)
{
    QString format = "CALL get_crossing('%1','%2','%3');";
    EListPair listPair;
    listPair.setStrafe("-1");
    //listPair.setPairCount(this->options.getPairCount().toInt());
    //listPair.setPlintCount(this->options.getPlintCount().toInt());
    QString str_query = format.arg(i_pair.getStrafe()).arg(i_pair.getPlint()).arg(i_pair.getPair());
    //qDebug() << str_query;
    if(query->exec(str_query)){
        QSqlRecord rec = query->record();
        while(query->next()){
            EPair pair;
/*
            `this_strafe` text,
            `this_plint` text,
            `this_pair` text,
            `prev_strafe` text,
            `prev_plint` text,
            `prev_pair` text,
*/
            if(query->value(rec.indexOf("this_strafe")).toString() == i_pair.getStrafe() &&
               query->value(rec.indexOf("this_plint")).toString() == i_pair.getPlint() &&
               query->value(rec.indexOf("this_pair")).toString() == i_pair.getPair()){

                pair.setStrafe(query->value(rec.indexOf("prev_strafe")).toString());
                pair.setPlint(query->value(rec.indexOf("prev_plint")).toString());
                pair.setPair(query->value(rec.indexOf("prev_pair")).toString());
            }
            if(query->value(rec.indexOf("prev_strafe")).toString() == i_pair.getStrafe() &&
               query->value(rec.indexOf("prev_plint")).toString() == i_pair.getPlint() &&
               query->value(rec.indexOf("prev_pair")).toString() == i_pair.getPair()){

                pair.setStrafe(query->value(rec.indexOf("this_strafe")).toString());
                pair.setPlint(query->value(rec.indexOf("this_plint")).toString());
                pair.setPair(query->value(rec.indexOf("this_pair")).toString());
            }
            listPair.addPair(pair);
            //qDebug() << pair.getStrafe() << " : " << pair.getPlint() << " : " << pair.getPair();
        }
        //qDebug() << "dbLoadCrossing::Count = " << listPair.rowCount();
        emit this->signalReturnLoadCrossing(listPair);

    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CCrossing::dbLoadCrossing)"));
    };
}

QString CCrossing::stringError(QString dbError)
{
    if(dbError == "NORMAL"){
        return  "NORMAL";
    }
    if(dbError == "ERROR_REPEAT_CROSSING"){
        return QObject::tr("Кроссировка между парами уже существует");
    }
    if(dbError == "NOT_FOUND"){
        return QObject::tr("Запись в базе не найдена");
    }
    if(dbError == "ERROR_FLAG_VALUE_CROSSING"){
        return QObject::tr("Обе пары имеют тип исходящие");
    }
    if(dbError == "ERROR_NOT_CROSSING"){
        return QObject::tr("Пары не соединены");
    }
    return QObject::tr("Неизвестный результат (CCrossing::stringError)");
}

void CCrossing::slotLoadCrossing(EPair i_pair)
{
    this->dbLoadCrossing(i_pair);
}

void CCrossing::slotRun()
{
   /* EPair pair;
    pair.setStrafe("0");
    pair.setPlint("0");
    pair.setPair("2");
    this->slotLoadCrossing(pair);
    EPair to_pair;
    to_pair.setStrafe("0");
    to_pair.setPlint("0");
    to_pair.setPair("4");
    //this->slotDeleteCrossing(pair,to_pair);
    //this->slotAddCrossing(pair,to_pair);
*/
}

void CCrossing::slotAddCrossing(EPair pair, EPair to_pair)
{
    QString result = this->dbAddCrossing(pair,to_pair);
    this->signalReturnAddCrossing(result,to_pair);
}

QString CCrossing::dbAddCrossing(EPair pair, EPair to_pair)
{
    QString format = "CALL set_crossing('%1','%2','%3','%4','%5','%6');";
    QString strQuery = format.arg(pair.getStrafe()).
                       arg(pair.getPlint()).
                       arg(pair.getPair()).
                       arg(to_pair.getStrafe()).
                       arg(to_pair.getPlint()).
                       arg(to_pair.getPair());
    //qDebug() << strQuery;
    if(query->exec(strQuery)){
        QSqlRecord rec = query->record();
        if(query->next()){//rec.indexOf("return_text")
            qDebug() << query->value(rec.indexOf("return_text")).toString();
            if(query->value(rec.indexOf("return_text")).toString() == "NORMAL"){
                emit this->signalUpdate();
            }
            return this->stringError(query->value(rec.indexOf("return_text")).toString());
        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CCrossing::dbAddCrossing)"));
        }
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CCrossing::dbAddCrossing)"));
    }
    return QObject::tr("ERROR->CCrossing::dbAddCrossing");
}

void CCrossing::slotDeleteCrossing(EPair pair, EPair to_pair)
{
    QString result = this->dbDeleteCrossing(pair,to_pair);
    qDebug() << result;
    this->signalReturnDeleteCrossing(result,to_pair);
}

QString CCrossing::dbDeleteCrossing(EPair pair, EPair to_pair)
{
    QString format = "CALL delete_crossing('%1','%2','%3','%4','%5','%6');";
    QString strQuery = format.arg(pair.getStrafe()).
                       arg(pair.getPlint()).
                       arg(pair.getPair()).
                       arg(to_pair.getStrafe()).
                       arg(to_pair.getPlint()).
                       arg(to_pair.getPair());
    //qDebug() << strQuery;
    if(query->exec(strQuery)){
        QSqlRecord rec = query->record();
        if(query->next()){//rec.indexOf("return_text")
            //qDebug() << query->value(rec.indexOf("return_text")).toString();
            if(query->value(rec.indexOf("return_text")).toString() == "NORMAL"){
                emit this->signalUpdate();
            }
            return this->stringError(query->value(rec.indexOf("return_text")).toString());
        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CCrossing::dbDeleteCrossing)"));
        }
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CCrossing::dbDeleteCrossing)"));
    }
    return QObject::tr("ERROR->CCrossing::dbDeleteCrossing");
}


