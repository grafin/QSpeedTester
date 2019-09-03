#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <mainwindow.h>
#include <speedtester.h>
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow *_window;
    SpeedTester *_tester;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

signals:

public slots:
};

#endif // CONTROLLER_H
