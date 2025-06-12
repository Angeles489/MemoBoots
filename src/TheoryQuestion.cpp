#include "TheoryQuestion.h"
#include <stdexcept>

TheoryQuestion::TheoryQuestion(const QString &text, const QStringList &options, int correctIndex)
    : text_(text), options_(options), correctIndex_(correctIndex)
{
    if (correctIndex < 0 || correctIndex >= options.size()) {
        throw std::invalid_argument("Índice fuera de rango");
    }
}

QString TheoryQuestion::getText() const {
    return text_;
}

QStringList TheoryQuestion::getOptions() const {
    return options_;
}

bool TheoryQuestion::checkAnswer(int index) const {
    return index == correctIndex_;
}