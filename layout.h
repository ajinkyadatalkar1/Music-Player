#ifndef LAYOUT_H
#define LAYOUT_H

#include "body.h"

class layouts : public QGridLayout
{
public:
    layouts();

public slots:
    void slider_pos_changed(int pos, QSlider *slider);
};

#endif // LAYOUT_H
