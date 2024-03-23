#pragma once
#include "Studentai.h"

double Mediana(list<int>& mas);

double Vidurkis(list<int>& mas, int n);

bool raides(const string& str);

int IntInput();

string StringInput();

string FailoPatikrinimas();

int generateGrade(mt19937& rng);

int generateND(mt19937& rng);

void generateFile(const string& fileName, int studentAmount);

void readFile(const string& fileName, list<Studentas>& studentai);

void sortStudents(list<Studentas>& students, int rusiavimas);

void separateStudents(list<Studentas>& studentai, list<Studentas>& Blogi);

void generateSeperateFile(const list<Studentas>& studentai, const string& fileName);

void clearList(list<Studentas>& studentai, list<Studentas>& Blogi);
