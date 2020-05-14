#include "body.h"
#include "layout.h"

body::body()
{
    layouts *lay = new layouts();
    setLayout(lay);
    setFixedHeight(100);
    setFixedWidth(475);
    QLabel *name = new QLabel;
    name->setText("Application written by Ajinkya Datalkar.");
    lay->addWidget(name);
}
