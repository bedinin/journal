/********************************************************************************
** Form generated from reading UI file 'DesignerShowError.ui'
**
** Created: Thu 3. Jan 16:19:08 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERSHOWERROR_H
#define UI_DESIGNERSHOWERROR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesignerShowError
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbText;
    QLineEdit *leError;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btOK;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DesignerShowError)
    {
        if (DesignerShowError->objectName().isEmpty())
            DesignerShowError->setObjectName(QString::fromUtf8("DesignerShowError"));
        DesignerShowError->setWindowModality(Qt::WindowModal);
        DesignerShowError->resize(410, 180);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DesignerShowError->sizePolicy().hasHeightForWidth());
        DesignerShowError->setSizePolicy(sizePolicy);
        DesignerShowError->setMinimumSize(QSize(410, 180));
        DesignerShowError->setMaximumSize(QSize(410, 180));
        verticalLayout = new QVBoxLayout(DesignerShowError);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbText = new QLabel(DesignerShowError);
        lbText->setObjectName(QString::fromUtf8("lbText"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbText->sizePolicy().hasHeightForWidth());
        lbText->setSizePolicy(sizePolicy1);
        lbText->setMinimumSize(QSize(392, 78));
        lbText->setMaximumSize(QSize(16777215, 16777215));
        lbText->setLineWidth(1);
        lbText->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(lbText);

        leError = new QLineEdit(DesignerShowError);
        leError->setObjectName(QString::fromUtf8("leError"));

        verticalLayout->addWidget(leError);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btOK = new QPushButton(DesignerShowError);
        btOK->setObjectName(QString::fromUtf8("btOK"));

        horizontalLayout->addWidget(btOK);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DesignerShowError);
        QObject::connect(btOK, SIGNAL(clicked()), DesignerShowError, SLOT(close()));

        QMetaObject::connectSlotsByName(DesignerShowError);
    } // setupUi

    void retranslateUi(QWidget *DesignerShowError)
    {
        DesignerShowError->setWindowTitle(QApplication::translate("DesignerShowError", "Error", 0, QApplication::UnicodeUTF8));
        lbText->setText(QApplication::translate("DesignerShowError", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#aa0000;\">TextLabel</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btOK->setText(QApplication::translate("DesignerShowError", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesignerShowError: public Ui_DesignerShowError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERSHOWERROR_H
