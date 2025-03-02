#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sysinfo.h"
#include "memorywidget.h"
#include <QDebug>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCpuWidget(this)
    , memoryWidget(this)
{
    ui->setupUi(this);
    SysInfo::instans().init();
    ui->centralwidget->layout()->addWidget(&mCpuWidget);
    ui->centralwidget->layout()->addWidget(&memoryWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

