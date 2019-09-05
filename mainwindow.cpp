#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(const QString &url, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _enterShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    _enterShortcut->setContext(Qt::ApplicationShortcut);
    _spaceShortcut = new QShortcut(QKeySequence(Qt::Key_Space), this);
    _spaceShortcut->setContext(Qt::ApplicationShortcut);

    ui->gaugeWidget->setAttribute(Qt::WA_AlwaysStackOnTop, true);
    ui->gaugeWidget->engine()->rootContext()->setContextProperty("MainWindow", this);
    ui->gaugeWidget->setSource(QUrl("qrc:/gauge.qml"));

    ui->urlEdit->setText(url);

    connect(
        ui->startStopButton, SIGNAL(toggled(bool)),
        this, SLOT(start_stop(const bool))
    );

    connect(
        _enterShortcut, SIGNAL(activated()),
        ui->startStopButton, SLOT(toggle())
    );

    connect(
        _spaceShortcut, SIGNAL(activated()),
        ui->startStopButton, SLOT(toggle())
    );
}

MainWindow::~MainWindow()
{
    delete _enterShortcut;
    delete _spaceShortcut;
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
    if(ui->startStopButton->isChecked() && time > 0)
        emit update_gauge(static_cast<double>(size) / static_cast<double>(time));
    else
        emit update_gauge(0);
}

void MainWindow::show_error()
{
}

void MainWindow::start_stop(const bool running)
{
    if(running)
    {
        emit run_test();
    }
    else
    {
        emit update_gauge(0);
    }
}
