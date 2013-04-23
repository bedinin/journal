/********************************************************************************
** Form generated from reading UI file 'DesignerFacade.ui'
**
** Created: Sun 7. Apr 22:36:14 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERFACADE_H
#define UI_DESIGNERFACADE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesignerFacade
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *DesignerFacade)
    {
        if (DesignerFacade->objectName().isEmpty())
            DesignerFacade->setObjectName(QString::fromUtf8("DesignerFacade"));
        DesignerFacade->resize(243, 115);
        DesignerFacade->setMinimumSize(QSize(0, 115));
        DesignerFacade->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(DesignerFacade);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);

        retranslateUi(DesignerFacade);

        QMetaObject::connectSlotsByName(DesignerFacade);
    } // setupUi

    void retranslateUi(QWidget *DesignerFacade)
    {
        DesignerFacade->setWindowTitle(QApplication::translate("DesignerFacade", "\320\244\320\260\321\201\320\260\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesignerFacade: public Ui_DesignerFacade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERFACADE_H
