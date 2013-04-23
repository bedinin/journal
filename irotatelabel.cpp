#include "irotatelabel.h"

IRotateLabel::IRotateLabel(int angle, const QString &text, QWidget *parent) :
    QWidget(parent),
    angle_(angle), text_(text),
    erase_rect_(QRect(0, 0, 0, 0))
{
    matrix_.rotate(angle_);
    setMinimumWidth(fontMetrics().boundingRect(text_).height()); // 270 degrees
}

void IRotateLabel::paintEvent(QPaintEvent *)
{
   /* QPixmap pm(QSize(this->width(),this->height()));
    pm.fill(this,0,0);
    QPainter paint(this);
    QPixmap pix;
    paint.drawText(50,60,"ssssssssssss");
    paint.rotate(90);
    this->*/
}

void IRotateLabel::resizeEvent(QResizeEvent *)
{
   // erase_rect_ = QRect( width()/2, height()/2, 0, 0 );
    //repaint(rect());
}

void IRotateLabel::do_paint(){

    //this->setText("sa");
    /*QPixmap pm(QSize(this->width(),this->height()));
    pm.fill(this,0,0);
    QPainter p(&pm);
    p.rotate(90);
    this->setPixmap(pm);
    //this->show();

    //p. (&pm);
    //p.rotate(90);
    /*QMatrix um;  // copy user specified transform
    QRect br = fontMetrics().boundingRect( text_ );	// rectangle covering text
    QRect r  = br;	  // rectangle covering new text in virtual coordinates
    int textYPos = -r.y(); // distance from boundingRect y pos to baseline
    int textXPos = -r.x(); // distance from boundingRect x pos to text start
    br.moveTopLeft( QPoint( -br.width()/2, -br.height()/2 ) );
    r.moveTopLeft( QPoint(-r.width()/2, -r.height()/2) );
    // compute union of new and old rect
    // the resulting rectangle will cover what is already displayed
    // and have room for the new text/pixmap
    erase_rect_ = erase_rect_.unite( matrix_.map(r) );
    erase_rect_.moveBy( -1, -1 ); // add border for matrix round off
    erase_rect_.setSize( QSize( erase_rect_.width() + 2,erase_rect_.height() + 2 ) );
    int pw = std::min(erase_rect_.width(),width());
    int ph = std::min(erase_rect_.height(),height());
    QPixmap pm( pw, ph );		// off-screen drawing pixmap
    pm.fill( backgroundColor() );

    p.begin( &pm );
    um.translate( pw/2, ph/2 );	// 0,0 is center
    um = matrix_ * um;
    p.setWorldMatrix( um );
    p.setFont( font() );		// use widget font
    p.drawText( r.left() + textXPos, r.top() + textYPos, text_ );
    p.end();

    int xpos = width()/2  - pw/2;
    int ypos = height()/2 - ph/2;
    bitBlt( this, xpos, ypos,			// copy pixmap to widget
            &pm, 0, 0, -1, -1 );
    erase_rect_ = matrix_.map( r );*/
}
