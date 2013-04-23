#ifndef IDIRECTORYGROUPNAME_H
#define IDIRECTORYGROUPNAME_H

#include <QWidget>
#include <QColorDialog>
#include "ui_designerDirectoryGroupName.h"
#include "elistdirectorygroupname.h"
#include "ilabeldirectory.h"

class IDirectoryGroupName : public QWidget, private Ui::designerGroupNameDirectory
{
    Q_OBJECT
private:
        void clearTable();
public:
    explicit IDirectoryGroupName(QWidget *parent = 0);

signals:
        void signalLoadAllDirectory();
        void signalLoadDirectory(QString id);
        void signalAddDirectory(EDirectoryGroupName directory);
        void signalDeleteDirectory(EDirectoryGroupName directory);
        void signalEditDirectory(EDirectoryGroupName directory);
private slots:
        void slotClearInput();
        void slotSelectColor();
        void slotAddDirectory();
        void slotSelectDirectory();
        void slotEditDirectory();
        void slotCancelDirectory();
        //void slotLoadAllDirectory();
        //void slotLoadDirectory();
        void slotDeleteDirectory();
public slots:
        void slotReturnLoadAllDirectory(EListDirectoryGroupName list);
        void slotRun();
        void slotReturnAddDirectory(QString result, EDirectoryGroupName directory);
        void slotReturnEditDirectory(QString result, EDirectoryGroupName directory);
        void slotReturnDeleteDirectory(QString);
        //void slotReturnLoadDirectory(EDirectoryGroupName directory);
        void slotError(QString);

};

#endif // IDIRECTORYGROUPNAME_H
