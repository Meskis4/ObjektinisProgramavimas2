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
    while(true){
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
        string filename = FailoPatikrinimas();
        readFile(filename, studentai);
    }

    // Failu generavimas

    if (budas == 5) {
        vector<Studentas> geri;
        vector<Studentas> blogi;

        vector<string> fileSizes = {"100000", "1000000",};

        for (const string& size : fileSizes) {

            /*auto startGenerate = chrono::high_resolution_clock::now();
            generateFile(size + ".txt", stoi(size));
            auto endGenerate = chrono::high_resolution_clock::now();
            auto durationGenerate = chrono::duration_cast<chrono::milliseconds>(endGenerate - startGenerate);
            cout << size << " sugeneravimas: " << durationGenerate.count() * 0.001 << " sekundziu" << endl;*/

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
            separateStudents(studentai, blogi);
            auto endSeparate = chrono::high_resolution_clock::now();
            auto durationSeparate = chrono::duration_cast<chrono::milliseconds>(endSeparate - startSeparate);
            cout << size << " paskirstymas i 2 grupes: " << durationSeparate.count() * 0.001 << " sekundziu" << std::endl;

            auto startGenerateGeri = chrono::high_resolution_clock::now();
            generateSeperateFile(studentai, "geri" + size + ".txt");
            auto endGenerateGeri = chrono::high_resolution_clock::now();
            auto durationGenerateGeri = chrono::duration_cast<std::chrono::milliseconds>(endGenerateGeri - startGenerateGeri);
            cout << size << " geru studentu irasymas i faila:  " << durationGenerateGeri.count() * 0.001 << " sekundziu" << std::endl;

            auto startGenerateBlogi = chrono::high_resolution_clock::now();
            generateSeperateFile(blogi, "blogi" + size + ".txt");
            auto endGenerateBlogi = chrono::high_resolution_clock::now();
            auto durationGenerateBlogi = chrono::duration_cast<std::chrono::milliseconds>(endGenerateBlogi - startGenerateBlogi);
            cout << size << " blogu studentu irasymas i faila:  " << durationGenerateBlogi.count() * 0.001 << " sekundziu" << std::endl;
            cout << endl;
            cout << size << " bendras testo laikas: " << durationRead.count() * 0.001 + durationSeparate.count() * 0.001 + durationSort.count() * 0.001 + durationGenerateGeri.count() * 0.001 + durationGenerateBlogi.count() * 0.001 << " sekundziu" << endl;
            clearVectors(studentai, blogi);
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
