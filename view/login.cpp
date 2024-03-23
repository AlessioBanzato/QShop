#include "login.h"

#include "view/utenteEditor.h"

#include <QHBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>
#include <QShortcut>

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


Login::Login() : home(nullptr),
                name(new QLabel("QShop", this)),
                usr(new QLabel("Username: ", this)),
                pwd(new QLabel("Password: ", this)),
                error(new QLabel("Username o password errato")),
                box_username(new QLineEdit(this)),
                box_password(new QLineEdit(this)),
                try_login(new QPushButton("Log In", this)),
                aggiungiUtente(new QPushButton("Aggiungi utente"))
{
    error->setStyleSheet("QLabel { color : red; }");
    error->hide();
    box_password->setEchoMode(QLineEdit::Password);

    QFont name_font;
    name_font.setPointSize(40);
    name_font.setBold(true);
    name->setFont(name_font);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(name, 0, Qt::AlignCenter | Qt::AlignLeft);
    mainLayout->insertSpacing(1, 125);


    QGridLayout* layout = new QGridLayout();
    layout->addWidget(usr, 1, 1);
    layout->addWidget(box_username, 1, 2);
    layout->addWidget(pwd, 2, 1);
    layout->addWidget(box_password, 2, 2);
    layout->addWidget(try_login, 4, 2);
    layout->addWidget(aggiungiUtente, 5, 2);
    layout->addWidget(error, 3, 2);

    QSpacerItem* up_space = new QSpacerItem(10, 200);
    layout->addItem(up_space, 0, 0, 1, 2);
    QSpacerItem* bottom_space = new QSpacerItem(10, 200);
    layout->addItem(bottom_space, 6, 0, 1, 2);

    mainLayout->addLayout(layout);

    QShortcut *loginShortcut = new QShortcut(QKeySequence("Return"),this);

    connect(loginShortcut, &QShortcut::activated, try_login, &QPushButton::click);
    connect(try_login, &QPushButton::pressed, this, &Login::logProcedure);

    connect(aggiungiUtente, &QPushButton::clicked, this, [](){
        UtenteEditor* tmp = new UtenteEditor();
        tmp->show();
    });

    this->setFixedSize(800, 500);
}

Utente* Login::verifyCredentials(const QString& usr, const QString& pwd) {
    QFile utenti("utenti.json");

    if(!utenti.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Errore nell'apertura del file 'utenti.json'";
        return nullptr;
    }

    QByteArray jsonData = utenti.readAll();
    utenti.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if (!jsonDocument.isArray()) {
        qDebug() << "'utenti.json' non è un file valido";
        return nullptr;
    }

    QJsonArray jsonArray = jsonDocument.array();
    for (const QJsonValue& jsonValue : jsonArray) {
        if (jsonValue.isObject()) {
            QJsonObject jsonObject = jsonValue.toObject();
            QString username = jsonObject["username"].toString();
            QString password = jsonObject["password"].toString();

            if (username == usr && password == pwd) {
                Utente* tmp = new Utente(username.toStdString(), password.toStdString());
                return tmp;
            }
        }
    }
    return nullptr;
}


// slot
void Login::logProcedure() {
    Utente* u = Login::verifyCredentials(box_username->text(),box_password->text());
    if(u) {
        this->close();
        home = new MainWindow(u);
        home->show();
    }
    else {
        box_password->clear();
        box_username->clear();
        error->show();
    }
}
