#ifndef ILABELDIRECTORY_H
#define ILABELDIRECTORY_H

#include <QLabel>

class ILabelDirectory : public QLabel
{
    Q_OBJECT
private:
       QString id;
       QString name;
       QRgb rgb;
public:
    explicit ILabelDirectory(QWidget *parent = 0);
       QString getId();
       void setId(QString i_id);
       QString getName();
       void setName(QString i_name);
       void setColor(QRgb);
       QString getColor();
signals:

public slots:

};

#endif // ILABELDIRECTORY_H
