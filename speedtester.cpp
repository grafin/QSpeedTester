#include "speedtester.h"

SpeedTester::SpeedTester(QObject *parent, unsigned long timeout) : QObject(parent)
{
    _timeout = timeout;

    _webManager = new QNetworkAccessManager();
    _timer = new QElapsedTimer();

    connect(
        _webManager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(test_finished(QNetworkReply*))
    );

    _thread = new QThread();

    this->moveToThread(_thread);
    _webManager->moveToThread(_thread);
    _thread->start();
}

SpeedTester::~SpeedTester()
{
    delete _timer;
    delete _webManager;
    _thread->quit();
    _thread->wait();
    delete _thread;
}

void SpeedTester::run_test(const QString &url)
{

    QNetworkRequest request(url);
    request.setAttribute(
        QNetworkRequest::CacheLoadControlAttribute,
        QVariant(int(QNetworkRequest::AlwaysNetwork))
    );

    _timer->start();
    QNetworkReply *reply = _webManager->get(request);

    connect(
        reply, SIGNAL(downloadProgress(qint64, qint64)),
        this, SLOT(test_running(qint64, qint64))
    );
}

void SpeedTester::test_finished(QNetworkReply *reply)
{
    emit test_ready(reply->bytesAvailable(), _timer->elapsed());
    reply->deleteLater();
    run_test(reply->url().toString());
}

void SpeedTester::test_running(const qint64 bytesReceived, const qint64 bytesTotal)
{
    emit test_ready(bytesReceived, _timer->elapsed());
}
