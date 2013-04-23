#ifndef ISTRAFE_H
#define ISTRAFE_H

#include <QWidget>
#include <QCheckBox>
#include "ui_DesignerStrafe.h"
#include "ipair.h"
#include <QColorDialog>
#include "elistdirectorygroupname.h"
#include "ipairfacade.h"
#include "elistpair.h"
#include "icrossing.h"
class IStrafe : public QWidget, private Ui::DesignerStrafe
{
    Q_OBJECT
private:
    QString strafe;
public:
    explicit IStrafe(QWidget *parent = 0);
    void setName(QString val);
    QString getName();
signals:
    void signalGetListDirectoryGroupName();
    void signalGetStrafe();
    void signalEditPair(EPair);
    void signalError(QString);
    void signalICrossingConnect(ICrossing *val);
private slots:
    //void slotSelectMenu();
    //void slotSelectItems(const QItemSelection,const QItemSelection);
    //void slotUpdate();
public slots:
    void slotSetPair(int r,int c, IPair *val);
    void slotSetName(QString name);
    void slotSetCount(int row, int col);
    //void slot
    void slotRun();
    void slotGetListDirectoryGroupName(EListDirectoryGroupName i_list);
    void slotGetStrafe();
    void slotReturnGetStrafe(EListPair i_list);
    void slotReturnEditPair(QString,EPair);
};

#endif // ISTRAFE_H
