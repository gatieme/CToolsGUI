#include "aboutctools.h"
#include "ui_aboutctools.h"

AboutCTools::AboutCTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutCTools)
{
    ui->setupUi(this);
}

AboutCTools::~AboutCTools()
{
    delete ui;
}
