#ifndef EDIRECTORYGROUPNAME_H
#define EDIRECTORYGROUPNAME_H
#include <QtCore>
class EDirectoryGroupName
{
private:
        QString id;
        QString name;
        QString color;
        QString comment;
public:
    EDirectoryGroupName();
    void setId( QString i_id);
    void setName(QString i_name);
    void setColor(QString i_color);
    void setComment(QString i_comment);
    QString getId();
    QString getName();
    QString getColor();
    QString getComment();
};

#endif // EDIRECTORYGROUPNAME_H
