#include "Card.h"
#include "TheoryQuestion.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>

Card::Card(QWidget *parent)
    : QWidget(parent), currentQuestionIndex(0)
{
    setWindowTitle("Tarjeta de teoría");
    resize(400, 250);

    QVBoxLayout *layout = new QVBoxLayout(this);
    questionLabel = new QLabel(this);
    layout->addWidget(questionLabel);

    for (int i = 0; i < 4; ++i) {
        QPushButton *btn = new QPushButton(this);
        optionButtons.append(btn);
        layout->addWidget(btn);
        connect(btn, &QPushButton::clicked, this, &Card::checkAnswer);
    }

    try {
        loadQuestions();
        showQuestion(currentQuestionIndex);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
        close();
    }
}

void Card::loadQuestions()
{
    questions.append(new TheoryQuestion("¿Capital de Francia?", {"Madrid", "París", "Roma", "Berlín"}, 1));
    questions.append(new TheoryQuestion("Lenguaje usado en Qt?", {"Java", "C++", "Python", "Go"}, 1));
    questions.append(new TheoryQuestion("¿Fórmula del agua?", {"H2O", "CO2", "NaCl", "O2"}, 0));
}

void Card::showQuestion(int index)
{
    if (index >= questions.size()) {
        QMessageBox::information(this, "Fin", "¡Has terminado todas las preguntas!");
        close();
        return;
    }

    Question *q = questions[index];
    questionLabel->setText(q->getText());

    QStringList options = q->getOptions();
    for (int i = 0; i < optionButtons.size(); ++i) {
        optionButtons[i]->setText(options[i]);
        optionButtons[i]->setProperty("answerIndex", i);
    }
}

void Card::checkAnswer()
{
    QPushButton* clicked = qobject_cast<QPushButton*>(sender());
    if (!clicked) return;  // por seguridad: puede ser null

    int selected = clicked->property("answerIndex").toInt();
    Question* q = questions[currentQuestionIndex];

    if (q->checkAnswer(selected)) {
        QMessageBox::information(this, "Correcto", "¡Respuesta correcta!");
    } else {
        QMessageBox::warning(this, "Incorrecto", "Respuesta incorrecta");
    }

    currentQuestionIndex++;
    showQuestion(currentQuestionIndex);
}