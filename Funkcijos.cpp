#include "Funkcijos.h"
#include "Studentai.h"
#include <algorithm>

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

string StringInput() {
    string value;
    while (true) {
        try {
            cin >> value;
            if (!raides(value)) {
                throw runtime_error("Ivesties klaida! Iveskite tik raides. ");
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

string FailoPatikrinimas() {
    string filename;
    while (true) {
        try {
            cout << "Iveskite failo pavadinima: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Failas nerastas!");
            }
            file.close();
            break;
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return filename;
}

string intToString(int value) {
    return to_string(value);
}

int generateGrade(mt19937& rng) {
    uniform_int_distribution<int> distribution(1, 10);
    return distribution(rng);
}

int generateND(mt19937& rng) {
    uniform_int_distribution<int> distribution(5, 10);
    return distribution(rng);
}

void generateFile(const string& fileName, int studentAmount) {
    ofstream file(fileName);
    random_device rd;
    mt19937 rng(rd());

    int ndCount = generateND(rng);
    if (!file.is_open()) { cerr << "Nepavyko atidaryti failo!" << endl; return; }

    file << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= ndCount; ++i) {
        file << setw(10) << "ND" + intToString(i);
    }
    file << setw(10) << "Egz." << endl;

    for (int entry = 1; entry <= studentAmount; ++entry) {
        file << setw(20) << "Vardas" + intToString(entry) << setw(20) << "Pavarde" + intToString(entry);

        for (int i = 0; i < ndCount; ++i) {
            file << setw(10) << intToString(generateGrade(rng));
        }

        file << setw(10) << intToString(generateGrade(rng)) << endl;
    }

    file.close();
}
