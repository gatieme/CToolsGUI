#ifndef ABOUTCTOOLS_H
#define ABOUTCTOOLS_H

#include <QDialog>

namespace Ui {
class AboutCTools;
}

class AboutCTools : public QDialog
{
    Q_OBJECT

public:
    explicit AboutCTools(QWidget *parent = 0);
    ~AboutCTools();

private:
    Ui::AboutCTools *ui;
};

#endif // ABOUTEDIT_H
