#ifndef ISHOWERROR_H
#define ISHOWERROR_H

#include <QWidget>
#include "ui_DesignerShowError.h"

class IShowError : public QWidget, private Ui::DesignerShowError
{
    Q_OBJECT
public:
    explicit IShowError(QWidget *parent = 0);

signals:

public slots:
        void slotShowError(QString);
};

#endif // ISHOWERROR_H
