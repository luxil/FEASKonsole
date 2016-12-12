#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sendoscmsg.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setIpAddress(string ipaddress);
    void setPort(int port);
    void send(string method, float value);

private slots:
    void on_SendOSCMessage_Button_clicked();

    void on_MundH_Slider_valueChanged(int value);

    void on_MundB_Slider_valueChanged(int value);

    void on_AugenbraueL_Slider_valueChanged(int value);

    void on_AugenbraueR_Slider_valueChanged(int value);

    void on_Kopfdrehung_Slider_valueChanged(int value);

    void on_Kopsskalierung_Slider_valueChanged(int value);

    void on_AugeL_checkBox_clicked(bool checked);

    void on_AugeR_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    Sendoscmsg sendoscmsg;
};

#endif // MAINWINDOW_H
