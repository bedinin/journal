#ifndef ICROSSING_H
#define ICROSSING_H

#include <QWidget>
#include <QLabel>
#include "elistpair.h"
#include "epair.h"
#include "ui_designericrossing.h"

class ICrossing : public QWidget, private Ui::DesignerICrossing
{
    Q_OBJECT
private:
    EPair pair;
public:
    explicit ICrossing(QWidget *parent = 0);
    void setPair(EPair val);
    EPair getPair();
private:
    void clearTable();
    int findPair(EPair findPair);
signals:
    void signalLoadCrossing(EPair pair);
    void signalAddCrossing(EPair pair,EPair to_pair);
    void signalDeleteCrossing(EPair pair,EPair to_pair);
private slots:
    void slotClearInput();
    //void slotSelectColor();
    void slotAddCrossing();
    //void slotSelectDirectory();
    void slotDeleteCrossing();

public slots:
    void slotReturnLoadCrossing(EListPair list);
    void slotRun();
    void slotReturnAddCrossing(QString result, EPair pair);
    void slotReturnDeleteCrossing(QString result, EPair to_pair);
    //void slotReturnLoadDirectory(EDirectoryGroupName directory);
    void slotError(QString str);

};

#endif // ICROSSING_H
