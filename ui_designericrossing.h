/********************************************************************************
** Form generated from reading UI file 'designericrossing.ui'
**
** Created: Sun 7. Apr 22:22:45 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERICROSSING_H
#define UI_DESIGNERICROSSING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesignerICrossing
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *table;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leStrafe;
    QLineEdit *lePlint;
    QLineEdit *lePair;
    QVBoxLayout *verticalLayout;
    QPushButton *btAdd;
    QPushButton *btDelete;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DesignerICrossing)
    {
        if (DesignerICrossing->objectName().isEmpty())
            DesignerICrossing->setObjectName(QString::fromUtf8("DesignerICrossing"));
        DesignerICrossing->resize(727, 326);
        horizontalLayout_2 = new QHBoxLayout(DesignerICrossing);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        table = new QTableWidget(DesignerICrossing);
        if (table->columnCount() < 3)
            table->setColumnCount(3);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setPointSize(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setForeground(brush);
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table->setObjectName(QString::fromUtf8("table"));
        QFont font1;
        font1.setPointSize(8);
        table->setFont(font1);
        table->setMouseTracking(false);
        table->setLineWidth(1);
        table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setAutoScroll(true);
        table->setAutoScrollMargin(16);
        table->setAlternatingRowColors(false);
        table->setSelectionMode(QAbstractItemView::ExtendedSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setShowGrid(true);
        table->setGridStyle(Qt::SolidLine);
        table->horizontalHeader()->setDefaultSectionSize(40);
        table->horizontalHeader()->setMinimumSectionSize(30);
        table->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leStrafe = new QLineEdit(DesignerICrossing);
        leStrafe->setObjectName(QString::fromUtf8("leStrafe"));
        leStrafe->setContextMenuPolicy(Qt::DefaultContextMenu);

        horizontalLayout->addWidget(leStrafe);

        lePlint = new QLineEdit(DesignerICrossing);
        lePlint->setObjectName(QString::fromUtf8("lePlint"));

        horizontalLayout->addWidget(lePlint);

        lePair = new QLineEdit(DesignerICrossing);
        lePair->setObjectName(QString::fromUtf8("lePair"));

        horizontalLayout->addWidget(lePair);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btAdd = new QPushButton(DesignerICrossing);
        btAdd->setObjectName(QString::fromUtf8("btAdd"));
        btAdd->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btAdd->sizePolicy().hasHeightForWidth());
        btAdd->setSizePolicy(sizePolicy);
        btAdd->setMinimumSize(QSize(28, 24));
        btAdd->setMaximumSize(QSize(28, 24));
        btAdd->setSizeIncrement(QSize(0, 0));
        btAdd->setBaseSize(QSize(0, 0));
        btAdd->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/images/edit_add.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btAdd->setIcon(icon);
        btAdd->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(btAdd);

        btDelete = new QPushButton(DesignerICrossing);
        btDelete->setObjectName(QString::fromUtf8("btDelete"));
        btDelete->setMaximumSize(QSize(28, 24));
        btDelete->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/images/edit_remove.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btDelete->setIcon(icon1);

        verticalLayout->addWidget(btDelete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(DesignerICrossing);

        QMetaObject::connectSlotsByName(DesignerICrossing);
    } // setupUi

    void retranslateUi(QWidget *DesignerICrossing)
    {
        DesignerICrossing->setWindowTitle(QApplication::translate("DesignerICrossing", "\320\232\321\200\320\276\321\201\321\201\320\270\321\200\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DesignerICrossing", "\320\241\321\202\321\200\320\265\320\271\321\204", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DesignerICrossing", "\320\237\320\273\320\270\320\275\321\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DesignerICrossing", "\320\237\320\260\321\200\320\260", 0, QApplication::UnicodeUTF8));
        btAdd->setText(QString());
        btDelete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DesignerICrossing: public Ui_DesignerICrossing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERICROSSING_H
