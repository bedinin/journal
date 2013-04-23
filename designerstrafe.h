#ifndef DESIGNERSTRAFE_H
#define DESIGNERSTRAFE_H

#include <QWidget>

namespace Ui {
    class DesignerStrafe;
}

class DesignerStrafe : public QWidget
{
    Q_OBJECT

public:
    explicit DesignerStrafe(QWidget *parent = 0);
    ~DesignerStrafe();

private:
    Ui::DesignerStrafe *ui;
};

#endif // DESIGNERSTRAFE_H
