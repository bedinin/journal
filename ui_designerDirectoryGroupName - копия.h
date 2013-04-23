/********************************************************************************
** Form generated from reading UI file 'designerDirectoryGroupName.ui'
**
** Created: Sun 16. Dec 18:07:24 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERDIRECTORYGROUPNAME_H
#define UI_DESIGNERDIRECTORYGROUPNAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_designerGroupNameDirectory
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *lbError;
    QTableWidget *table;
    QGridLayout *gridLayout;
    QLabel *lbName;
    QLabel *lbColor;
    QLineEdit *leName;
    QLabel *lbComment;
    QTextEdit *teComment;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leColor;
    QPushButton *btColorSelect;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btAdd;
    QPushButton *btSave;
    QPushButton *btDelete;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *designerGroupNameDirectory)
    {
        if (designerGroupNameDirectory->objectName().isEmpty())
            designerGroupNameDirectory->setObjectName(QString::fromUtf8("designerGroupNameDirectory"));
        designerGroupNameDirectory->resize(450, 400);
        designerGroupNameDirectory->setMinimumSize(QSize(450, 400));
        verticalLayout_2 = new QVBoxLayout(designerGroupNameDirectory);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbError = new QLabel(designerGroupNameDirectory);
        lbError->setObjectName(QString::fromUtf8("lbError"));

        verticalLayout_2->addWidget(lbError);

        table = new QTableWidget(designerGroupNameDirectory);
        if (table->columnCount() < 3)
            table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table->setObjectName(QString::fromUtf8("table"));
        table->setContextMenuPolicy(Qt::ActionsContextMenu);
        table->setLineWidth(1);
        table->setMidLineWidth(0);
        table->setAlternatingRowColors(false);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setColumnCount(3);

        verticalLayout_2->addWidget(table);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbName = new QLabel(designerGroupNameDirectory);
        lbName->setObjectName(QString::fromUtf8("lbName"));

        gridLayout->addWidget(lbName, 0, 0, 1, 1);

        lbColor = new QLabel(designerGroupNameDirectory);
        lbColor->setObjectName(QString::fromUtf8("lbColor"));

        gridLayout->addWidget(lbColor, 2, 0, 1, 1);

        leName = new QLineEdit(designerGroupNameDirectory);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 1, 1, 1);

        lbComment = new QLabel(designerGroupNameDirectory);
        lbComment->setObjectName(QString::fromUtf8("lbComment"));

        gridLayout->addWidget(lbComment, 3, 0, 1, 1);

        teComment = new QTextEdit(designerGroupNameDirectory);
        teComment->setObjectName(QString::fromUtf8("teComment"));
        teComment->setMaximumSize(QSize(16777215, 150));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        teComment->setFont(font);
        teComment->setFrameShape(QFrame::StyledPanel);
        teComment->setFrameShadow(QFrame::Sunken);
        teComment->setLineWidth(0);

        gridLayout->addWidget(teComment, 3, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        leColor = new QLineEdit(designerGroupNameDirectory);
        leColor->setObjectName(QString::fromUtf8("leColor"));
        leColor->setMaximumSize(QSize(50, 16777215));
        leColor->setReadOnly(true);

        horizontalLayout_3->addWidget(leColor);

        btColorSelect = new QPushButton(designerGroupNameDirectory);
        btColorSelect->setObjectName(QString::fromUtf8("btColorSelect"));
        btColorSelect->setMaximumSize(QSize(30, 20));
        btColorSelect->setCheckable(false);
        btColorSelect->setChecked(false);
        btColorSelect->setAutoRepeat(false);
        btColorSelect->setAutoExclusive(false);

        horizontalLayout_3->addWidget(btColorSelect);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btAdd = new QPushButton(designerGroupNameDirectory);
        btAdd->setObjectName(QString::fromUtf8("btAdd"));

        horizontalLayout->addWidget(btAdd);

        btSave = new QPushButton(designerGroupNameDirectory);
        btSave->setObjectName(QString::fromUtf8("btSave"));
        btSave->setEnabled(false);

        horizontalLayout->addWidget(btSave);

        btDelete = new QPushButton(designerGroupNameDirectory);
        btDelete->setObjectName(QString::fromUtf8("btDelete"));
        btDelete->setEnabled(false);

        horizontalLayout->addWidget(btDelete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(designerGroupNameDirectory);

        QMetaObject::connectSlotsByName(designerGroupNameDirectory);
    } // setupUi

    void retranslateUi(QWidget *designerGroupNameDirectory)
    {
        designerGroupNameDirectory->setWindowTitle(QApplication::translate("designerGroupNameDirectory", "\320\223\321\200\321\203\320\277\320\277\321\213 \320\275\320\260 \320\272\321\200\320\276\321\201\321\201\320\265", 0, QApplication::UnicodeUTF8));
        lbError->setText(QApplication::translate("designerGroupNameDirectory", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#ff0000;\">%1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("designerGroupNameDirectory", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("designerGroupNameDirectory", "\320\246\320\262\320\265\321\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("designerGroupNameDirectory", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", 0, QApplication::UnicodeUTF8));
        lbName->setText(QApplication::translate("designerGroupNameDirectory", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#00007f;\">\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lbColor->setText(QApplication::translate("designerGroupNameDirectory", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#00007f;\">\320\246\320\262\320\265\321\202</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        leName->setInputMask(QString());
        leName->setText(QString());
        lbComment->setText(QApplication::translate("designerGroupNameDirectory", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#00007f;\">\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        teComment->setHtml(QApplication::translate("designerGroupNameDirectory", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:italic;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">%1</p></body></html>", 0, QApplication::UnicodeUTF8));
        leColor->setInputMask(QString());
        leColor->setText(QString());
        btColorSelect->setText(QApplication::translate("designerGroupNameDirectory", "...", 0, QApplication::UnicodeUTF8));
        btAdd->setText(QApplication::translate("designerGroupNameDirectory", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btSave->setText(QApplication::translate("designerGroupNameDirectory", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btDelete->setText(QApplication::translate("designerGroupNameDirectory", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class designerGroupNameDirectory: public Ui_designerGroupNameDirectory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERDIRECTORYGROUPNAME_H
