/********************************************************************************
** Form generated from reading UI file 'designerstrafe.ui'
**
** Created: Sun 7. Apr 22:29:22 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERSTRAFE_H
#define UI_DESIGNERSTRAFE_H

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

class Ui_DesignerStrafe
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbSrafeName;
    QTableWidget *table;

    void setupUi(QWidget *DesignerStrafe)
    {
        if (DesignerStrafe->objectName().isEmpty())
            DesignerStrafe->setObjectName(QString::fromUtf8("DesignerStrafe"));
        DesignerStrafe->resize(268, 170);
        verticalLayout = new QVBoxLayout(DesignerStrafe);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbSrafeName = new QLabel(DesignerStrafe);
        lbSrafeName->setObjectName(QString::fromUtf8("lbSrafeName"));

        verticalLayout->addWidget(lbSrafeName);

        table = new QTableWidget(DesignerStrafe);
        if (table->columnCount() < 9)
            table->setColumnCount(9);
        if (table->rowCount() < 2)
            table->setRowCount(2);
        table->setObjectName(QString::fromUtf8("table"));
        table->setEnabled(true);
        table->setFrameShape(QFrame::StyledPanel);
        table->setFrameShadow(QFrame::Sunken);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        table->setAutoScroll(true);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionMode(QAbstractItemView::ExtendedSelection);
        table->setRowCount(2);
        table->setColumnCount(9);
        table->horizontalHeader()->setDefaultSectionSize(20);
        table->horizontalHeader()->setMinimumSectionSize(20);
        table->verticalHeader()->setVisible(false);
        table->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(table);


        retranslateUi(DesignerStrafe);

        QMetaObject::connectSlotsByName(DesignerStrafe);
    } // setupUi

    void retranslateUi(QWidget *DesignerStrafe)
    {
        DesignerStrafe->setWindowTitle(QApplication::translate("DesignerStrafe", "Form", 0, QApplication::UnicodeUTF8));
        lbSrafeName->setText(QApplication::translate("DesignerStrafe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">%1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesignerStrafe: public Ui_DesignerStrafe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERSTRAFE_H
