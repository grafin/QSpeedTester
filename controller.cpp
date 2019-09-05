#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    _window = new MainWindow();
    _tester = new SpeedTester();

    connect(
        _window, SIGNAL(run_test(const QString &)),
        _tester, SLOT(run_test(const QString &))
    );

    connect(
        _tester, SIGNAL(test_ready(const qint64, const qint64)),
        _window, SLOT(show_results(const qint64, const qint64))
    );

    connect(
        _tester, SIGNAL(test_error()),
        _window, SLOT(show_error())
    );

    _window->show();
}

Controller::~Controller()
{
    delete _window;
    delete _tester;
}

void Controller::run_test()
{

}
