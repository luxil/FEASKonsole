#ifndef WIDGET_H
#define WIDGET_H

#include <QTabWidget>
#include "facedetandfpl.h"
#include "soundmodus.h"

namespace Ui {
class Widget;
}


class Widget : public QTabWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_TonModus_clicked();

private:
    Ui::Widget *ui;
    FaceDetAndFPL faceDetAndFPL;
    SoundModus soundModus;
};

#endif // WIDGET_H
