#include "utenteEditor.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

UtenteEditor::UtenteEditor() : username(new EditorLine("Username:")),
                                password(new EditorLine("Password:")),
                                add(new QPushButton("Aggiungi"))
{
   QVBoxLayout* mainLayout = new QVBoxLayout(this);

   mainLayout->addWidget(username);
   mainLayout->addWidget(password);
   mainLayout->addWidget(add);

   connect(add, &QPushButton::clicked, this, &UtenteEditor::aggiungi);
}

// private slots
void UtenteEditor::aggiungi() {
    QJsonObject newUtente;

    newUtente["username"] = username->getText();
    newUtente["password"] = password->getText();

    QFile utenti("utenti.json");
    if (!utenti.open(QIODevice::ReadWrite)) {
        return;
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(utenti.readAll());

    QJsonArray jsonArray = jsonDoc.array();
    jsonArray.append(newUtente);
    jsonDoc.setArray(jsonArray);

    utenti.seek(0);
    utenti.write(jsonDoc.toJson());
    utenti.close();
    delete this;
}
