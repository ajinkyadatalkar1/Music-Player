#include "controls.h"

QString home_dir = QDir::homePath() + "/Music/";
QString filename;
int paused;

void controls::play_button(QMediaPlayer *player,QSlider *track)
{
    if(!paused){
    filename = QFileDialog::getOpenFileName(0,"play file",home_dir,"*.mp3");
        if(filename != ""){
            player->setMedia(QUrl::fromLocalFile(filename));
            track->setValue(player->position());
            player->play();
            qDebug() << "Playing";
        }
    }
    else
    {
        player->play();
        paused = 0;
    }
}
void controls::pause_button(QMediaPlayer *player)
{
    player->pause();
    qDebug() << "Paused";
    paused = 1;
}
