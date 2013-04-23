/********************************************************************************
** Form generated from reading UI file 'designerDetailedStrafe.ui'
**
** Created: Tue 9. Apr 15:15:25 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERDETAILEDSTRAFE_H
#define UI_DESIGNERDETAILEDSTRAFE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_designerDetailedStrafe
{
public:
    QTabWidget *table;
    QWidget *widget;
    QWidget *tab_2;

    void setupUi(QWidget *designerDetailedStrafe)
    {
        if (designerDetailedStrafe->objectName().isEmpty())
            designerDetailedStrafe->setObjectName(QString::fromUtf8("designerDetailedStrafe"));
        designerDetailedStrafe->resize(400, 300);
        table = new QTabWidget(designerDetailedStrafe);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(0, 0, 127, 80));
        table->setElideMode(Qt::ElideNone);
        table->setDocumentMode(false);
        table->setTabsClosable(false);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        table->addTab(widget, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        table->addTab(tab_2, QString());

        retranslateUi(designerDetailedStrafe);

        table->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(designerDetailedStrafe);
    } // setupUi

    void retranslateUi(QWidget *designerDetailedStrafe)
    {
        designerDetailedStrafe->setWindowTitle(QApplication::translate("designerDetailedStrafe", "\320\232\321\200\320\276\321\201\321\201", 0, QApplication::UnicodeUTF8));
        table->setTabText(table->indexOf(widget), QString());
        table->setTabText(table->indexOf(tab_2), QApplication::translate("designerDetailedStrafe", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class designerDetailedStrafe: public Ui_designerDetailedStrafe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERDETAILEDSTRAFE_H
