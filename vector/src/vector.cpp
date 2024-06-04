#include "Studentai.h"
#include <chrono>

using namespace std;



int main()
{

    vector<string> Vardai_v = { "Petras", "Jonas", "Paulius", "Saulius", "Martynas", "Kornelijus", "Adomas", "Lukas", "Marius", "Kazimieras", "Dovydas", "Mantas", "Arnas", "Dziugas" };
    vector<string> Vardai_m = { "Eva", "Paulina", "Sofija", "Gintare", "Skaiste", "Marija", "Lukrecija", "Kornelija", "Egle", "Kamile", "Auguste", "Meda", "Ruta" };
    vector<string> Pavardes_v = { "Kazlauskas", "Vasiliauskas", "Petrauskas", "Paulauskas", "Urbonas", "Adomaitis", "Sadauskas", "Vaitkus", "Jankauskas", "Rimkus" };
    vector<string> Pavardes_m = { "Kazlauskaite", "Vasiliauskiene", "Paulauskyte", "Vaitkute", "Jankauskaite", "Rimkute", "Adomaitiene", "Petrauskyte" };
    vector<Studentas> studentai;

    int budas = 0;
    int pasirinkimas = 0;
    int rusiavimas = 0;
    int sk;
    Studentas S;

    cout << "*****************************************************" << endl;
    cout << "Programos " << endl;
    cout << "1. Uzpildyti ranka" << endl;
    cout << "2. Uzpildyti pazymius automatiskai" << endl;
    cout << "3. Uzpildyti varda, pavarde bei pazymius automatiskai" << endl;
    cout << "4. Nuskaityti duomenis is failo" << endl;
    cout << "5. Generuoti failus" << endl;
    cout << "6. Atskirti studentus i atskirus failus" << endl;
    cout << "7. Istestuoti 'Rule of five'" << endl;
    cout << "*****************************************************" << endl;

    while (true) {
        cout << "Jusu pasirinkimas: ";
        budas = S.IntInput();

        if (budas < 1 || budas > 7) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }

    if (budas != 7) {
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

            rusiavimas = S.IntInput();
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
            pasirinkimas = S.IntInput();

            if (pasirinkimas != 1 && pasirinkimas != 2) {
                cout << "Netinkamas pasirinkimas!" << endl;
            }
            else break;
        }
    };

    // Pildymas ranka

    if (budas == 1) {
        while (true) {
            S.ManualDataInput(pasirinkimas);
            studentai.push_back(S);

            cout << "Baigti: 0 " << endl;
            cout << "Testi: 1" << endl;
            while (true) {
                sk = S.IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }
            if (sk == 0)break;
        }
    }


    // *************************************
    // Pazymiu automatinis pildymas

    if (budas == 2) {
        while (true) {
            S.ManualNameInput(pasirinkimas);
            studentai.push_back(S);

            cout << "Baigti: 0 " << endl;
            cout << "Testi: 1" << endl;
            while (true) {
                sk = S.IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }
            if (sk == 0)break;
        }
    }

    //***************************************
    //Automatinis vardo bei pazymiu pildymas

    if (budas == 3) {
        while (true) {
            S.GenerateRandomData(Vardai_v, Vardai_m, Pavardes_v, Pavardes_m, pasirinkimas);
            studentai.push_back(S);

            cout << "Baigti: 0 " << endl;
            cout << "Testi: 1" << endl;
            while (true) {
                sk = S.IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }
            if (sk == 0)break;

        }
    }

    // Nuskaitymas is failo

    if (budas == 4) {
        string filename = S.FailoPatikrinimas();
        S.readFile(filename, studentai, pasirinkimas);
    }

    // Failu generavimas

    if (budas == 5) {
        vector<string> fileSizes = { "1000", "10000" };

        for (const string& size : fileSizes) {

            auto startGenerate = chrono::high_resolution_clock::now();
            S.generateFile(size + ".txt", stoi(size));
            auto endGenerate = chrono::high_resolution_clock::now();
            auto durationGenerate = chrono::duration_cast<chrono::milliseconds>(endGenerate - startGenerate);
            cout << size << " sugeneravimas: " << durationGenerate.count() * 0.001 << " sekundziu" << endl;

            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
        }
    }


    if (budas == 6) {
        vector<Studentas> blogi;

        vector<string> fileSizes = { "1000", "10000" };

        for (const string& size : fileSizes) {

            auto startRead = chrono::high_resolution_clock::now();
            S.readFile(size + ".txt", studentai, pasirinkimas);
            auto endRead = chrono::high_resolution_clock::now();
            auto durationRead = chrono::duration_cast<chrono::milliseconds>(endRead - startRead);
            cout << size << " nuskaitymas: " << durationRead.count() * 0.001 << " sekundziu" << endl;

            auto startSort = chrono::high_resolution_clock::now();
            S.sortStudents(studentai, rusiavimas);
            auto endSort = chrono::high_resolution_clock::now();
            auto durationSort = chrono::duration_cast<chrono::milliseconds>(endSort - startSort);
            cout << size << " rusiavimas: " << durationSort.count() * 0.001 << " sekundziu" << endl;


            auto startSeparate = chrono::high_resolution_clock::now();
            S.separateStudents(studentai, blogi);
            auto endSeparate = chrono::high_resolution_clock::now();
            auto durationSeparate = chrono::duration_cast<chrono::milliseconds>(endSeparate - startSeparate);
            cout << size << " paskirstymas i 2 grupes: " << durationSeparate.count() * 0.001 << " sekundziu" << std::endl;

            auto startGenerateGeri = chrono::high_resolution_clock::now();
            S.generateSeperateFile(studentai, "geri" + size + ".txt", pasirinkimas);
            auto endGenerateGeri = chrono::high_resolution_clock::now();
            auto durationGenerateGeri = chrono::duration_cast<std::chrono::milliseconds>(endGenerateGeri - startGenerateGeri);
            cout << size << " geru studentu irasymas i faila:  " << durationGenerateGeri.count() * 0.001 << " sekundziu" << std::endl;

            auto startGenerateBlogi = chrono::high_resolution_clock::now();
            S.generateSeperateFile(blogi, "blogi" + size + ".txt", pasirinkimas);
            auto endGenerateBlogi = chrono::high_resolution_clock::now();
            auto durationGenerateBlogi = chrono::duration_cast<std::chrono::milliseconds>(endGenerateBlogi - startGenerateBlogi);
            cout << size << " blogu studentu irasymas i faila:  " << durationGenerateBlogi.count() * 0.001 << " sekundziu" << std::endl;
            cout << endl;
            cout << size << " bendras testo laikas: " << durationRead.count() * 0.001 + durationSeparate.count() * 0.001 + durationSort.count() * 0.001 + durationGenerateGeri.count() * 0.001 + durationGenerateBlogi.count() * 0.001 << " sekundziu" << endl;
            S.clearVectors(studentai, blogi);
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
        }
    }

    if (budas == 7) {
        cout << " " << endl;
        cout << "***DEFAULT KONSTRUKTORIUS***" << endl;
        Studentas defaultStudent;
        cout << "Vardas: " << defaultStudent.getVardas() << endl;
        cout << "Pavarde: " << defaultStudent.getPavarde() << endl;
        cout << "N: " << defaultStudent.getN() << endl;
        cout << "Egz: " << defaultStudent.getEgz() << endl;
        cout << "Vidurkis: " << defaultStudent.getVidurkis() << endl;
        cout << "Galutinis: " << defaultStudent.getGalutinis() << endl;
        cout << "Mediana: " << defaultStudent.getMediana() << endl;
        cout << "ND: ";
        for (int grade : defaultStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;

        cout << " " << endl;
        cout << "***PARAMETRINIS KONSTRUKTORIUS***" << endl;
        vector<int> nd = { 8, 9, 10 };
        Studentas paramStudent("Jonas", "Jonaitis", 3, 9, nd, 9.0, 9.4, 9.0);
        cout << "Vardas: " << paramStudent.getVardas() << endl;
        cout << "Pavarde: " << paramStudent.getPavarde() << endl;
        cout << "N: " << paramStudent.getN() << endl;
        cout << "Egz: " << paramStudent.getEgz() << endl;
        cout << "Vidurkis: " << paramStudent.getVidurkis() << endl;
        cout << "Galutinis: " << paramStudent.getGalutinis() << endl;
        cout << "Mediana: " << paramStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : paramStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;

        cout << " " << endl;
        cout << "***COPY KONSTRUKTORIUS***" << endl;
        cout << "STUDENTO KOPIJA: " << endl;
        Studentas copiedStudent(paramStudent);
        cout << "Vardas: " << copiedStudent.getVardas() << endl;
        cout << "Pavarde: " << copiedStudent.getPavarde() << endl;
        cout << "N: " << copiedStudent.getN() << endl;
        cout << "Egz: " << copiedStudent.getEgz() << endl;
        cout << "Vidurkis: " << copiedStudent.getVidurkis() << endl;
        cout << "Galutinis: " << copiedStudent.getGalutinis() << endl;
        cout << "Mediana: " << copiedStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : copiedStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "-------------------------------" << endl;

        cout << "PARAMETRINIS STUDENTAS: " << endl;
        cout << "Vardas: " << paramStudent.getVardas() << endl;
        cout << "Pavarde: " << paramStudent.getPavarde() << endl;
        cout << "N: " << paramStudent.getN() << endl;
        cout << "Egz: " << paramStudent.getEgz() << endl;
        cout << "Vidurkis: " << paramStudent.getVidurkis() << endl;
        cout << "Galutinis: " << paramStudent.getGalutinis() << endl;
        cout << "Mediana: " << paramStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : paramStudent.getND()) {
            cout << grade << " ";
        }
        


        cout << " " << endl;
        cout << " " << endl;

        cout << "***COPY PRISKYRIMO OPERATORIUS***" << endl;
        cout << "PRISKIRTAS STUDENTAS: " << endl;
        Studentas assignedStudent;
        assignedStudent = paramStudent;
        cout << "Vardas: " << assignedStudent.getVardas() << endl;
        cout << "Pavarde: " << assignedStudent.getPavarde() << endl;
        cout << "N: " << assignedStudent.getN() << endl;
        cout << "Egz: " << assignedStudent.getEgz() << endl;
        cout << "Vidurkis: " << assignedStudent.getVidurkis() << endl;
        cout << "Galutinis: " << assignedStudent.getGalutinis() << endl;
        cout << "Mediana: " << assignedStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : paramStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "-------------------------------" << endl;


        cout << "PARAMETRINIS STUDENTAS: " << endl;
        cout << "Vardas: " << paramStudent.getVardas() << endl;
        cout << "Pavarde: " << paramStudent.getPavarde() << endl;
        cout << "N: " << paramStudent.getN() << endl;
        cout << "Egz: " << paramStudent.getEgz() << endl;
        cout << "Vidurkis: " << paramStudent.getVidurkis() << endl;
        cout << "Galutinis: " << paramStudent.getGalutinis() << endl;
        cout << "Mediana: " << paramStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : paramStudent.getND()) {
            cout << grade << " ";
        }

        cout << endl;

        cout << " " << endl;
        cout << "***MOVE KONSTRUKTORIUS***" << endl;
        cout << "PERKELTAS STUDENTAS: " << endl;
        Studentas movedStudent(std::move(paramStudent));
        cout << "Vardas: " << movedStudent.getVardas() << endl;
        cout << "Pavarde: " << movedStudent.getPavarde() << endl;
        cout << "N: " << movedStudent.getN() << endl;
        cout << "Egz: " << movedStudent.getEgz() << endl;
        cout << "Vidurkis: " << movedStudent.getVidurkis() << endl;
        cout << "Galutinis: " << movedStudent.getGalutinis() << endl;
        cout << "Mediana: " << movedStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : movedStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;

        cout << "-------------------------------" << endl;
        cout << "PRADINIS PARAMETRINIS STUDENTAS (PO PERKELIMO):" << endl;
        cout << "Vardas: " << paramStudent.getVardas() << endl;
        cout << "Pavarde: " << paramStudent.getPavarde() << endl;
        cout << "N: " << paramStudent.getN() << endl;
        cout << "Egz: " << paramStudent.getEgz() << endl;
        cout << "Vidurkis: " << paramStudent.getVidurkis() << endl;
        cout << "Galutinis: " << paramStudent.getGalutinis() << endl;
        cout << "Mediana: " << paramStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : paramStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;

       
        cout << " " << endl;
        cout << "***MOVE PRISKYRIMO OPERATORIUS***" << endl;
        Studentas anotherStudent;
        cout << "PRISKIRTAS MOVE STUDENTAS:" << endl;
        anotherStudent = std::move(movedStudent);
        cout << "Vardas: " << anotherStudent.getVardas() << endl;
        cout << "Pavarde: " << anotherStudent.getPavarde() << endl;
        cout << "N: " << anotherStudent.getN() << endl;
        cout << "Egz: " << anotherStudent.getEgz() << endl;
        cout << "Vidurkis: " << anotherStudent.getVidurkis() << endl;
        cout << "Galutinis: " << anotherStudent.getGalutinis() << endl;
        cout << "Mediana: " << anotherStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : anotherStudent.getND()) {
            cout << grade << " ";
        }
        cout << endl;

        cout << "-------------------------------" << endl;
        cout << "PRADINIS PERKELTAS STUDENTAS (PO PRISKYRIMO):" << endl;
        cout << "Vardas: " << movedStudent.getVardas() << endl;
        cout << "Pavarde: " << movedStudent.getPavarde() << endl;
        cout << "N: " << movedStudent.getN() << endl;
        cout << "Egz: " << movedStudent.getEgz() << endl;
        cout << "Vidurkis: " << movedStudent.getVidurkis() << endl;
        cout << "Galutinis: " << movedStudent.getGalutinis() << endl;
        cout << "Mediana: " << movedStudent.getMediana() << endl;
        cout << "ND:";
        for (int grade : movedStudent.getND()) {
            cout << grade << " ";
        }
    }

    if (budas != 5 && budas != 6 && budas != 7) {

        S.sortStudents(studentai, rusiavimas);

        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)  /" << setw(20) << "Galutinis (Med.)" << endl;
        cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
        for (const auto& S : studentai) {
            if (pasirinkimas == 1) {
                cout << left << setw(15) << S.getPavarde() << setw(15) << S.getVardas() << setw(20) << fixed << setprecision(2) << S.getGalutinis() << endl;
            }
            else {
                cout << left << setw(15) << S.getPavarde() << setw(15) << S.getVardas() << setw(20) << " " << setw(20) << fixed << setprecision(2) << S.getGalutinis() << endl;
            }
        }
    }

}
