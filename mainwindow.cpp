#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(
        ui->startStopButton, SIGNAL(clicked()),
        this, SLOT(run_test())
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_results(const qint64 size, const qint64 time)
{
    ui->sizeLabel->setNum(static_cast<int>(size));
    ui->timeLabel->setNum(static_cast<int>(time));
    ui->speedLabel->setNum(static_cast<double>(size) / 1024 / 1024 / static_cast<double>(time) * 1000);
}

void MainWindow::run_test()
{
    emit run_test(ui->urlEdit->text());
}
