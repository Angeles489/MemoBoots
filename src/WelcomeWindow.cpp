#include "WelcomeWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QRandomGenerator>

#include "WelcomeWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QRandomGenerator>

WelcomeWindow::WelcomeWindow(QWidget* parent)
    : QWidget(parent) {
    setWindowTitle("Bienvenido");
    resize(400, 280);

    // 🎨 Estilos
    setStyleSheet(R"(
        QWidget {
            background-color: #fffaec;
            font-family: 'Segoe UI', sans-serif;
        }

        QLabel#titleLabel {
            color: #e65100;
            font-size: 24px;
            font-weight: bold;
        }

        QLineEdit {
            padding: 10px;
            border: 2px solid #ffa726;
            border-radius: 10px;
            font-size: 16px;
            background-color: #fff3e0;
        }

        QLineEdit:focus {
            border: 2px solid #fb8c00;
            background-color: #fff8e1;
        }

        QPushButton {
            background-color: #ff9800;
            color: white;
            font-size: 16px;
            padding: 10px 20px;
            border: none;
            border-radius: 12px;
            min-height: 40px;
        }

        QPushButton:hover {
            background-color: #fb8c00;
        }

        QPushButton:pressed {
            background-color: #ef6c00;
        }
    )");

    // 📦 Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 30, 40, 30);
    layout->setSpacing(20);

    QLabel* title = new QLabel("👋 Bienvenido a <b>MemoBoots</b>", this);
    title->setObjectName("titleLabel");
    title->setAlignment(Qt::AlignCenter);

    nameInput_ = new QLineEdit(this);
    nameInput_->setPlaceholderText("Ingresa tu nombre");

    QPushButton* acceptButton = new QPushButton("Comenzar", this);

    layout->addWidget(title);
    layout->addWidget(nameInput_);
    layout->addStretch();
    layout->addWidget(acceptButton);

    connect(acceptButton, &QPushButton::clicked, this, &WelcomeWindow::onAccept);

    // 🔁 ANIMACIÓN DE LATIDO (por opacidad)
    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(acceptButton);
    acceptButton->setGraphicsEffect(effect);

    QPropertyAnimation* opacityAnim = new QPropertyAnimation(effect, "opacity");
    opacityAnim->setDuration(1000);
    opacityAnim->setStartValue(1.0);
    opacityAnim->setKeyValueAt(0.5, 0.7);
    opacityAnim->setEndValue(1.0);
    opacityAnim->setLoopCount(-1);
    opacityAnim->start(QAbstractAnimation::DeleteWhenStopped);

    // ✨ PARTICULAS FLOTANTES SIN FONDO
    QTimer* particleTimer = new QTimer(this);
    connect(particleTimer, &QTimer::timeout, this, [=]() {
        QLabel* star = new QLabel(this);
        star->setText("✨");
        star->setStyleSheet("font-size: 16px; background-color: transparent;");
        star->setAttribute(Qt::WA_TranslucentBackground);
        star->setAttribute(Qt::WA_NoSystemBackground);
        star->setAttribute(Qt::WA_OpaquePaintEvent, false);

        int x = QRandomGenerator::global()->bounded(width());
        star->move(x, height());
        star->show();

        QPropertyAnimation* anim = new QPropertyAnimation(star, "pos");
        anim->setDuration(4000);
        anim->setStartValue(QPoint(x, height()));
        anim->setEndValue(QPoint(x, -30));
        anim->setEasingCurve(QEasingCurve::OutQuad);
        connect(anim, &QPropertyAnimation::finished, star, &QLabel::deleteLater);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
    });
    particleTimer->start(600);
}

void WelcomeWindow::onAccept() {
    QString name = nameInput_->text().trimmed();
    if (!name.isEmpty()) {
        User* user = new User(name);
        emit userReady(user);
        close();  // Cierra esta ventana
    }
}