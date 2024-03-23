#ifndef ALBUMEDITOR_H
#define ALBUMEDITOR_H

#include "view/itemEditor.h"

class MainWindow;

class AlbumEditor : public ItemEditor {
    Q_OBJECT
private:
    EditorLine* label;
    MainWindow* parentWindow;
public:
    AlbumEditor(const QString& =QString(),const QString& =QString(),const QString& =QString(),const QString& =QString(),
                const QString& ="./images/",const QString& =QString(),const QString& =QString(),const QString& =QString(),
                const QString& =QString());
    EditorLine* getLabel() const;
private slots:
    void applicaModifiche();
    void aggiungiProdotto();
};

#endif // ALBUMEDITOR_H
