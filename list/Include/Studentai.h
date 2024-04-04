#pragma once
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <cctype>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    int n;
    int egz;
    list<int> nd;
    double vid;
    double galut;
    double medi;
    double pasirinkimas;
};
