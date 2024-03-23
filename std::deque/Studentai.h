#pragma once
#include <deque>
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
    deque<int> nd;
    double vid;
    double galut;
    double medi;
    double pasirinkimas;
};
