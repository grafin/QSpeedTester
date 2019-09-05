#include "speedtester.h"

SpeedTester::SpeedTester(QObject *parent, const int timeout) : QObject(parent)
{
    _timeout = timeout;

    _webManager = new QNetworkAccessManager(this);

    _timer = new QElapsedTimer();

    connect(
        _webManager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(reply_ready(QNetworkReply*))
    );
}

void SpeedTester::init()
{
    _webManager->moveToThread(this->thread());
}

SpeedTester::~SpeedTester()
{
    delete _timer;
    delete _webManager;
}

void SpeedTester::run_test(const QUrl &url)
{
    QNetworkRequest request(url);
    request.setAttribute(
        QNetworkRequest::CacheLoadControlAttribute,
        QVariant(int(QNetworkRequest::AlwaysNetwork))
    );

    QTimer timer;
    timer.setSingleShot(true);

    _timer->start();
    QNetworkReply *reply = _webManager->get(request);

    connect(
        reply, SIGNAL(downloadProgress(qint64, qint64)),
        this, SLOT(test_running(qint64, qint64))
    );

    QEventLoop loop;
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    timer.start(_timeout);
    loop.exec();

    if(timer.isActive())
    {
        timer.stop();
    }
    else
    {
        disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        reply->abort();
    }
}

void SpeedTester::reply_ready(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        emit test_error();
    }
    else
    {
        emit test_finished(reply->url().toString());
    }
    reply->deleteLater();
}

void SpeedTester::test_running(const qint64 bytesReceived, const qint64 bytesTotal)
{
    emit results_ready(bytesReceived, _timer->elapsed());
}
