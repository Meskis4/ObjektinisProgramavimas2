#include "Funkcijos.h"
#include "Studentai.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

double Mediana(list<int>& mas) {
    mas.sort();

    if (mas.size() % 2 == 0) {
        auto it1 = next(mas.begin(), mas.size() / 2 - 1);
        auto it2 = next(it1);
        return static_cast<double>(*it1 + *it2) / 2.0;
    }
    else {
        auto it = next(mas.begin(), mas.size() / 2);
        return static_cast<double>(*it);
    }
}

bool raides(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

double Vidurkis(list<int>& mas, int n) {
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
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return;
    }

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

void readFile(const string& fileName, list<Studentas>& studentai) {
    ifstream df(fileName);

    if (!df.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return;
    }

    string header;
    getline(df, header);

    stringstream headerStream(header);
    string token;
    int n = 0;

    while (getline(headerStream, token, ' ')) {
        if (token.find("ND") != string::npos) {
            n++;
        }
    }

    Studentas S;
    while (true) {
        df >> S.pavarde >> S.vardas;

        if (df.eof()) {
            break;
        }

        S.nd.clear();
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            df >> tmp;
            S.nd.push_back(tmp);
        }

        df >> S.egz;

        S.n = S.nd.size();

        if (S.pasirinkimas == 1) {
            S.vid = Vidurkis(S.nd, S.n);
            S.galut = 0.4 * S.vid + 0.6 * S.egz;
        }
        else {
            S.medi = Mediana(S.nd);
            S.galut = 0.4 * S.medi + 0.6 * S.egz;
        }

        studentai.push_back(S);
    }

    df.close();
}

void sortStudents(list<Studentas>& students, int rusiavimas) {
    if (rusiavimas == 1) {
        students.sort([](const Studentas& a, const Studentas& b) {
            return a.galut > b.galut;
            });
    }

    if (rusiavimas == 2) {
        students.sort([](const Studentas& a, const Studentas& b) {
            return a.galut < b.galut;
            });
    }

    if (rusiavimas == 3) {
        students.sort([](const Studentas& a, const Studentas& b) {
            return a.vardas < b.vardas;
            });
    }

    if (rusiavimas == 4) {
        students.sort([](const Studentas& a, const Studentas& b) {
            return a.vardas > b.vardas;
            });
    }

    if (rusiavimas == 5) {
        students.sort([](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
            });
    }
    if (rusiavimas == 6) {
        students.sort([](const Studentas & a, const Studentas& b) {
            return a.pavarde > b.pavarde;
            });
    }
}

void separateStudents(list<Studentas>& studentai, list<Studentas>& Blogi) {

    auto it = std::find_if(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.galut >= 5;
        });

    Blogi.splice(Blogi.end(), studentai, studentai.begin(), it);
    studentai.erase(studentai.begin(), it);
}

void generateSeperateFile(const list<Studentas>& studentai, const string& fileName) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)  /" << setw(20) << "Galutinis (Med.)" << endl;
        outFile << setfill('-') << setw(68) << "" << setfill(' ') << endl;
        for (const auto& S : studentai) {
            if (S.pasirinkimas == 1) {
                outFile << left << setw(15) << S.pavarde << setw(15) << S.vardas << setw(20) << fixed << setprecision(2) << S.galut << endl;
            }
            else {
                outFile << left << setw(15) << S.pavarde << setw(15) << S.vardas << setw(20) << " " << setw(20) << fixed << setprecision(2) << S.galut << endl;
            }
        }
        outFile.close();
    }
}

void clearList(list<Studentas>& studentai, list<Studentas>& Geri, list<Studentas>& Blogi) {
    studentai.clear();
    Geri.clear();
    Blogi.clear();
}
