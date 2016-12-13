#include "widget.h"
#include "ui_widget.h"
#include "sendoscmsg.h"

Widget::Widget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::Widget),
    sendoscmsg(new Sendoscmsg)
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
    sendoscmsg->send("/DSP", checked);
}

void Widget::on_MundHSlider_valueChanged(int value)
{
    sendoscmsg->send("/MundH", value);
}

void Widget::on_MundBlSlider_valueChanged(int value)
{
    sendoscmsg->send("/MundB", value);
}

void Widget::on_AugenbraueLSlider_valueChanged(int value)
{
    sendoscmsg->send("/AugenbraueL", value);
}

void Widget::on_AugenbraueRSlider_valueChanged(int value)
{
    sendoscmsg->send("/AugenbraueR", value);
}

void Widget::on_KopfDrehungSlider_valueChanged(int value)
{
    sendoscmsg->send("/Kopfdrehung", value);
}

void Widget::on_KopfskalierungSlider_valueChanged(int value)
{
    sendoscmsg->send("/Kopfskalierung", value);
}

void Widget::on_AugeLcheckBox_clicked(bool checked)
{
    sendoscmsg->send("/AugeL", checked);
}

void Widget::on_AugeRcheckBox_clicked(bool checked)
{
    sendoscmsg->send("/AugeR", checked);
}
