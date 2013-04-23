#ifndef IFACADE_H
#define IFACADE_H

#include <QWidget>
#include "ui_DesignerFacade.h"

class IFacade : public QWidget, private Ui::DesignerFacade
{
    Q_OBJECT
private:
    int count;
public:
    explicit IFacade(QWidget *parent = 0);
    void addWidget(QWidget *wdg);
signals:
public slots:

};

#endif // IFACADE_H
