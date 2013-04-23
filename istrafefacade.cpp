#include "istrafefacade.h"

IStrafeFacade::IStrafeFacade(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    this->setName("");
    QObject::connect(this->table->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(slotSelectItems(QItemSelection,QItemSelection)));

}

void IStrafeFacade::slotSetCount(int row, int col)
{
    if(col > 0){
        this->table->setColumnCount(col);
    }else{
        col = 0;
        this->table->setColumnCount(col);
    }
    if(row > 0){
        this->table->setRowCount(row);
    }else{
        row = 0;
        this->table->setRowCount(row);
    }
    for(int x = 0;x<row;x++){
        for(int y = 0; y<col;y++){
            this->table->setCellWidget(x,y,new IPairFacade(this->table));
        }
    }
    this->setMinimumWidth(40+col*21);
    this->setMinimumHeight(70+row*30);
    QStringList list;
    for(int i = 0;i<row;i++){
        list << QString::number(i);
    }
    this->table->setHorizontalHeaderLabels(list);
    list.clear();
    for(int i = 0;i<col;i++){
        list << QString::number(i);
    }
    this->table->setVerticalHeaderLabels(list);
    //this->lbSrafeName->setText(QString::number(this->minimumHeight()));
}

void IStrafeFacade::slotGetListDirectoryGroupName(EListDirectoryGroupName i_list)
{
    list = i_list;
    QList<QAction*> actList = this->table->actions();
    for(int i = 0;i<actList.count();i++){
       this->table->removeAction(actList.at(i));
    }
    for(int i = 0;i<list.rowCount();i++){
        QAction *act = new QAction(list.getDirectory(i).getName(),this->table);
        QObject::connect(act,SIGNAL(triggered()),this,SLOT(slotSelectMenu()));
        this->table->addAction(act);
    }
    /*
    this->table->addAction(new QAction(QObject::tr("sad1"),this->table));
    this->table->addAction(new QAction(QObject::tr("sad2"),this->table));*/
    this->table->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void IStrafeFacade::slotSelectMenu()
{
    QAction *act = dynamic_cast<QAction*>(sender());
    if(this->table->selectedRanges().count() > 0){
        QTableWidgetSelectionRange selected = this->table->selectedRanges().at(0);
        for(int i = selected.topRow(); i<=selected.bottomRow();i++){
            for(int j=selected.leftColumn();j<=selected.rightColumn();j++){
                IPairFacade *pair = dynamic_cast<IPairFacade*>(this->table->cellWidget(i,j));
                pair->setGroupName(this->list.getDirectory(act->text()));
                this->signalEditPair(pair->getPair());
            }
        }
    }
}

void IStrafeFacade::slotRun()
{
    emit this->signalGetListDirectoryGroupName();
}

void IStrafeFacade::slotGetStrafe()
{
    if(this->strafe != ""){
        emit this->signalGetStrafe();
    }
    else{
        qDebug() << "IStrafeFacade::slotGetStrafe >> " << "this->strafe == ''";
    }
}

void IStrafeFacade::slotReturnGetStrafe(EListPair i_list)
{    
    if(i_list.getStrafe() == this->strafe){
    emit this->signalError(i_list.getStrafe());
    EPair val;
    this->slotSetCount(i_list.getPlintCount(),i_list.getPairCount());
    this->lbSrafeName->setText(QObject::tr("Стрейф: ")+i_list.getStrafe());
    //this->lbSrafeName->setText(QString::number(i_list.rowCount()));
    for(int i = 0; i< i_list.rowCount();i++){
        val = i_list.getPair(i);
        int row = val.getPlint().toInt(),
            col = val.getPair().toInt();
        if(row>=0 && row<this->table->rowCount() && col>=0 && col<this->table->columnCount()){
            IPairFacade *pair = dynamic_cast<IPairFacade*>(this->table->cellWidget(row,col));
            pair->setGroupName(this->list.getDirectoryID(val.getGroup_id()));
            pair->setPair(val);
        }

    }
    }
}

void IStrafeFacade::slotSelectItems(const QItemSelection selection, const QItemSelection deselection)
{
    if(this->table->selectedRanges().count() > 0){

        QTableWidgetSelectionRange sel = this->table->selectedRanges().at(0);
        for(int i = 0; i<this->table->rowCount();i++){
            for(int j=0;j<this->table->columnCount();j++){
                IPairFacade *pair = dynamic_cast<IPairFacade*>(this->table->cellWidget(i,j));

                if(i>=sel.topRow() && i<=sel.bottomRow() && j>=sel.leftColumn() && j<=sel.rightColumn()){
                    pair->slotSelected(true);
                }
                else{
                    pair->slotSelected(false);
                }
            }
        }
    }
    else{
        for(int i = 0; i<this->table->rowCount();i++){
            for(int j=0;j<this->table->columnCount();j++){
                IPairFacade *pair = dynamic_cast<IPairFacade*>(this->table->cellWidget(i,j));
                pair->slotSelected(false);
            }
       }
    }
}

void IStrafeFacade::slotReturnEditPair(QString result,EPair pair)
{

}

void IStrafeFacade::setName(QString val)
{
    this->strafe = val;
}

QString IStrafeFacade::getName()
{
    return this->strafe;
}
