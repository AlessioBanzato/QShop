#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <iostream>

class Utente {
private:
    std::string username, password;
public:
    Utente (const std::string& =std::string(), const std::string& =std::string());
    const std::string& getUsername() const;
    const std::string& getPassword() const;
    void setUsername(const std::string&);
    void setPassword(const std::string&);
    virtual ~Utente() =default;
};

std::ostream& operator<<(std::ostream&, const Utente&);

#endif
