#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(
        ui->startStopButton, SIGNAL(clicked(bool)),
        this, SLOT(run_test(bool))
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

void MainWindow::show_error()
{
    ui->sizeLabel->setText("Error");
    ui->timeLabel->setText("Error");
    ui->speedLabel->setText("Error");
}


void MainWindow::run_test(const bool enabled)
{
    qDebug() << enabled;
    emit run_test(ui->urlEdit->text());
}
