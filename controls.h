#ifndef CONTROLS_H
#define CONTROLS_H

#include "body.h"

class controls
{
public:
    void play_button(QMediaPlayer *player,QSlider *track);
    void pause_button(QMediaPlayer *player);
    void quit_button();
};

#endif // CONTROLS_H
