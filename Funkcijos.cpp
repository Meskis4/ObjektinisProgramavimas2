#include "Funkcijos.h"
#include "Studentai.h"
#include <algorithm>
#include <iostream>

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

double Vidurkis(vector<int>& mas, int n) {
    
    int suma = 0;
    for (int i : mas) {
        suma += i;
    }

    return static_cast<double>(suma) / n;
}

int IntInput() {
    int value;
    while (true) {
        try {
            cin >> value;
            if (cin.fail() || cin.peek() != '\n') {
                throw runtime_error("Netinkama ivestis! Iveskite sveikaji skaiciu.");
            }
            break;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}
