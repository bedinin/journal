#include "istrafe.h"

IStrafe::IStrafe(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    this->lbSrafeName->setText("Plint");
    QString formatColor = QString("IPairFacade { ")+
                          //QString("selection-background-color: rgb(0, 0, 0);}")+
                          //QString("webkit-transform: rotate(90deg);")+
                          QString("transform: rotate(90deg);}");
    this->setName("");
    this->lbSrafeName->setStyleSheet(formatColor);
}

void IStrafe::slotSetPair(int r, int c,  IPair *val)
{
/*    if(val != NULL && r >= 0 && c >= 0){
        val->setParent(this);
        if(this->tableWidget->columnCount() <= c){
            this->tableWidget->setColumnCount(c+1);
        }
        if(this->tableWidget->rowCount() <= r){
            this->tableWidget->setRowCount(r+1);
        }
        this->tableWidget->setCellWidget(r,c,val);
    }
    */
}

void IStrafe::slotSetName(QString name)
{
    QString format = "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:16pt; font-weight:600; color:#aa0000;'>%1</span></p></body></html>";
    //this->lbName->setText(format.arg("Strafe: "+name));
}

void IStrafe::slotSetCount(int row, int col)
{
    int intCountParam = 7;
    this->table->setColumnCount(intCountParam);
    if(row * col > 0){
        this->table->setRowCount(row*col);
    }else{
        this->table->setRowCount(0);
    }
    //Заголовок
    QStringList list;
    list << QObject::tr("Плинт") <<
            QObject::tr("Пара") <<
            QObject::tr("Значение") <<
            QObject::tr("Тип") <<
            QObject::tr("Кроссировка")  <<
            QObject::tr("ДопИнф")  <<
            QObject::tr("Примечание");
    this->table->setHorizontalHeaderLabels(list);
    this->table->setColumnWidth(0,50);
    for(int i=1;i<7;i++)
        this->table->setColumnWidth(i,20);
    this->table->setColumnWidth(4,180);
    for(int x = 0;x<row*col;x++){
        if((x%(col))==0){ //На каждом intCountParam шаге объеденяем ячейки и записываем номер плинта
            //qDebug() << "(x%(col) = " << (x%(col));// <<
           // qDebug() << "x = " << x ;
            this->table->setSpan(x,0,col,1);
            QTableWidgetItem *item=new QTableWidgetItem();this->table->item(x,0);
            item->setText(QString::number(x/col));
            item->setTextAlignment(Qt::AlignCenter);
            this->table->setItem(x,0,item);
        }        
        this->table->setRowHeight(x,150);

        //Номер пары
        QLabel *lb = new QLabel(this->table);
        lb->setText(QString::number(x%col));
        this->table->setCellWidget(x,1,lb);
        //Значение
        lb = new QLabel(this->table);
        this->table->setCellWidget(x,2,lb);
        //Тип пары
        QCheckBox *chb = new QCheckBox(this->table);
        chb->setChecked(false);
        this->table->setCellWidget(x,3,chb);
        //Кроссировка
        ICrossing *crossing = new ICrossing(this->table);
        emit this->signalICrossingConnect(crossing);
        this->table->setCellWidget(x,4,crossing);
        //ДопИнф
        lb = new QLabel(this->table);
        this->table->setCellWidget(x,5,lb);
        //Примечание
        lb = new QLabel(this->table);
        this->table->setCellWidget(x,6,lb);
    }
}

void IStrafe::slotReturnEditPair(QString, EPair)
{
}

void IStrafe::slotReturnGetStrafe(EListPair i_list)
{
    if(i_list.getStrafe() == this->strafe){
        emit this->signalError(i_list.getStrafe());
        EPair val;
        this->slotSetCount(i_list.getPlintCount(),i_list.getPairCount());
        this->lbSrafeName->setText(QObject::tr("Стрейф: ")+i_list.getStrafe());
        //qDebug() << "i_list.rowCount() = " << i_list.rowCount();
        for(int i = 0; i< i_list.rowCount();i++){
            val = i_list.getPair(i);
            int row = val.getPlint().toInt(),
            col = val.getPair().toInt();
            //qDebug() << "val.getPair() = " << val.getPair();
            QLabel *pair;
            QCheckBox *chk;
            ICrossing *crossing;
            pair = dynamic_cast<QLabel*>(this->table->cellWidget(i,2));
            pair->setText(i_list.getPair(i).getValue());
            chk = dynamic_cast<QCheckBox*>(this->table->cellWidget(i,3));
            chk->setChecked(i_list.getPair(i).getFlag_value().toInt());
            crossing = dynamic_cast<ICrossing*>(this->table->cellWidget(i,4));
            crossing->setPair(val);
            crossing->slotRun();
            pair = dynamic_cast<QLabel*>(this->table->cellWidget(i,6));
            pair->setText(i_list.getPair(i).getComment());

        }
    }
}

void IStrafe::slotGetStrafe()
{
    emit this->signalGetStrafe();
}

void IStrafe::slotGetListDirectoryGroupName(EListDirectoryGroupName i_list)
{
}
//void slotSetCount(int row, int col);

void IStrafe::slotRun()
{
}

void IStrafe::setName(QString val)
{
    this->strafe = val;
}

QString IStrafe::getName()
{
    return this->strafe;
}


