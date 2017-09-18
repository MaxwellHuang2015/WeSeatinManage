#include "mainwindow.h"
#include <QApplication>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    if (QSysInfo::windowsVersion() == QSysInfo::WV_XP) {
        QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
        QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
