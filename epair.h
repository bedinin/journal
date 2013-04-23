#ifndef EPAIR_H
#define EPAIR_H
#include <QtCore>

class EPair
{
private:
    QString id,
            strafe,
            plint,
            pair,
            flag_value,
            value,
            ext_id,
            plint_name_id,
            group_id,
            comment;
public:
    EPair(); //что то
    QString getID();
    QString getStrafe();
    QString getPlint();
    QString getPair();
    QString getFlag_value();
    QString getValue();
    QString getExt_id();
    QString getPlint_name_id();
    QString getComment();
    QString getGroup_id();
    void setID(QString val);
    void setStrafe(QString val);
    void setPlint(QString val);
    void setPair(QString val);
    void setFlag_value(QString val);
    void setValue(QString val);
    void setExt_id(QString val);
    void setPlint_name_id(QString val);
    void setComment(QString val);
    void setGroup_id(QString val);
    //EPair& operator =(EPair&);
signals:

public slots:

};

#endif // EPAIR_H
