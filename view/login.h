#ifndef LOGIN_H
#define LOGIN_H

// Schermata di login, prima finestra visualizzata

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "view/mainWindow.h"

class Login : public QWidget {
    Q_OBJECT
private:
    MainWindow* home;
    QLabel* name, *usr, *pwd, *error;
    QLineEdit* box_username, *box_password;
    QPushButton* try_login, *aggiungiUtente;
public:
    Login();
    Utente* verifyCredentials(const QString&, const QString&);
private slots:
    void logProcedure();
};

#endif // LOGIN_H
