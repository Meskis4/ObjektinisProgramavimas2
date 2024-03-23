#pragma once
#include "Studentai.h"

double Mediana(deque<int>& mas);

double raides(const string& str);

double Vidurkis(deque<int>& mas, int n);

int IntInput();

string StringInput();

string FailoPatikrinimas();

int generateGrade(mt19937& rng);

int generateND(mt19937& rng);

void generateFile(const string& fileName, int studentAmount);

void readFile(const string& fileName, deque<Studentas>& studentai);

void sortStudents(deque<Studentas>& students, int rusiavimas);

void separateStudents(deque<Studentas>& studentai, deque<Studentas>& Blogi);

void generateSeperateFile(const deque<Studentas>& studentai, const string& fileName);

void clearDeque(deque<Studentas>& studentai, deque<Studentas>& Blogi);
