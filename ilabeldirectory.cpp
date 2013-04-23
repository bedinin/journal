#include "ilabeldirectory.h"

ILabelDirectory::ILabelDirectory(QWidget *parent) :
    QLabel(parent)
{
    this->id = "";
    this->name = "";
}

QString ILabelDirectory::getId()
{
    return this->id;
}

void ILabelDirectory::setId(QString i_id)
{
    this->id = i_id;
}

QString ILabelDirectory::getName()
{
    return this->name;
}

void ILabelDirectory::setName(QString i_name)
{
    this->name = i_name;
    this->setText(this->name);
}

void ILabelDirectory::setColor(QRgb i_rgb)
{
    this->rgb = i_rgb;
    QString formatColor = "ILabelDirectory { background-color: rgb(%1, %2, %3); }";
    this->setStyleSheet(formatColor.arg(QString::number(qRed(rgb))).
                                  arg(QString::number(qGreen(rgb))).
                        arg(QString::number(qBlue(rgb))));
}

QString ILabelDirectory::getColor()
{
    return QString::number(this->rgb);
}
