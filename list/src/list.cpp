#include "Studentai.h"
#include "Funkcijos.h"
#include <chrono>

using namespace std;

int main()
{

    list<string> Vardai_v = { "Petras", "Jonas", "Paulius", "Saulius", "Martynas", "Kornelijus", "Adomas", "Lukas", "Marius", "Kazimieras", "Dovydas", "Mantas", "Arnas", "Dziugas" };
    list<string> Vardai_m = { "Eva", "Paulina", "Sofija", "Gintare", "Skaiste", "Marija", "Lukrecija", "Kornelija", "Egle", "Kamile", "Auguste", "Meda", "Ruta" };
    list<string> Pavardes_v = { "Kazlauskas", "Vasiliauskas", "Petrauskas", "Paulauskas", "Urbonas", "Adomaitis", "Sadauskas", "Vaitkus", "Jankauskas", "Rimkus" };
    list<string> Pavardes_m = { "Kazlauskaite", "Vasiliauskiene", "Paulauskyte", "Vaitkute", "Jankauskaite", "Rimkute", "Adomaitiene", "Petrauskyte" };
    list<Studentas> studentai;

    int budas = 0;
    int pasirinkimas = 0;
    int rusiavimas = 0;
    int sk;
    Studentas S;
    //

    cout << "*****************************************************" << endl;
    cout << "Duomenu uzpildymo budas" << endl;
    cout << "1. Uzpildyti ranka" << endl;
    cout << "2. Uzpildyti pazymius automatiskai" << endl;
    cout << "3. Uzpildyti varda, pavarde bei pazymius automatiskai" << endl;
    cout << "4. Nuskaityti duomenis is failo" << endl;
    cout << "5. Generuoti failus" << endl;
    cout << "*****************************************************" << endl;

    while (true) {
        cout << "Jusu pasirinkimas: ";
        budas = IntInput();

        if (budas < 1 || budas > 5) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }


    cout << "**************************************" << endl;
    cout << "Kaip norite surusiuoti rezultatus?" << endl;
    cout << "1. Pagal galutini pazymi (mazejanciai)" << endl;
    cout << "2. Pagal galutini pazymi (didejanciai)" << endl;
    cout << "3. Pagal varda (A -> Z)" << endl;
    cout << "4. Pagal varda (Z -> A)" << endl;
    cout << "5. Pagal pavarde (A -> Z)" << endl;
    cout << "6. Pagal pavarde (Z -> A)" << endl;
    cout << "7. Nerusiuoti" << endl;
    while (true) {

        rusiavimas = IntInput();
        if (rusiavimas < 1 || rusiavimas > 7) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }

    cout << "----------------------------------" << endl;
    cout << "Pasirinktie galutinio balo skaiciavimo metoda: " << endl;
    cout << "1. Skaiciuoti naudojant vidurki" << endl;
    cout << "2. Skaiciuoti naudojant mediana" << endl;
    while (true) {

        cout << "Jusu pasirinkimas: ";
        S.pasirinkimas = IntInput();

        if (S.pasirinkimas != 1 && S.pasirinkimas != 2) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }

    // Pildymas ranka

    if (budas == 1) {
        while (true) {
            bool loop = false;
            cout << "Iveskite savo varda: ";

            S.vardas = StringInput();

            cout << "Iveskite savo pavarde: ";

            S.pavarde = StringInput();

            cout << "Iveskite egzamino bala [1 - 10]: " << endl;
            while (true) {
                cout << "Pazymys: ";
                S.egz = IntInput();

                if (S.egz < 1 || S.egz>10) {
                    cout << "Iveskite pazymi nuo 1 iki 10" << endl;
                }
                else break;
            }


            cout << "Iveskite atliktu namu darbu skaiciu: " << endl;
            while (true) {
                S.n = IntInput();
                if (S.n) break;
            }

            cout << "----------------------------------" << endl;
            S.nd.resize(S.n);
            cout << "Iveskite pazymi nuo [1 - 10] " << endl;
            for (int j = 0; j < S.n; j++) {
                while (true) {
                    cout << "Pazymys: ";
                    int pazymys = IntInput();

                    if (pazymys < 1 || pazymys > 10) {
                        cout << "Iveskite skaiciu nuo 1 iki 10" << endl;
                    }
                    else {
                        S.nd.push_back(pazymys);
                        break;
                    }
                    

                }
            }
            if (S.pasirinkimas == 1) {
                S.vid = Vidurkis(S.nd, S.n);
                S.galut = 0.4 * S.vid + 0.6 * S.egz;
            }
            else {
                S.medi = Mediana(S.nd);
                S.galut = 0.4 * S.medi + 0.6 * S.egz;
            }
            cout << "*******************************" << endl;
            studentai.push_back(S);

            cout << "0. Baigti" << endl;
            cout << "1. Testi" << endl;
            while (true) {
                sk = IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }

            if (sk == 0) {
                break;
            }
            else loop = true;
        }
    }

    // *************************************
    // Pazymiu automatinis pildymas

    if (budas == 2) {
        while (true) {
            bool loop = false;

            cout << "Iveskite savo varda: ";

            S.vardas = StringInput();

            cout << "Iveskite savo pavarde: ";

            S.pavarde = StringInput();

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distribution(1, 10);
            S.egz = distribution(gen);

            cout << "Iveskite atliktu namu darbu skaiciu: " << endl;
            while (true) {
                S.n = IntInput();
                if (S.n) break;
            }
            S.nd.resize(S.n);
            for (int j = 0; j < S.n; j++) {

                int pazymys = distribution(gen);
                S.nd.push_back(pazymys);
            }
            if (S.pasirinkimas == 1) {
                S.vid = Vidurkis(S.nd, S.n);
                S.galut = 0.4 * S.vid + 0.6 * S.egz;
            }
            else {
                S.medi = Mediana(S.nd);
                S.galut = 0.4 * S.medi + 0.6 * S.egz;
            }
            cout << "*******************************" << endl;
            studentai.push_back(S);

            cout << "0. Baigti" << endl;
            cout << "1. Testi" << endl;
            while (true) {
                sk = IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }

            if (sk == 0) {
                break;
            }
            else loop = true;
        }
    }

    //***************************************
    //Automatinis vardo bei pazymiu pildymas

    if (budas == 3) {
        while (true) {
            bool loop = false;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distribution(1, 10);
            uniform_int_distribution<int> lyties_num(0, 1); // 0 - vyras, 1 - moteris

            int lytis = lyties_num(gen);

            if (lytis == 0) {
                auto it_v = next(Vardai_v.begin(), uniform_int_distribution<int>(0, Vardai_v.size() - 1)(gen));
                auto it_pv = next(Pavardes_v.begin(), uniform_int_distribution<int>(0, Pavardes_v.size() - 1)(gen));
                S.vardas = *it_v;
                S.pavarde = *it_pv;
            }
            else {
                auto it_m = next(Vardai_m.begin(), uniform_int_distribution<int>(0, Vardai_m.size() - 1)(gen));
                auto it_pm = next(Pavardes_m.begin(), uniform_int_distribution<int>(0, Pavardes_m.size() - 1)(gen));
                S.vardas = *it_m;
                S.pavarde = *it_pm;
            }
            S.egz = distribution(gen);

            cout << "Iveskite atliktu namu darbu skaiciu: " << endl;
            while (true) {
                S.n = IntInput();
                if (S.n) break;
            }

            // Clear previous contents of S.nd list
            S.nd.clear();
            mt19937 rng;
            for (int j = 0; j < S.n; j++) {
                int grade = generateGrade(rng); // Assuming generateGrade() returns a valid grade
                S.nd.push_back(grade);
            }
            if (S.pasirinkimas == 1) {
                S.vid = Vidurkis(S.nd, S.n);
                S.galut = 0.4 * S.vid + 0.6 * S.egz;
            }
            else {
                S.medi = Mediana(S.nd);
                S.galut = 0.4 * S.medi + 0.6 * S.egz;
            }
            cout << "*******************************" << endl;
            studentai.push_back(S);

            cout << "0. Baigti" << endl;
            cout << "1. Testi" << endl;
            while (true) {
                sk = IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }

            if (sk == 0) {
                break;
            }
            else loop = true;
        }
    }

    // Nuskaitymas is failo

    if (budas == 4) {
        string filename = FailoPatikrinimas();
        readFile(filename, studentai);
    }

    // Failu generavimas

    if (budas == 5) {

        list<Studentas> blogi;
        list<string> fileSizes = { "1000", "10000", "100000", "1000000", "10000000" };

        for (const string& size : fileSizes) {

            auto startGenerate = chrono::high_resolution_clock::now();
            generateFile(size + ".txt", stoi(size));
            auto endGenerate = chrono::high_resolution_clock::now();
            auto durationGenerate = chrono::duration_cast<chrono::milliseconds>(endGenerate - startGenerate);
            cout << size << " sugeneravimas: " << durationGenerate.count() * 0.001 << " sekundziu" << endl;

            auto startRead = chrono::high_resolution_clock::now();
            readFile(size + ".txt", studentai);
            auto endRead = chrono::high_resolution_clock::now();
            auto durationRead = chrono::duration_cast<chrono::milliseconds>(endRead - startRead);
            cout << size << " nuskaitymas: " << durationRead.count() * 0.001 << " sekundziu" << endl;

            auto startSort = chrono::high_resolution_clock::now();
            sortStudents(studentai, rusiavimas);
            auto endSort = chrono::high_resolution_clock::now();
            auto durationSort = chrono::duration_cast<chrono::milliseconds>(endSort - startSort);
            cout << size << " rusiavimas: " << durationSort.count() * 0.001 << " sekundziu" << endl;


            auto startSeparate = chrono::high_resolution_clock::now();
            separateStudents(studentai,blogi);
            auto endSeparate = chrono::high_resolution_clock::now();
            auto durationSeparate = chrono::duration_cast<chrono::milliseconds>(endSeparate - startSeparate);
            cout << size << " paskirstymas i 2 grupes: " << durationSeparate.count() * 0.001 << " sekundziu" << std::endl;

           auto startgenerategeri = chrono::high_resolution_clock::now();
            generateSeperateFile(studentai, "geri" + size + ".txt");
            auto endgenerategeri = chrono::high_resolution_clock::now();
            auto durationgenerategeri = chrono::duration_cast<std::chrono::milliseconds>(endgenerategeri - startgenerategeri);
            cout << size << " geru studentu irasymas i faila:  " << durationgenerategeri.count() * 0.001 << " sekundziu" << std::endl;

            auto startgenerateblogi = chrono::high_resolution_clock::now();
            generateSeperateFile(blogi, "blogi" + size + ".txt");
            auto endgenerateblogi = chrono::high_resolution_clock::now();
            auto durationgenerateblogi = chrono::duration_cast<std::chrono::milliseconds>(endgenerateblogi - startgenerateblogi);
            cout << size << " blogu studentu irasymas i faila:  " << durationgenerateblogi.count() * 0.001 << " sekundziu" << std::endl;
           
            cout << endl;
            cout << size << " bendras testo laikas: " << durationRead.count() * 0.001 + durationSeparate.count() * 0.001 + durationSort.count() * 0.001 << " sekundziu" << endl;
            clearList(studentai, blogi);
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
        }
    }

    if (budas != 5) {

        sortStudents(studentai, rusiavimas);

        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)  /" << setw(20) << "Galutinis (Med.)" << endl;
        cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
        for (const auto& S : studentai) {
            if (S.pasirinkimas == 1) {
                cout << left << setw(15) << S.pavarde << setw(15) << S.vardas << setw(20) << fixed << setprecision(2) << S.galut << endl;
            }
            else {
                cout << left << setw(15) << S.pavarde << setw(15) << S.vardas << setw(20) << " " << setw(20) << fixed << setprecision(2) << S.galut << endl;
            }
        }
    }

}
