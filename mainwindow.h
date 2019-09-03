#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void run_test();

public slots:
    void show_results(const qint64 size, const qint64 time);

signals:
    void run_test(const QString &url);
};

#endif // MAINWINDOW_H
