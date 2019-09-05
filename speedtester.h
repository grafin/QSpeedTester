#ifndef SPEEDTESTER_H
#define SPEEDTESTER_H

#include <QObject>
#include <QThread>
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
    QThread *_thread;
    QNetworkAccessManager *_webManager;
    QElapsedTimer *_timer;
    int _timeout;

public:
    explicit SpeedTester(QObject *parent = nullptr, const int timeout = 1000);
    ~SpeedTester();

private slots:
    void test_finished(QNetworkReply *reply);

public slots:
    void run_test(const QString &url);
    void test_running(const qint64 bytesReceived, const qint64 bytesTotal);

signals:
    void test_ready(const qint64 size, const qint64 time);
    void test_error();
};

#endif // SPEEDTESTER_H
