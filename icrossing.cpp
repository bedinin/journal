#include "icrossing.h"

ICrossing::ICrossing(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    QObject::connect(this->btAdd,SIGNAL(clicked()),this,SLOT(slotAddCrossing()));
    QObject::connect(this->btDelete,SIGNAL(clicked()),this,SLOT(slotDeleteCrossing()));
}

void ICrossing::setPair(EPair val)
{
    this->pair = val;
}

EPair ICrossing::getPair()
{
    return this->pair;
}

void ICrossing::slotClearInput()
{
    this->leStrafe->setText("");
    this->lePlint->setText("");
    this->lePair->setText("");
}

void ICrossing::slotAddCrossing()
{
    EPair toPair;
    toPair.setStrafe(this->leStrafe->text());
    toPair.setPlint(this->lePlint->text());
    toPair.setPair(this->lePair->text());
    emit this->signalAddCrossing(this->pair,toPair);
}

void ICrossing::slotDeleteCrossing()
{
    int row = this->table->currentRow();
    if(row>=0 && row<this->table->rowCount()){
        EPair to_pair;
        QLabel *lb = dynamic_cast<QLabel*>(this->table->cellWidget(row,0));
        to_pair.setStrafe(lb->text());
        lb = dynamic_cast<QLabel*>(this->table->cellWidget(row,1));
        to_pair.setPlint(lb->text());
        lb = dynamic_cast<QLabel*>(this->table->cellWidget(row,2));
        to_pair.setPair(lb->text());

        emit this->signalDeleteCrossing(this->pair,to_pair);
    }
}

void ICrossing::clearTable()
{
    for(int i = 0;i<this->table->rowCount();i++){
        this->table->removeRow(i);
    }
}

void ICrossing::slotReturnLoadCrossing(EListPair list)
{
    this->clearTable();
    this->table->setRowCount(list.rowCount());
    for(int i = 0; i<list.rowCount();i++){
        QLabel *lb;
        lb = new QLabel(this->table);
        lb->setText(list.getPair(i).getStrafe());
        this->table->setCellWidget(i,0,lb);
        lb = new QLabel(this->table);
        lb->setText(list.getPair(i).getPlint());
        this->table->setCellWidget(i,1,lb);
        lb = new QLabel(this->table);
        lb->setText(list.getPair(i).getPair());
        this->table->setCellWidget(i,2,lb);
    }
}

void ICrossing::slotRun()
{
    /*EPair tmp;
    tmp.setStrafe("0");
    tmp.setPlint("0");
    tmp.setPair("4");
    this->setPair(tmp);*/
    emit this->signalLoadCrossing(this->pair);
}

void ICrossing::slotReturnAddCrossing(QString result, EPair pair)
{
    if(result == "NORMAL"){
        int i = this->table->rowCount();
        this->table->setRowCount(i+1);
        QLabel *lb;
        lb = new QLabel(this->table);
        lb->setText(pair.getStrafe());
        this->table->setCellWidget(i,0,lb);
        lb = new QLabel(this->table);
        lb->setText(pair.getPlint());
        this->table->setCellWidget(i,1,lb);
        lb = new QLabel(this->table);
        lb->setText(pair.getPair());
        this->table->setCellWidget(i,2,lb);
    }else{
        QString format = "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:10pt; color:#ff0000;'>%1</span></p></body></html>";
        //this->lbError->setText();
        this->slotError(format.arg(result));
    }
}

void ICrossing::slotError(QString str)
{

}

void ICrossing::slotReturnDeleteCrossing(QString result, EPair to_pair)
{
    if(result == "NORMAL"){
        this->table->removeRow(this->findPair(to_pair));
        this->slotClearInput();
    }else{
        QString format = "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:10pt; color:#ff0000;'>%1</span></p></body></html>";
        //this->lbError->setText(format.arg(result));
        this->slotError(format.arg(result));
    }
}

int ICrossing::findPair(EPair findPair)
{
    QLabel *lb;
    QString strafe,plint,pair;
    for(int i = 0;i<this->table->rowCount();i++){
        lb=dynamic_cast<QLabel*>(this->table->cellWidget(i,0));
        strafe = lb->text();
        lb=dynamic_cast<QLabel*>(this->table->cellWidget(i,1));
        plint = lb->text();
        lb=dynamic_cast<QLabel*>(this->table->cellWidget(i,2));
        pair = lb->text();
        if((findPair.getStrafe()== strafe) && (findPair.getPlint() == plint) && findPair.getPair() == pair){
            return i;
        }
    }
    return -1;
}



