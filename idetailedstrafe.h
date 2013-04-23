#ifndef IDETAILEDSTRAFE_H
#define IDETAILEDSTRAFE_H

#include <QWidget>
//#include "ui_DesignerFacade.h"
#include "ui_designerDetailedStrafe.h"

class IDetailedStrafe : public QWidget, private Ui::designerDetailedStrafe
{
    Q_OBJECT
private:
    int count;
public:
    explicit IDetailedStrafe(QWidget *parent = 0);
    void addWidget(QWidget *wdg);

signals:
public slots:
};

#endif // IDETAILEDSTRAFE_H
