#pragma once
#include "Zmogus.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <cctype>
#include <fstream>
#include <sstream>
#include <algorithm>

class Studentas : public Zmogus {
private:
    std::string vardas_;
    std::string pavarde_;
    int n_;
    int egz_;
    std::vector<int> nd_;
    double vidurkis_;
    double galutinis_;
    double mediana_;

public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde, int n, int egz, const std::vector<int>& nd, double vidurkis, double galutinis, double mediana);
    ~Studentas();

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    Studentas(Studentas&& other) noexcept;
    Studentas& operator=(Studentas&& other) noexcept;

    std::string getVardas() const override { return vardas_; }
    std::string getPavarde() const override { return pavarde_; }
    int getN() const { return n_; }
    int getEgz() const { return egz_; }
    std::vector<int> getND() const { return nd_; }
    double getVidurkis() const { return vidurkis_; }
    double getGalutinis() const { return galutinis_; }
    double getMediana() const { return mediana_; }

    void setVardas(const std::string& vardas) override { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) override { pavarde_ = pavarde; }
    void setN(int n) { n_ = n; }
    void setEgz(int egz) { egz_ = egz; }
    void setND(const std::vector<int>& nd) { nd_ = nd; }
    void setVidurkis(double vidurkis) { vidurkis_ = vidurkis; }
    void setGalutinis(double galutinis) { galutinis_ = galutinis; }
    void setMediana(double mediana) { mediana_ = mediana; }

    int IntInput();
    void sortStudents(std::vector<Studentas>& students, int rusiavimas);
    std::string allLetters();
    std::string StringInput();
    double Mediana() const;
    double Vidurkis() const;
    void ManualDataInput(int pasirinkimas);
    int generateGrade();
    void ManualNameInput(int pasirinkimas);
    int generateND();
    void GenerateRandomData(const std::vector<std::string>& Vardai_v, const std::vector<std::string>& Vardai_m, const std::vector<std::string>& Pavardes_v, const std::vector<std::string>& Pavardes_m, int pasirinkimas);
    std::string FailoPatikrinimas();
    void readFile(const std::string& fileName, std::vector<Studentas>& studentai, int pasirinkimas);
    std::string intToString(int value);
    void generateFile(const std::string& fileName, int studentAmount);
    void separateStudents(std::vector<Studentas>& studentai, std::vector<Studentas>& Blogi);
    void generateSeperateFile(const std::vector<Studentas>& studentai, const std::string& fileName, int pasirinkimas);
    void clearVectors(std::vector<Studentas>& studentai, std::vector<Studentas>& Blogi);
    void printInfo();
    std::string Studentas::output() const;
};



