#include "mainwindow.h"
#include <QApplication>
#include "../EssController/projectcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Projectcontroller *pj = new Projectcontroller();
    pj->initView(&w);

    return a.exec();
}
