#ifndef UTENTEEDITOR_H
#define UTENTEEDITOR_H

#include <QWidget>
#include <QPushButton>

#include "view/editorLine.h"

class UtenteEditor : public QWidget {
    Q_OBJECT
private:
    EditorLine* username, *password;
    QPushButton* add;
public:
    UtenteEditor();
private slots:
    void aggiungi();
};

#endif // UTENTEEDITOR_H
