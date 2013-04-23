#ifndef IROTATELABEL_H
#define IROTATELABEL_H

#include <QWidget>
#include <QPainter>

class IRotateLabel : public QWidget
{
    Q_OBJECT
private:
        int      angle_;
        QString  text_;
        QRect    erase_rect_; // covers last displayed text
        QMatrix matrix_;
public:
    //explicit IRotateLabel(QObject *parent = 0);
     explicit  IRotateLabel(int angle, const QString &text, QWidget *parent=0);
private:
        virtual void paintEvent(QPaintEvent *);
        virtual void resizeEvent(QResizeEvent *);
        void do_paint();
signals:

public slots:

};

#endif // IROTATELABEL_H
