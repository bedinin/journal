#include "designericrossing.h"
#include "ui_designericrossing.h"

DesignerICrossing::DesignerICrossing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DesignerICrossing)
{
    ui->setupUi(this);
}

DesignerICrossing::~DesignerICrossing()
{
    delete ui;
}
