#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MemoBoots");
    resize(300, 150);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *vbox = new QVBoxLayout;

    QLabel *label = new QLabel("Puchale play", this);
    vbox->addWidget(label);

    QPushButton *button = new QPushButton("msj 1", this);
    vbox->addWidget(button);

    QPushButton *button2 = new QPushButton("msj 2", this);
    vbox->addWidget(button2);

    connect(button, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(button2, &QPushButton::clicked, this, &MainWindow::on_button2Clicked);

    central->setLayout(vbox);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_buttonClicked()
{
    QMessageBox::information(this, "Mensaje", "loba");
}

void MainWindow::on_button2Clicked()
{
    QMessageBox::information(this, "Mensaje", "loba 2");
}