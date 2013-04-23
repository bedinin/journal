#include "cstrafe.h"

CStrafe::CStrafe(QObject *parent) :
    QObject(parent){
    this->setName("");
}

void CStrafe::slotLoadStrafe()
{
    QString format = "CALL get_data('%1');";
    EListPair listPair;
    listPair.setStrafe(this->getName());
    listPair.setPairCount(this->options.getPairCount().toInt());
    listPair.setPlintCount(this->options.getPlintCount().toInt());
    //qDebug() << format.arg(this->getName());
    if(query->exec(format.arg(this->getName()))){
        QSqlRecord rec = query->record();
        while(query->next()){
            EPair pair;
            pair.setID(query->value(rec.indexOf("id")).toString());                         //id
            pair.setStrafe(query->value(rec.indexOf("strafe")).toString());                 //strafe
            pair.setPlint(query->value(rec.indexOf("plint")).toString());                   //plint
            pair.setPair(query->value(rec.indexOf("pair")).toString());                     //pair
            pair.setFlag_value(query->value(rec.indexOf("flag_value")).toString());         //flag_value
            pair.setValue(query->value(rec.indexOf("value")).toString());                   //value
            pair.setExt_id(query->value(rec.indexOf("ext_id")).toString());                 //ext_id
            pair.setPlint_name_id(query->value(rec.indexOf("plint_name_id")).toString());   //plint_name_id
            pair.setGroup_id(query->value(rec.indexOf("group_id")).toString());             //group_id
            pair.setComment(query->value(rec.indexOf("comment")).toString());               //comment
            listPair.addPair(pair);
        }
        emit this->signalReturnLoadStrafe(listPair);
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CStrafe::slotLoadStrafe)"));
    };
    //emit this->signalReturnLoadStrafe(this->list.getStrafe(index));
}

/*int CStrafe::dbLoadStrafe(QString id)
{
    QString format = "CALL get_data('%1');";
    EListPair listPair;
    listPair.setStrafe(id);
    listPair.setPairCount(this->options.getPairCount().toInt());
    listPair.setPlintCount(this->options.getPlintCount().toInt());
    if(query->exec(format.arg(id))){
        QSqlRecord rec = query->record();
        while(query->next()){
            EPair pair;
            pair.setID(query->value(rec.indexOf("id")).toString());                         //id
            pair.setStrafe(query->value(rec.indexOf("strafe")).toString());                 //strafe
            pair.setPlint(query->value(rec.indexOf("plint")).toString());                   //plint
            pair.setPair(query->value(rec.indexOf("pair")).toString());                     //pair
            pair.setFlag_value(query->value(rec.indexOf("flag_value")).toString());         //flag_value
            pair.setValue(query->value(rec.indexOf("value")).toString());                   //value
            pair.setExt_id(query->value(rec.indexOf("ext_id")).toString());                 //ext_id
            pair.setPlint_name_id(query->value(rec.indexOf("plint_name_id")).toString());   //plint_name_id
            pair.setGroup_id(query->value(rec.indexOf("group_id")).toString());             //group_id
            pair.setComment(query->value(rec.indexOf("comment")).toString());               //comment
            listPair.addPair(pair);
        }
        this->list.addStrafe(listPair);
        return this->getIndexStrafe(id);
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CStrafe::bdLoadStrafe)"));
        return (int)-1;
    };
}*/

void CStrafe::slotEditPair(EPair pair)
{
    QString format = "CALL set_data(%1, %2, %3, %4, %5, '%6', %7, %8, %9, %10, %11, %12, %13, '%14');";
    /*
IN i_id INT,                1
IN i_strafe INT,            2
IN i_plint INT,             3
IN i_pair INT,              4
IN i_flag_value BOOL,       5
IN i_value TEXT,            6
IN i_ext_id INT,            7
IN i_journal BOOL,          8
IN i_post_id INT,           9
IN i_department_id INT,     10
IN i_address_id INT,        11
IN i_plint_name_id INT,     12
IN i_group_id INT,          13
IN i_comment TEXT           14
*/
    QString strQuery = format.arg(pair.getID()).
                       arg(pair.getStrafe()).
                       arg(pair.getPlint()).
                       arg(pair.getPair()).
                       arg(pair.getFlag_value()).
                       arg(pair.getValue()).
                       arg(pair.getExt_id()).
                       arg("0").
                       arg("0").
                       arg("0").
                       arg("0").
                       arg(pair.getPlint_name_id()).
                       arg(pair.getGroup_id()).
                       arg(pair.getComment());

    if(query->exec(strQuery)){
        QSqlRecord rec = query->record();
        if(query->next()){
            QString result = this->stringError(query->value(rec.indexOf("return_text")).toString());
            emit this->signalReturnEditPair(result,pair);
        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CStrafe::slotEditPair)"));
        }
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CStrafe::slotEditPair)"));
    }
    emit this->signalError(QObject::tr("ERROR CStrafe::slotEditPair"));



/*    int indexStrafe = this->getIndexStrafe(pair.getStrafe());
    QString result = this->dbEditPair(pair);
    if(indexStrafe != -1){
        if(result == "NORMAL"){
            this->list.getStrafe(indexStrafe).setPair(pair);
        }
    }*/
};
/*
QString CStrafe::dbEditPair(EPair pair)
{
    QString format = "CALL set_data(%1, %2, %3, %4, %5, '%6', %7, %8, %9, %10, %11, %12, %13, '%14');";
    /*
IN i_id INT,                1
IN i_strafe INT,            2
IN i_plint INT,             3
IN i_pair INT,              4
IN i_flag_value BOOL,       5
IN i_value TEXT,            6
IN i_ext_id INT,            7
IN i_journal BOOL,          8
IN i_post_id INT,           9
IN i_department_id INT,     10
IN i_address_id INT,        11
IN i_plint_name_id INT,     12
IN i_group_id INT,          13
IN i_comment TEXT           14
*/
/*    QString strQuery = format.arg(pair.getID()).
                       arg(pair.getStrafe()).
                       arg(pair.getPlint()).
                       arg(pair.getPair()).
                       arg(pair.getFlag_value()).
                       arg(pair.getValue()).
                       arg(pair.getExt_id()).
                       arg("0").
                       arg("0").
                       arg("0").
                       arg("0").
                       arg(pair.getPlint_name_id()).
                       arg(pair.getGroup_id()).
                       arg(pair.getComment());

    if(query->exec(strQuery)){
        QSqlRecord rec = query->record();
        if(query->next()){
            return query->value(rec.indexOf("return_text")).toString();
        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CStrafe::dbEditPair)"));
        }
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CStrafe::dbEditPair)"));
    }
    return QObject::tr("ERROR");
};*/

QString CStrafe::stringError(QString dbError)
{
    if(dbError == "NORMAL"){
        return  "NORMAL";
    }
    if(dbError == "NOT_REPEAT"){
        return QObject::tr("Запись уже есть в базе");
    }
    if(dbError == "NOT_FOUND"){
        return QObject::tr("Запись в базе не найдена");
    }

    return QObject::tr("Неизвестный результат (CStrafe::stringError)");
}

void CStrafe::slotReturnOptions(QString i_return,EOptions val)
{
    if(i_return == "NORMAL"){
        this->options = val;
    }
}

void CStrafe::slotRun()
{
    emit this->signalGetOptions();
}

//Связать с COptions
/*void CStrafe::slotGetStrafeCount()
{
    emit this->signalReturnStrafeCount(this->options.getStrafeCount().toInt());
}*/

void CStrafe::setName(QString val)
{
    this->strafe = val;
}

QString CStrafe::getName()
{
    return this->strafe;
}
