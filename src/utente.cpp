#include "utente.h"

Utente::Utente(const std::string& u, const std::string& p) : username(u), password(p) {}

const std::string& Utente::getUsername() const { return username; }

const std::string& Utente::getPassword() const { return password; }

void Utente::setUsername(const std::string& u) { username = u; }

void Utente::setPassword(const std::string& p) { password = p; }

std::ostream& operator<<(std::ostream& os, const Utente& u) {
    return os << u.getUsername() << " - " << u.getPassword();
}
