#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img(":/Innopolis.jpg");

    setFixedSize(img.size());
    QPalette plt = this->palette();
    plt.setBrush(QPalette::Background, img);
    setPalette(plt);

    ui->centralwidget->setStyleSheet("background-color: rgba(255, 255, 255, 200)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
