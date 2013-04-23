#include "cdirectorygroupname.h"

CDirectoryGroupName::CDirectoryGroupName(QObject *parent) :
    QObject(parent)
{
}

QString CDirectoryGroupName::stringError(QString bdError)
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

    return QObject::tr("Неизвестный результат (CDirectoryGroupName::stringError)");
}

void CDirectoryGroupName::slotLoadAllDirectory()
{
    //emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotAddDirectory)"));
    EListDirectoryGroupName list;
    if(query->exec("CALL get_all_group_name();")){
        QSqlRecord rec = query->record();
        while(query->next()){
                EDirectoryGroupName record;
                record.setId(query->value(rec.indexOf("id")).toString());
                record.setName(query->value(rec.indexOf("name")).toString());
                record.setColor(query->value(rec.indexOf("color")).toString());
                record.setComment(query->value(rec.indexOf("comment")).toString());
                list.addDirectory(record);
        }
        emit this->signalReturnLoadAllDirectory(list);
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotAddDirectory)"));
    };
};

void CDirectoryGroupName::slotAddDirectory(EDirectoryGroupName directory)
{
    QString format = "CALL add_group_name('%1', '%2', '%3');";
    if(query->exec(format.arg(directory.getName()).arg(directory.getColor()).arg(directory.getComment()))){

        QSqlRecord rec = query->record();
        if(query->next()){
            //QString result = this->stringError(query->value(rec.indexOf("return_text")).toString());
            directory.setId(query->value(rec.indexOf("return_id")).toString());
            emit this->signalReturnAddDirectory(this->stringError(query->value(rec.indexOf("return_text")).toString()),
                                          directory);

        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotAddDirectory)"));
        }
    }else{
       emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotAddDirectory)"));
    }
}

void CDirectoryGroupName::slotDeleteDirectory(EDirectoryGroupName directory)
{
    QString format = "CALL delete_group_name(%1);";

    if(query->exec(format.arg(directory.getId()))){

        QSqlRecord rec = query->record();
        if(query->next()){
            //QString result = this->stringError(query->value(rec.indexOf("return_text")).toString());
            emit this->signalReturnDeleteDirectory(this->stringError(query->value(rec.indexOf("return_text")).toString()));
        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotDeleteDirectory)"));
        }
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotDeleteDirectory)"));
    }
}

void CDirectoryGroupName::slotEditDirectory(EDirectoryGroupName directory)
{
    QString format = "CALL set_group_name(%1, '%2', '%3','%4');";
    QString strQuery = format.arg(directory.getId()).arg(directory.getName()).arg(directory.getColor()).arg(directory.getComment());
    //emit this->signalError(strQuery);
    if(query->exec(strQuery)){
        //emit this->signalError("2");
        QSqlRecord rec = query->record();
        if(query->next()){
            //emit this->signalError("3");
            //emit this->signalError(format.arg(directory.getId()).arg(directory.getName()).arg(directory.getColor()).arg(directory.getComment()));

            //QString result = this->stringError(query->value(rec.indexOf("return_text")).toString());
            //directory.setId(query->value(rec.indexOf("return_id")).toString());
            emit this->signalReturnEditDirectory(this->stringError(query->value(rec.indexOf("return_text")).toString()),
                                          directory);
        }else{
            emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotEditDirectory)"));
        }
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotEditDirectory)"));
    }
}

void CDirectoryGroupName::slotLoadDirectory(QString id)
{
    QString format = "CALL get_group_name('%1');";
    EDirectoryGroupName record;;
    if(query->exec(format.arg(id))){
        QSqlRecord rec = query->record();
        if(query->next()){

                record.setId(query->value(rec.indexOf("id")).toString());
                record.setName(query->value(rec.indexOf("name")).toString());
                record.setColor(query->value(rec.indexOf("color")).toString());
                record.setComment(query->value(rec.indexOf("comment")).toString());
        }
        emit this->signalReturnLoadDirectory(record);
    }else{
        emit this->signalError(QObject::tr("Ошибка базы данных(CDirectoryGroupName::slotLoadDirectory)"));
    };
}

