#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQmlEngine>
#include <QQmlContext>
#include <QUrl>

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const QUrl getUrl() const;
    bool testRunning() const;

private slots:
    void start_stop();

public slots:
    void show_results(const qint64 size, const qint64 time);
    void show_error();

signals:
    void run_test();
    void update_gauge(const double value);
};

#endif // MAINWINDOW_H
