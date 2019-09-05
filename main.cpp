#include <controller.h>

#include <QApplication>
#include <QObject>
#include <QQuickWindow>
#include <QString>

#include <QDebug>

int main(int argc, char *argv[])
{
    QString url = "http://example.com";
    if(argc > 1)
        url = argv[1];

    QQuickWindow::setSceneGraphBackend(QSGRendererInterface::Software);

    QApplication a(argc, argv);

    Controller controller(url);

    return a.exec();
}
