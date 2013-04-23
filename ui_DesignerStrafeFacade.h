/********************************************************************************
** Form generated from reading UI file 'DesignerStrafeFacade.ui'
**
** Created: Wed 2. Jan 20:40:18 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERSTRAFEFACADE_H
#define UI_DESIGNERSTRAFEFACADE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_designerStrafeFacade
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbSrafeName;
    QTableWidget *table;

    void setupUi(QWidget *designerStrafeFacade)
    {
        if (designerStrafeFacade->objectName().isEmpty())
            designerStrafeFacade->setObjectName(QString::fromUtf8("designerStrafeFacade"));
        designerStrafeFacade->resize(237, 125);
        verticalLayout = new QVBoxLayout(designerStrafeFacade);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbSrafeName = new QLabel(designerStrafeFacade);
        lbSrafeName->setObjectName(QString::fromUtf8("lbSrafeName"));

        verticalLayout->addWidget(lbSrafeName);

        table = new QTableWidget(designerStrafeFacade);
        if (table->columnCount() < 9)
            table->setColumnCount(9);
        if (table->rowCount() < 2)
            table->setRowCount(2);
        table->setObjectName(QString::fromUtf8("table"));
        table->setEnabled(true);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionMode(QAbstractItemView::ExtendedSelection);
        table->setRowCount(2);
        table->setColumnCount(9);
        table->horizontalHeader()->setDefaultSectionSize(20);
        table->horizontalHeader()->setMinimumSectionSize(20);
        table->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(table);


        retranslateUi(designerStrafeFacade);

        QMetaObject::connectSlotsByName(designerStrafeFacade);
    } // setupUi

    void retranslateUi(QWidget *designerStrafeFacade)
    {
        designerStrafeFacade->setWindowTitle(QString());
        lbSrafeName->setText(QApplication::translate("designerStrafeFacade", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">%1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class designerStrafeFacade: public Ui_designerStrafeFacade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERSTRAFEFACADE_H
