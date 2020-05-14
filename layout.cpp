#include <layout.h>
#include "player.h"
#include "controls.h"

layouts::layouts()
{
    player *play_diag = new player();
    play_diag->setVolume(100);

    controls *ctrl = new controls;
    QSlider *track = new QSlider(Qt::Horizontal);

    QSlider *volume = new QSlider(Qt::Horizontal);
    volume->setRange(0,100);
    volume->setValue(play_diag->volume());
    volume->setFixedWidth(100);

    connect(play_diag,&player::positionChanged,[=](){
        track->setRange(0,play_diag->duration());
        slider_pos_changed(play_diag->position(),track);
    });

    connect(track,&QSlider::sliderReleased,[=](){
        play_diag->setPosition(track->value());
    });

    connect(volume,&QSlider::valueChanged,[=](){
        play_diag->setVolume(volume->value());

    });

    QHBoxLayout *hBox = new QHBoxLayout;
    QVBoxLayout *vBox = new QVBoxLayout;

    addLayout(vBox,0,0);
    addLayout(hBox,1,0);

    qDebug() << QDir::homePath();

    vBox->addWidget(track);

    QPushButton *btn1 = new QPushButton("Play ");
    btn1->setFixedWidth(50);

    QPushButton *btn2 = new QPushButton("RR");
    btn2->setFixedWidth(50);

    QPushButton *btn3 = new QPushButton("Pause");
    btn3->setFixedWidth(50);

    QPushButton *btn4 = new QPushButton("FF");
    btn4->setFixedWidth(50);

    QPushButton *btn5 = new QPushButton("Quit");
    btn5->setFixedWidth(50);

    QPushButton *btn6 = new QPushButton("🔊");
    btn6->setFixedWidth(50);

    hBox->addWidget(btn1);
    hBox->addWidget(btn2);
    hBox->addWidget(btn3);
    hBox->addWidget(btn4);
    hBox->addWidget(btn5);
    hBox->addWidget(btn6);
    hBox->addWidget(volume);

    connect(btn1,&QPushButton::clicked,[=](){
        ctrl->play_button(play_diag, track);
    });

    connect(btn2,&QPushButton::clicked,[=](){
        play_diag->setPosition(play_diag->position() - 1500);
        track->setValue(play_diag->position());
    });

    connect(btn3,&QPushButton::clicked,[=](){
       ctrl->pause_button(play_diag);
    });

    connect(btn4,&QPushButton::clicked,[=](){
        play_diag->setPosition(play_diag->position() + 1500);
        track->setValue(play_diag->position());
    });

    connect(btn5,&QPushButton::clicked,[=](){
       exit(0);
    });

    connect(btn6,&QPushButton::clicked,[=](){
        play_diag->isMuted()? btn6->setText("🔊"):btn6->setText("🔇");
        play_diag->isMuted()? play_diag->setMuted(0):play_diag->setMuted(1);
    });

    }

void layouts::slider_pos_changed(int pos,QSlider *slider)
{
    slider->setValue(pos);
}
