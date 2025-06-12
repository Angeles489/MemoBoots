#include <QApplication>
#include <QDebug>
#include "WelcomeWindow.h"
#include "MainWindow.h"
#include "User.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    WelcomeWindow* welcome = new WelcomeWindow();
    welcome->show();

    QObject::connect(welcome, &WelcomeWindow::userReady, [&](User* user) {
        // Ejemplo de sobrecarga ==
        User admin("Ana");
        if (*user == admin) {
            qDebug() << "Bienvenida administradora:" << *user;
        } else {
            qDebug() << "Usuario normal:" << *user;
        }

        // Crear y mostrar ventana principal
        MainWindow* main = new MainWindow();
        main->setUser(user);
        main->show();
    });

    return app.exec();
}