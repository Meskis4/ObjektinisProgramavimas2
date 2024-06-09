#pragma once
#include <string>

class Zmogus {
public:
    virtual ~Zmogus() = default;

    virtual std::string getVardas() const = 0;
    virtual std::string getPavarde() const = 0;

    virtual void setVardas(const std::string& vardas) = 0;
    virtual void setPavarde(const std::string& pavarde) = 0;
};
