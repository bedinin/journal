#ifndef EOPTIONS_H
#define EOPTIONS_H

#include <QtCore>
class EOptions
{
private:
    QString strafe_count,
            plint_count,
            pair_count,
            cross_name;
public:
    EOptions();
    void setStrafeCount(QString name);
    void setPlintCount(QString name);
    void setPairCount(QString name);
    void setCrossName(QString name);

    QString getStrafeCount();
    QString getPlintCount();
    QString getPairCount();
    QString getCrossName();
};

#endif // EOPTIONS_H
