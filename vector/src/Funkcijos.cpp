#include "Studentai.h"

using namespace std;

Studentas::Studentas() : n_(0), egz_(0), vidurkis_(0), galutinis_(0), mediana_(0) {}

int Studentas::IntInput() {
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

void Studentas::sortStudents(vector<Studentas>& students, int rusiavimas) {
    if (rusiavimas == 1) {
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getGalutinis() > b.getGalutinis();
            });
    }

    if (rusiavimas == 2) {
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getGalutinis() < b.getGalutinis();
            });
    }

    if (rusiavimas == 3) {
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
            });
    }

    if (rusiavimas == 4) {
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() > b.getVardas();
            });
    }

    if (rusiavimas == 5) {
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
            });
    }

    if (rusiavimas == 6) {
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() > b.getPavarde();
            });
    }
}

string Studentas::allLetters() {
    string value;
    cin >> value;
    for (char c : value) {
        if (!isalpha(c)) {
            throw runtime_error("Ivesties klaida! Iveskite tik raides. ");
        }
    }
    return value;
}

string Studentas::StringInput() {
    string value;
    while (true) {
        try {
            value = allLetters();
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


double Studentas::Mediana() const {
    std::vector<int> sorted_nd = nd_;
    std::sort(sorted_nd.begin(), sorted_nd.end());
    if (sorted_nd.size() % 2 == 0) {
        double vidur1 = sorted_nd[sorted_nd.size() / 2 - 1];
        double vidur2 = sorted_nd[sorted_nd.size() / 2];
        return (vidur1 + vidur2) / 2.0;
    }
    else {
        return sorted_nd[sorted_nd.size() / 2];
    }
}

double Studentas::Vidurkis() const {
    int suma = 0;
    for (int i : nd_) {
        suma += i;
    }
    return static_cast<double>(suma) / n_;
}

void Studentas::ManualDataInput(int pasirinkimas) {
    
        std::cout << "Iveskite savo varda: ";
        setVardas(StringInput());

        std::cout << "Iveskite savo pavarde: ";
        setPavarde(StringInput());

        std::cout << "Iveskite egzamino bala [1 - 10]: ";
        while (true) {
            setEgz(IntInput());
            if (getEgz() < 1 || getEgz() > 10) {
                cout << "Netinkamas pasirinkimas! " << endl;
            }
            else break;
        }

        std::cout << "Iveskite atliktu namu darbu skaiciu: ";
        setN(IntInput());

        std::cout << "Iveskite pazymius nuo [1 - 10]: ";
        for (int i = 0; i < n_; i++) {
            int sum = 0;
            int nd;
            while (true) {
                std::cout << "Pazymys " << i + 1 << ": ";
                nd = IntInput();
                if (nd < 1 || nd > 10) {
                    cout << "Netinkamas pasirinkimas! " << endl;
                }
                else break;

                sum += nd;
                nd_.push_back(nd);
            }
    }

        if (pasirinkimas == 1) {
            setVidurkis( Vidurkis());
            setGalutinis(0.4 * getVidurkis() + 0.6 * getEgz());
        }
        if (pasirinkimas == 2) {
            setMediana(Mediana());
            setGalutinis(0.4 * getMediana() + 0.6 * getEgz());
        }
}
