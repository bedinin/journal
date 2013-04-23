#ifndef COPTIONS_H
#define COPTIONS_H

#include <QObject>
#include "global.h"
#include "cmysqlconnect.h"
#include "eoptions.h"
class COptions : public QObject
{
    Q_OBJECT
private:
    QString stringError(QString bdError);
public:
    explicit COptions(QObject *parent = 0);

signals:
    void signalError(QString);
    void signalReturnOptions(QString,EOptions);
public slots:
    void slotLoadOptions();
};

#endif // COPTIONS_H
