#include "editorLine.h"

EditorLine::EditorLine(const QString& n, const QString& b) : nome(new QLabel(n)), box(new QLineEdit(b)){
    QHBoxLayout* layout = new QHBoxLayout(this);

    layout->addWidget(nome);
    layout->addStretch(1);
    layout->addWidget(box);

    this->setFixedWidth(300);
}

QString EditorLine::getText() const {
    return box->text();
}
