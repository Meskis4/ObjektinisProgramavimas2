#pragma once
#include "Studentai.h"

double Mediana(std::list<int>& mas);

double Vidurkis(std::list<int>& mas, int n);

bool raides(const std::string& str);

int IntInput();

string StringInput();

string FailoPatikrinimas();

int generateGrade(std::mt19937& rng);

int generateND(std::mt19937& rng);

void generateFile(const std::string& fileName, int studentAmount);

void readFile(const std::string& fileName, std::list<Studentas>& studentai);

void sortStudents(std::list<Studentas>& students, int rusiavimas);

void separateStudents(list<Studentas>& studentai, list<Studentas>& Blogi);

void generateSeperateFile(const std::list<Studentas>& studentai, const std::string& fileName);

void clearList(std::list<Studentas>& studentai, std::list<Studentas>& Geri, std::list<Studentas>& Blogi);
