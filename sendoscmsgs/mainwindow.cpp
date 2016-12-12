#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SendOSCMessage_Button_clicked()
{
    sendoscmsg.send("/Test", 100);
}

void MainWindow::on_MundH_Slider_valueChanged(int value)
{
    sendoscmsg.send("/MundH", value);
}

void MainWindow::on_MundB_Slider_valueChanged(int value)
{
    sendoscmsg.send("/MundB", value);
}

void MainWindow::on_AugenbraueL_Slider_valueChanged(int value)
{
    sendoscmsg.send("/AugenbraueL", value);
}

void MainWindow::on_AugenbraueR_Slider_valueChanged(int value)
{
    sendoscmsg.send("/AugenbraueR", value);
}

void MainWindow::on_Kopfdrehung_Slider_valueChanged(int value)
{
    sendoscmsg.send("/Kopfdrehung", value);
}

void MainWindow::on_Kopsskalierung_Slider_valueChanged(int value)
{
    sendoscmsg.send("/Kopfskalierung", value);
}

void MainWindow::on_AugeL_checkBox_clicked(bool checked)
{
   sendoscmsg.send("/AugeL", checked);
}

void MainWindow::on_AugeR_checkBox_clicked(bool checked)
{
   sendoscmsg.send("/AugeR", checked);
}
