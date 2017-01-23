#ifndef WIDGET_H
#define WIDGET_H

#include <QTabWidget>
#include "facedetandfpl.h"
#include "soundmodus.h"
#include "sendoscmsg.h"

namespace Ui {
class Widget;
}


class Widget : public QTabWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void send(string method, float value);



private slots:
    void on_TonModus_clicked();

    void on_checkBox_clicked(bool checked);

    void on_MundHSlider_valueChanged(int value);

    void on_MundBlSlider_valueChanged(int value);

    void on_AugenbraueLSlider_valueChanged(int value);

    void on_AugenbraueRSlider_valueChanged(int value);

    void on_KopfDrehungSlider_valueChanged(int value);

    void on_KopfskalierungSlider_valueChanged(int value);

    void on_param1_slider_valueChanged(int value);

    void on_param2_slider_valueChanged(int value);

    void on_TonModus_2_clicked();

    void on_TonModus_3_clicked();

private:
    Ui::Widget *ui;
    FaceDetAndFPL faceDetAndFPL;
    Sendoscmsg *sendoscmsg;
};

#endif // WIDGET_H
