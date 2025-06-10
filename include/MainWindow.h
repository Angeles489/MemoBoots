#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_buttonClicked();
    void on_button2Clicked();

private:
    QLabel      *label_;
    QPushButton *button_;
    QPushButton *button2_;
    QLineEdit   *lineEdit_;
    QTextEdit   *textEdit_;
};
