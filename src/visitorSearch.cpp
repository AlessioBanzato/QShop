#include "src/visitorSearch.h"

visitorSearch::visitorSearch(std::string& s) : str(strToLower(s)), presenza(false) {}

void visitorSearch::visit(const Album& a) {
    std::string lower = strToLower(a.getTitolo() + a.getAutore() + a.getGenere() + a.getLabel() + std::to_string(a.getAnno()));
    presenza = lower.find(str) != std::string::npos;
    return;
}

void visitorSearch::visit(const Book& b) {
    std::string lower = strToLower(b.getTitolo() + b.getAutore() + b.getGenere() + b.getEditore() + b.getTipo()
                                   + std::to_string(b.getAnno()));
    presenza = lower.find(str) != std::string::npos;
    return;
}

void visitorSearch::visit(const Movie& m) {
    std::string lower = strToLower(m.getTitolo() + m.getAutore() + m.getGenere() + std::to_string(m.getLength())
                                   + std::to_string(m.getAnno()));
    presenza = lower.find(str) != std::string::npos;
    return;
}

bool visitorSearch::getPresenza() const { return presenza; }

std::string visitorSearch::strToLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return s;
}
