#include "ishowerror.h"

IShowError::IShowError(QWidget *parent) :
    QWidget(parent)
{
    //QWidget *dlg = new QWidget(parent);
    this->setupUi(this);
};

void IShowError::slotShowError(QString str)
{
    QString format="<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.0//EN' 'http://www.w3.org/TR/REC-html40/strict.dtd'>\n<html><head><meta name='qrichtext' content='1' /><style type='text/css'>\np, li { white-space: pre-wrap; }\n</style></head><body style=' font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;'>\n<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><span style=' font-size:10pt; color:#aa0000;'>%1</span></p></body></html>";
    this->lbText->setText(format.arg(str));
    this->leError->setText(this->leError->text()+"; "+str);
    this->show();
};
