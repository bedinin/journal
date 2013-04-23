#ifndef ISTRAFEFACADE_H
#define ISTRAFEFACADE_H

#include <QWidget>
#include "ui_DesignerStrafeFacade.h"
#include "elistdirectorygroupname.h"
#include "ipairfacade.h"
#include "elistpair.h"

class IStrafeFacade : public QWidget, private Ui::designerStrafeFacade
{
    Q_OBJECT
private:
        //void clearTable();
        EListDirectoryGroupName list;
        QString strafe;

public:
    explicit IStrafeFacade(QWidget *parent = 0);
    void setName(QString val);
    QString getName();

signals:
        void signalGetListDirectoryGroupName();
        void signalGetStrafe();
        void signalEditPair(EPair);
        void signalError(QString);
private slots:
        void slotSelectMenu();
        void slotSelectItems(const QItemSelection,const QItemSelection);

public slots:
        void slotRun();
        void slotSetCount(int row, int col);
        void slotGetListDirectoryGroupName(EListDirectoryGroupName i_list);
        void slotGetStrafe();
        void slotReturnGetStrafe(EListPair i_list);
        void slotReturnEditPair(QString,EPair);
};

#endif // ISTRAFEFACADE_H
