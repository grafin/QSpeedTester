#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQmlEngine>
#include <QQmlContext>
#include <QUrl>
#include <QString>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QShortcut *_enterShortcut;
    QShortcut *_spaceShortcut;

public:
    explicit MainWindow(const QString &url, QWidget *parent = nullptr);
    ~MainWindow();

    const QUrl getUrl() const;
    bool testRunning() const;

private slots:
    void start_stop(const bool running);

public slots:
    void show_results(const qint64 size, const qint64 time);
    void show_error();

signals:
    void run_test();
    void update_gauge(const double value);
};

#endif // MAINWINDOW_H
