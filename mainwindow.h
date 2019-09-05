#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void run_test(const bool enabled);

public slots:
    void show_results(const qint64 size, const qint64 time);
    void show_error();

signals:
    void run_test(const QString &url);
};

#endif // MAINWINDOW_H
