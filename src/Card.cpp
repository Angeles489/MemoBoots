#include "Card.h"
#include "TheoryQuestion.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include "User.h"

Card::Card(User* user, QWidget* parent)
    : QWidget(parent), user_(user), currentQuestionIndex(0)
    {
    setWindowTitle("Tarjeta de teoría");
    resize(400, 250);

    setStyleSheet(R"(
    QWidget {
        background-color: #fff7e6;
        font-family: 'Segoe UI';
    }
    QLabel {
        color: #333;
        font-size: 18px;
        padding: 10px;
    }
    QPushButton {
        background-color: #ffa726;
        border: none;
        color: white;
        font-size: 16px;
        padding: 12px;
        border-radius: 12px;
        margin: 6px 20px;
    }
    QPushButton:hover {
        background-color: #fb8c00;
    }
    QPushButton:pressed {
        background-color: #ef6c00;
    }
)");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);  // más espacio alrededor
    layout->setSpacing(25);                      // espacio entre widgets

    // Pregunta visualmente centrada
    questionLabel = new QLabel(this);
    questionLabel->setAlignment(Qt::AlignCenter);
    questionLabel->setWordWrap(true);
    layout->addWidget(questionLabel);

    // Botones de opciones
    for (int i = 0; i < 4; ++i) {
        QPushButton* btn = new QPushButton(this);
        btn->setMinimumHeight(40);
        btn->setCursor(Qt::PointingHandCursor); // Cambia cursor al pasar
        optionButtons.append(btn);
        layout->addWidget(btn);
        connect(btn, &QPushButton::clicked, this, &Card::checkAnswer);
    }

    try {
        loadQuestions();
        showQuestion(currentQuestionIndex);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
        close();
    }

}



void Card::loadQuestions()
{
    questions.clear();  // Limpia cualquier pregunta anterior si ya existen

    // ✅ Preguntas originales
    questions.append(new TheoryQuestion("¿Capital de Francia?", {"Madrid", "París", "Roma", "Berlín"}, 1));
    questions.append(new TheoryQuestion("Lenguaje usado en Qt?", {"Java", "C++", "Python", "Go"}, 1));
    questions.append(new TheoryQuestion("¿Fórmula del agua?", {"H2O", "CO2", "NaCl", "O2"}, 0));

    // 🧠 Preguntas de memorización y cultura general añadidas
    questions.append(new TheoryQuestion("¿Qué parte del cerebro controla la memoria?",
        {"Cerebelo", "Hipotálamo", "Hipocampo", "Tálamo"}, 2));

    questions.append(new TheoryQuestion("¿Qué idioma se habla en Irán?",
        {"Árabe", "Kurdo", "Turco", "Persa (farsi)"}, 3));

    questions.append(new TheoryQuestion("¿Qué año comenzó la Segunda Guerra Mundial?",
        {"1914", "1939", "1945", "1929"}, 1));

    questions.append(new TheoryQuestion("¿Cuál es la capital de Canadá?",
        {"Toronto", "Ottawa", "Montreal", "Vancouver"}, 1));

    questions.append(new TheoryQuestion("¿Cuántos elementos tiene la tabla periódica actualmente (2024)?",
        {"118", "108", "120", "112"}, 0));

    questions.append(new TheoryQuestion("¿Cuál es el río más largo del mundo?",
        {"Nilo", "Amazonas", "Yangtsé", "Mississippi"}, 1));

    questions.append(new TheoryQuestion("¿Qué científico propuso la teoría del electromagnetismo unificado?",
        {"Maxwell", "Newton", "Einstein", "Faraday"}, 0));

    questions.append(new TheoryQuestion("¿Qué país tiene más zonas horarias?",
        {"Estados Unidos", "Rusia", "Francia", "China"}, 2));

    questions.append(new TheoryQuestion("¿Cuál es el único metal que es líquido a temperatura ambiente?",
        {"Mercurio", "Plomo", "Zinc", "Aluminio"}, 0));

    // Inicializa con la primera pregunta
    currentQuestionIndex = 0;
    showQuestion(currentQuestionIndex);
}

void Card::showQuestion(int index)
{
    if (index >= questions.size()) {
    QString msg = user_
        ? QString("¡Felicidades, %1! Has terminado el test.").arg(user_->getName())
        : "¡Has terminado el test!";
    
    QMessageBox::information(this, "Test Completado", msg);
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