#include "idirectorygroupname.h"

IDirectoryGroupName::IDirectoryGroupName(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    this->slotClearInput();
    QObject::connect(this->btColorSelect,SIGNAL(clicked()),
                     this,SLOT(slotSelectColor()));

    QObject::connect(this->btAdd,SIGNAL(clicked()),
                     this,SLOT(slotAddDirectory()));

    QObject::connect(this->table,SIGNAL(itemSelectionChanged()),
                     this,SLOT(slotSelectDirectory()));

    QObject::connect(this->btSave,SIGNAL(clicked()),
                     this,SLOT(slotEditDirectory()));

    QObject::connect(this->btDelete,SIGNAL(clicked()),
                     this,SLOT(slotDeleteDirectory()));

    QObject::connect(this->btCancel,SIGNAL(clicked()),
                     this,SLOT(slotCancelDirectory()));
}

void IDirectoryGroupName::slotSelectColor()
{
    QPalette pl = this->leColor->palette();
    QColor color = pl.color(QPalette::Base);
    color = QColorDialog::getColor(color,this);
    pl.setColor(QPalette::Base,color);
    this->leColor->setPalette(pl);
}

void IDirectoryGroupName::slotReturnLoadAllDirectory(EListDirectoryGroupName list)
{
    this->clearTable();
    this->table->setRowCount(list.rowCount());
    for(int i = 0; i<list.rowCount();i++){
        ILabelDirectory *lb = new ILabelDirectory(this);
            lb->setId(list.getDirectory(i).getId());
            lb->setName(list.getDirectory(i).getName());
        this->table->setCellWidget(i,0,lb);
        lb = new ILabelDirectory(this);
            lb->setId(list.getDirectory(i).getId());
            lb->setColor(list.getDirectory(i).getColor().toUInt());
        this->table->setCellWidget(i,1,lb);
        lb = new ILabelDirectory(this);
            lb->setId(list.getDirectory(i).getId());
            lb->setName(list.getDirectory(i).getComment());
        this->table->setCellWidget(i,2,lb);
    }
}

void IDirectoryGroupName::slotRun()
{
    emit this->signalLoadAllDirectory();
}

void IDirectoryGroupName::slotAddDirectory()
{
    EDirectoryGroupName directory;
    directory.setName(this->leName->text());
    directory.setColor(QString::number(this->leColor->palette().color(QPalette::Base).rgb()));
    directory.setComment(this->teComment->toPlainText());
    emit this->signalAddDirectory(directory);
}

void IDirectoryGroupName::slotReturnAddDirectory(QString result, EDirectoryGroupName directory)
{
    if(result == "NORMAL"){
        int i = this->table->rowCount();
        this->table->setRowCount(i+1);
        ILabelDirectory *lb = new ILabelDirectory(this);
            lb->setId(directory.getId());
            lb->setName(directory.getName());
        this->table->setCellWidget(i,0,lb);
        lb = new ILabelDirectory(this);
            lb->setId(directory.getId());
            lb->setColor(directory.getColor().toUInt());
        this->table->setCellWidget(i,1,lb);
        lb = new ILabelDirectory(this);
            lb->setId(directory.getId());
            lb->setName(directory.getComment());
        this->table->setCellWidget(i,2,lb);
        this->slotClearInput();
    }else{
        QString format = "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:10pt; color:#ff0000;'>%1</span></p></body></html>";
        //this->lbError->setText();
        this->slotError(format.arg(result));
    }
}

void IDirectoryGroupName::slotClearInput()
{
    this->table->clearSelection();
    this->leName->setText("");
    this->teComment->setText("");
    QPalette pl;
    pl.setColor(QPalette::Base,QColor(255,255,255));
    this->leColor->setPalette(pl);
    this->btSave->setEnabled(false);
    this->btDelete->setEnabled(false);
    this->btCancel->setEnabled(false);
    this->btAdd->setEnabled(true);
    this->slotError("");
}

void IDirectoryGroupName::slotSelectDirectory()
{
    int row = this->table->currentRow();
    if(row >= 0 && row < this->table->rowCount()){
        this->btSave->setEnabled(true);
        this->btDelete->setEnabled(true);
        this->btCancel->setEnabled(true);
        this->btAdd->setEnabled(false);
        this->leName->setText((dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,0)))->getName());
        this->teComment->setText((dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,2)))->getName());
        QPalette pl = (dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,1)))->palette();
        this->leColor->setPalette(pl);
    }
}

void IDirectoryGroupName::slotEditDirectory()
{
    int row = this->table->currentRow();
    EDirectoryGroupName directory;
    directory.setId((dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,0)))->getId());
    directory.setName(this->leName->text());
    directory.setColor(QString::number(this->leColor->palette().color(QPalette::Base).rgb()));
    directory.setComment(this->teComment->toPlainText());
    emit this->signalEditDirectory(directory);
}

void IDirectoryGroupName::slotReturnEditDirectory(QString result, EDirectoryGroupName directory)
{
    if(result == "NORMAL"){
        int row = this->table->currentRow();
        //ILabelDirectory *lb;
        (dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,0)))->setName(directory.getName());
        (dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,1)))->setColor(directory.getColor().toUInt());
        (dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,2)))->setName(directory.getComment());
        this->slotClearInput();
    }else{
        QString format = "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:10pt; color:#ff0000;'>%1</span></p></body></html>";
        //this->lbError->setText(format.arg(result));
        this->slotError(format.arg(result));
    }
}

void IDirectoryGroupName::slotError(QString i_error)
{
    this->lbError->setText(i_error);
    //this->leName->setText(i_error);
}

void IDirectoryGroupName::slotDeleteDirectory()
{
    int row = this->table->currentRow();
    EDirectoryGroupName directory;
    directory.setId((dynamic_cast<ILabelDirectory*>(this->table->cellWidget(row,0)))->getId());
    directory.setName(this->leName->text());
    directory.setColor(QString::number(this->leColor->palette().color(QPalette::Base).rgb()));
    directory.setComment(this->teComment->toPlainText());
    emit this->signalDeleteDirectory(directory);
}

void IDirectoryGroupName::slotReturnDeleteDirectory(QString result)
{
    if(result == "NORMAL"){
        this->table->removeRow(this->table->currentRow());
        this->slotClearInput();
    }else{
        QString format = "<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:10pt; color:#ff0000;'>%1</span></p></body></html>";
        //this->lbError->setText(format.arg(result));
        this->slotError(format.arg(result));
    }
}

void IDirectoryGroupName::clearTable()
{
    for(int i = 0;i<this->table->rowCount();i++){
        this->table->removeRow(i);
    }
}

void IDirectoryGroupName::slotCancelDirectory()
{
    this->slotClearInput();
}


