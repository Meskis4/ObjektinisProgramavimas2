#include "Funkcijos.h"
#include "Studentai.h"
#include "algorithm"

double Mediana(vector<int>& mas) {
    sort(mas.begin(), mas.end());

    if (mas.size() % 2 == 0) {
        double vidur1 = mas[mas.size() / 2 - 1];
        double vidur2 = mas[mas.size() / 2];
        return double((vidur1 + vidur2) / 2.0);
    }
    else {
        return double(mas[mas.size() / 2]);
    }
}

double raides(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
