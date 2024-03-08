#pragma once
#include <vector>
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
    vector<int> nd;
    double vid;
    double galut;
    double medi;
    double pasirinkimas;
};
