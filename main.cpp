#include <QApplication>
#include <QtGui>

#include "global.h"
#include "cjournalcore.h"

#include "istrafefacade.h"
#include "irotatelabel.h"
QSqlQuery* query;
CJournalCore* journalCore;
//CMysqlConnect mysqlConnect;
int main(int argc,char** argv){

    QApplication app(argc,argv);
    CJournalCore core;
    QString s = "ssssssssssssssssss";
 /*    //IRotateLabel *rot = new IRotateLabel(90,s);
   //rot->show();
     //QLabel *panel= new QLabel("sadasd");
    //panel->setText("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    //QPixmap pm(QSize(panel->width(),panel->height()));
    //qDebug() << panel->width() << ":" << panel->height();
   // pm.fill(panel,0,0);
   QPainter p;
    p.begin(&pm);
    p.drawText(50,50,"eeeeeeeeeeeeeeeeee");
    p.rotate(90);
    p.end();
    //QPixmap rotpm;
    //rotpm = pm.transformed(QTransform().rotate(90,Qt::YAxis),Qt::FastTransformation);
    //pm.fill(panel,0,0);

    //panel->setPixmap(rotpm);
    //QPainter p(&pm);
    //p.rotate(90);
    //panel->show();
     //p= panel->pain
    QColor color(255,0,0);
    QPen pen(color, 2);

    //app.setMainWidget(panel);
    panel->show();

    p.begin(panel->_buffer);
    QPoint point(100,100);
    p.drawText(point,"Text at 100,100");

    p.rotate(30);
    p.drawText(point,"Text at 100,100 after rotation");

    point = p.xFormDev(point);
    p.drawText(point,"Texte at 100,100 using xFormDev");
    p.end();
*/


    return app.exec();
}
