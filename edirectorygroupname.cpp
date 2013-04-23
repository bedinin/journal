#include "edirectorygroupname.h"

EDirectoryGroupName::EDirectoryGroupName()
{
    this->id = "";
    this->name = "";
    this->color = "";
    this->comment = "";
}

void EDirectoryGroupName::setId(QString i_id)
{
    this->id = i_id;
}

void EDirectoryGroupName::setName(QString i_name)
{
    this->name = i_name;
}

void EDirectoryGroupName::setColor(QString i_color)
{
    this->color = i_color;
}

void EDirectoryGroupName::setComment(QString i_comment)
{
    this->comment = i_comment;
}

QString EDirectoryGroupName::getId()
{
    return this->id;
}

QString EDirectoryGroupName::getName()
{
    return this->name;
}

QString EDirectoryGroupName::getColor()
{
    return this->color;
}

QString EDirectoryGroupName::getComment()
{
    return this->comment;
}
