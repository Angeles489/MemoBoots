#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

#include "Card.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MemoaBoots");
    resize(300, 150);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *vbox = new QVBoxLayout;

    QLabel *label = new QLabel("Puchale play", this);
    vbox->addWidget(label);

    QPushButton *button = new QPushButton("msj 1", this);
    vbox->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);

    central->setLayout(vbox);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_buttonClicked()
{
    Card *cardWindow = new Card();
    cardWindow->show();
    this->close(); // Cierra la ventana principal
}