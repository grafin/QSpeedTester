#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gaugeWidget->engine()->rootContext()->setContextProperty("MainWindow", this);
    ui->gaugeWidget->setSource(QUrl("qrc:/gauge.qml"));

    connect(
        ui->startStopButton, SIGNAL(clicked()),
        this, SLOT(start_stop())
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

const QUrl MainWindow::getUrl() const
{
    return QUrl(ui->urlEdit->text());
}

bool MainWindow::testRunning() const
{
    return ui->startStopButton->isChecked();
}

void MainWindow::show_results(const qint64 size, const qint64 time)
{
    emit update_gauge(static_cast<double>(size) * 2 / static_cast<double>(time));
//    ui->speedGauge->rootContext()->setContextProperty("50", "20");
//    ui->speedGauge->rootObject()->children()[2]->setProperty(
//                "value", );
//    ui->sizeLabel->setNum(static_cast<int>(size));
//    ui->timeLabel->setNum(static_cast<int>(time));
//    ui->speedLabel->setNum(;
}

void MainWindow::show_error()
{
//    ui->sizeLabel->setText("Error");
//    ui->timeLabel->setText("Error");
//    ui->speedLabel->setText("Error");
}

void MainWindow::start_stop()
{
    emit run_test();
}
