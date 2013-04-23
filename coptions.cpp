#include "coptions.h"

COptions::COptions(QObject *parent) :
    QObject(parent)
{
}

void COptions::slotLoadOptions()
{
    EOptions options;
    if(query->exec("CALL get_options();")){
        QSqlRecord rec = query->record();
        while(query->next()){
            if(query->value(rec.indexOf("nameOptions")).toString() == "strafe_count"){
                options.setStrafeCount(query->value(rec.indexOf("value")).toString());
            }
            if(query->value(rec.indexOf("nameOptions")).toString() == "plint_count"){
                options.setPlintCount(query->value(rec.indexOf("value")).toString());
            }
            if(query->value(rec.indexOf("nameOptions")).toString() == "pair_count"){
                options.setPairCount(query->value(rec.indexOf("value")).toString());
            }
            if(query->value(rec.indexOf("nameOptions")).toString() == "cross_name"){
                options.setCrossName(query->value(rec.indexOf("value")).toString());
            }
        }
        emit this->signalReturnOptions("NORMAL",options);
   }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(COptions::slotLoadOptions)"));
    };
}

QString COptions::stringError(QString bdError)
{
    if(bdError == "NORMAL"){
        return  "NORMAL";
    }
    if(bdError == "NAME_NOT_NULL"){
        return QObject::tr("Имя не может быть пустым");
    }
    if(bdError == "NOT_REPEAT"){
        return QObject::tr("Запись уже есть в базе");
    }
    if(bdError == "NOT_FOUND"){
        return QObject::tr("Запись в базе не найдена");
    }

    return QObject::tr("Неизвестный результат (COptions::stringError)");
}
