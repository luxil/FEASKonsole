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

private:
    Ui::Widget *ui;
    FaceDetAndFPL faceDetAndFPL;
    SoundModus soundModus;
    Sendoscmsg sendoscmsg;
};

#endif // WIDGET_H
