#include "widget.h"
#include "ui_widget.h"
#include "sendoscmsg.h"
using namespace std;

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
    faceDetAndFPL.soundModus->on = true;
    faceDetAndFPL.findFacesAndPoints();
}

void Widget::on_checkBox_clicked(bool checked)
{
    sendoscmsg->send("/DSP", checked);
    cout << "checked" << checked << endl;
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

void Widget::on_param1_slider_valueChanged(int value)
{
    sendoscmsg->send("/AugeL", value);
}

void Widget::on_param2_slider_valueChanged(int value)
{
    sendoscmsg->send("/AugeR", value);
}

void Widget::on_TonModus_2_clicked()
{
    faceDetAndFPL.soundModus->on = false;
    sendoscmsg->send("/DSP", 1);
    faceDetAndFPL.findFacesAndPoints();

}

void Widget::on_TonModus_3_clicked()
{
    sendoscmsg->send("/Kopfdrehung", 80);
}
