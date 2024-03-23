#include <QApplication>
#include <QLabel>
#include <QMessageBox>

#include "view/login.h"

#include "src/inventario.h"

void showConfirmationDialog() {
    Inventario& i = Inventario::getInventario();
    if(i.hasUnsavedChanges()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr,"Salva modifiche", "L'inventario ha subito modifiche, desideri salvarle?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
        if (reply == QMessageBox::Yes) {
            i.saveInventario();
        }
    }
    QApplication::quit();
}

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    Login l;
    l.show();
    QObject::connect(&app, &QApplication::aboutToQuit, &showConfirmationDialog);
    return app.exec();
}
