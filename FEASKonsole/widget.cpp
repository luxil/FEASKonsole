#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_TonModus_clicked()
{
    faceDetAndFPL.findFacesAndPoints();
}

void Widget::on_checkBox_clicked(bool checked)
{
    sendoscmsg.send("/DSP", checked);
}
