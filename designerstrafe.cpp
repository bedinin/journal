#include "designerstrafe.h"
#include "ui_designerstrafe.h"

DesignerStrafe::DesignerStrafe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DesignerStrafe)
{
    ui->setupUi(this);
}

DesignerStrafe::~DesignerStrafe()
{
    delete ui;
}
