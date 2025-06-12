#include "MainWindow.h"
#include "Card.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MemoaBoots");
    resize(300, 200);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *vbox = new QVBoxLayout;

    label_ = new QLabel("Púchale play", this);
    vbox->addWidget(label_);

    button_ = new QPushButton("msj 1", this);
    vbox->addWidget(button_);
    connect(button_, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);

    lineEdit_ = new QLineEdit(this);
    vbox->addWidget(lineEdit_);

    textEdit_ = new QTextEdit(this);
    vbox->addWidget(textEdit_);

    central->setLayout(vbox);
}

MainWindow::~MainWindow() {}

void MainWindow::on_buttonClicked()
{
    Card *cardWindow = new Card();
    cardWindow->show();
    this->close();
}