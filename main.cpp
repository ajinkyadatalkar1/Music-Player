#include "body.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    body *bd = new body();
    bd->show();

    return a.exec();
}
