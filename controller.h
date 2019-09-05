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

    bool _running;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

private slots:
    void run_test();

public slots:
};

#endif // CONTROLLER_H
