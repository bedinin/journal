#ifndef DESIGNERICROSSING_H
#define DESIGNERICROSSING_H

#include <QWidget>

namespace Ui {
    class DesignerICrossing;
}

class DesignerICrossing : public QWidget
{
    Q_OBJECT

public:
    explicit DesignerICrossing(QWidget *parent = 0);
    ~DesignerICrossing();

private:
    Ui::DesignerICrossing *ui;
};

#endif // DESIGNERICROSSING_H
