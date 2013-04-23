/********************************************************************************
** Form generated from reading UI file 'designerIPair.ui'
**
** Created: Tue 2. Apr 09:33:00 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERIPAIR_H
#define UI_DESIGNERIPAIR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_designerIPair
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbValue;
    QListWidget *listValue;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbCrossing;
    QListWidget *listCrossing;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbFlag_Value;
    QCheckBox *cbJournal;

    void setupUi(QWidget *designerIPair)
    {
        if (designerIPair->objectName().isEmpty())
            designerIPair->setObjectName(QString::fromUtf8("designerIPair"));
        designerIPair->resize(186, 196);
        verticalLayout_4 = new QVBoxLayout(designerIPair);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbValue = new QLabel(designerIPair);
        lbValue->setObjectName(QString::fromUtf8("lbValue"));

        verticalLayout->addWidget(lbValue);

        listValue = new QListWidget(designerIPair);
        listValue->setObjectName(QString::fromUtf8("listValue"));

        verticalLayout->addWidget(listValue);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lbCrossing = new QLabel(designerIPair);
        lbCrossing->setObjectName(QString::fromUtf8("lbCrossing"));

        verticalLayout_3->addWidget(lbCrossing);

        listCrossing = new QListWidget(designerIPair);
        listCrossing->setObjectName(QString::fromUtf8("listCrossing"));

        verticalLayout_3->addWidget(listCrossing);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cbFlag_Value = new QCheckBox(designerIPair);
        cbFlag_Value->setObjectName(QString::fromUtf8("cbFlag_Value"));

        verticalLayout_2->addWidget(cbFlag_Value);

        cbJournal = new QCheckBox(designerIPair);
        cbJournal->setObjectName(QString::fromUtf8("cbJournal"));

        verticalLayout_2->addWidget(cbJournal);


        verticalLayout_4->addLayout(verticalLayout_2);

        lbValue->raise();
        listValue->raise();
        lbValue->raise();
        cbFlag_Value->raise();
        cbJournal->raise();

        retranslateUi(designerIPair);

        QMetaObject::connectSlotsByName(designerIPair);
    } // setupUi

    void retranslateUi(QWidget *designerIPair)
    {
        designerIPair->setWindowTitle(QApplication::translate("designerIPair", "\320\237\320\260\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lbValue->setText(QApplication::translate("designerIPair", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        lbCrossing->setText(QApplication::translate("designerIPair", "\320\232\321\200\320\276\321\201\321\201\320\270\321\200\320\276\320\262\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        cbFlag_Value->setText(QApplication::translate("designerIPair", "\320\237\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8));
        cbJournal->setText(QApplication::translate("designerIPair", "\320\236\321\202\320\276\320\261\321\200\320\276\320\266\320\260\321\202\321\214 \320\262 \321\201\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class designerIPair: public Ui_designerIPair {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERIPAIR_H
