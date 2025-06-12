#include "MainWindow.h"
#include "Card.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("MemoaBoots");
    resize(300, 200);

    // Estilos modernos y llamativos
    setStyleSheet(R"(
        QWidget {
            background-color: #fff8e1;
            font-family: 'Segoe UI', sans-serif;
        }

        QLabel#title {
            font-size: 26px;
            color: #e65100;
            font-weight: bold;
        }

        QLabel#subtitle {
            font-size: 14px;
            color: #555;
            padding-bottom: 10px;
        }

        QPushButton {
            background-color: #ffa726;
            color: white;
            font-size: 16px;
            padding: 12px 20px;
            border: none;
            border-radius: 12px;
            margin: 10px 30px;
        }

        QPushButton:hover {
            background-color: #fb8c00;
        }

        QPushButton:pressed {
            background-color: #ef6c00;
        }
    )");

    QVBoxLayout *vbox = new QVBoxLayout;

    QLabel *title = new QLabel("MemoaBoots", this);
    title->setAlignment(Qt::AlignCenter);
    title->setObjectName("title");

    QLabel *subtitle = new QLabel("🧠 ¡Aprende de forma interactiva y divertida!", this);
    subtitle->setAlignment(Qt::AlignCenter);
    subtitle->setObjectName("subtitle");

    QPushButton *button = new QPushButton("Comenzar Test", this);
    connect(button, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);

    vbox->addStretch();
    vbox->addWidget(title);
    vbox->addWidget(subtitle);
    vbox->addSpacing(20);
    vbox->addWidget(button, 0, Qt::AlignCenter);
    vbox->addStretch();

    // CORREGIDO: ahora sí se declara central
    QWidget *central = new QWidget(this);
    central->setLayout(vbox);
    setCentralWidget(central);
}

MainWindow::~MainWindow() {}

void MainWindow::on_buttonClicked()
{
    Card *cardWindow = new Card(currentUser_);
    cardWindow->show();
    this->close();
}

void MainWindow::setUser(User* user) {
    currentUser_ = user;
}