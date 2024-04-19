#pragma once

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

public:
    virtual ~Zmogus() = default;
    virtual std::string getVardas() const = 0;
    virtual std::string getPavarde() const = 0;
};
