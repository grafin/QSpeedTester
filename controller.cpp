#include <controller.h>

Controller::Controller(const QString &url, QWidget *parent) : QObject(parent)
{
    _running = false;

    _thread = new QThread(this);
    _window = new MainWindow(url);
    _tester = new SpeedTester(this);

    this->moveToThread(_thread);
    _tester->moveToThread(_thread);
    _tester->init();

    connect(
        _window, SIGNAL(run_test()),
        this, SLOT(run_test())
    );

    connect(
        _tester, SIGNAL(results_ready(const qint64, const qint64)),
        _window, SLOT(show_results(const qint64, const qint64))
    );

    connect(
        _tester, SIGNAL(test_error()),
        _window, SLOT(show_error())
    );

    _thread->start();

    _window->show();
}

Controller::~Controller()
{
    delete _window;
    delete _tester;
    _thread->quit();
    _thread->wait();
    delete _thread;
}

void Controller::run_test()
{
    while (_window->testRunning()) {
        _tester->run_test(_window->getUrl());
    }
}
