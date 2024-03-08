#pragma once
#include "Studentai.h"

double Mediana(vector<int>& mas);

double raides(const string& str);

double Vidurkis(vector<int>& mas, int n);

int IntInput();

string StringInput();

string FailoPatikrinimas();

int generateGrade(mt19937& rng);

int generateND(mt19937& rng);

void generateFile(const string& fileName, int studentAmount);

void readFile(const string& fileName, vector<Studentas>& studentai);

void sortStudents(vector<Studentas>& students, int rusiavimas);
