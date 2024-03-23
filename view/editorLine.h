#ifndef EDITORLINE_H
#define EDITORLINE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

#include <QHBoxLayout>

class EditorLine : public QWidget {
    Q_OBJECT
private:
    QLabel* nome;
    QLineEdit* box;
public:
    EditorLine(const QString&,const QString& =QString());
    QString getText() const;
};

#endif // EDITORLINE_H
