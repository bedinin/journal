/********************************************************************************
** Form generated from reading UI file 'DesignerPair.ui'
**
** Created: Sun 9. Dec 21:06:07 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERPAIR_H
#define UI_DESIGNERPAIR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesignerPair
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbText;

    void setupUi(QWidget *DesignerPair)
    {
        if (DesignerPair->objectName().isEmpty())
            DesignerPair->setObjectName(QString::fromUtf8("DesignerPair"));
        DesignerPair->resize(174, 85);
        verticalLayout = new QVBoxLayout(DesignerPair);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbText = new QLabel(DesignerPair);
        lbText->setObjectName(QString::fromUtf8("lbText"));
        lbText->setContextMenuPolicy(Qt::DefaultContextMenu);
        lbText->setAutoFillBackground(false);

        verticalLayout->addWidget(lbText);


        retranslateUi(DesignerPair);

        QMetaObject::connectSlotsByName(DesignerPair);
    } // setupUi

    void retranslateUi(QWidget *DesignerPair)
    {
        DesignerPair->setWindowTitle(QApplication::translate("DesignerPair", "Form", 0, QApplication::UnicodeUTF8));
        lbText->setText(QApplication::translate("DesignerPair", "lbText", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesignerPair: public Ui_DesignerPair {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERPAIR_H
