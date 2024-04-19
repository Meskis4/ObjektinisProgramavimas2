#pragma once
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

using namespace std;
class Studentas {
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
    ~Studentas();
    Studentas(const Studentas& other);             //copy konstruktorius
    Studentas& operator=(const Studentas& s);     // copy priskyrimo operatorius
    Studentas(Studentas&& s);                     // move konstruktorius 
    Studentas& operator=(Studentas&& s);          // move priskyrimo operatorius


    //Get'eriai
    std::string getVardas()const { return vardas_; }
    std::string getPavarde() const { return pavarde_; }
    int getN() const { return n_; }
    int getEgz() const { return egz_; }
    std::vector<int> getND() const { return nd_; }
    double getVidurkis() const { return vidurkis_; }
    double getGalutinis() const { return galutinis_; }
    double getMediana() const { return mediana_; }

    //Set'eriai
    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    void setN(int n) { n_ = n; }
    void setEgz(int egz) { egz_ = egz; }
    void setND(const vector<int>& nd) { nd_ = nd; }
    void setVidurkis(double vidurkis) { vidurkis_ = vidurkis; }
    void setGalutinis(double galutinis) { galutinis_ = galutinis; }
    void setMediana(double mediana) { mediana_ = mediana; }

    //Metodai

    int IntInput();
    void sortStudents(vector<Studentas>& students, int rusiavimas);
    string allLetters();
    string StringInput();
    double Mediana() const;
    double Vidurkis() const;
    void ManualDataInput(int pasirinkimas);
    int generateGrade();
    void ManualNameInput(int pasirinkimas);
    int generateND();
    void GenerateRandomData(const std::vector<std::string>& Vardai_v, const std::vector<std::string>& Vardai_m, const std::vector<std::string>& Pavardes_v, const std::vector<std::string>& Pavardes_m, int pasirinkimas);
    string FailoPatikrinimas();
    void readFile(const string& fileName, vector<Studentas>& studentai, int pasirinkimas);
    string intToString(int value);
    void generateFile(const std::string& fileName, int studentAmount);
    void separateStudents(vector<Studentas>& studentai, vector<Studentas>& Blogi);
    void generateSeperateFile(const std::vector<Studentas>& studentai, const std::string& fileName, int pasirinkimas);
    void clearVectors(vector<Studentas>& studentai, vector<Studentas>& Blogi);
};
