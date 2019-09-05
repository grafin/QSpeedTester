#ifndef SPEEDTESTER_H
#define SPEEDTESTER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QEventLoop>
#include <QElapsedTimer>

#include <QDebug>

class SpeedTester : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *_webManager;
    QElapsedTimer *_timer;
    int _timeout;

public:
    explicit SpeedTester(QObject *parent = nullptr, const int timeout = 1000);
    void init();
    ~SpeedTester();

private slots:
    void reply_ready(QNetworkReply *reply);

public slots:
    void run_test(const QUrl &url);
    void test_running(const qint64 bytesReceived, const qint64 bytesTotal);

signals:
    void results_ready(const qint64 size, const qint64 time);
    void test_error();
    void test_finished(const QUrl &url);
};

#endif // SPEEDTESTER_H
