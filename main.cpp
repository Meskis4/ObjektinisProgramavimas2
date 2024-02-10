#include <iostream>
#include <iomanip>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    int n;
    int egz;
    int nd[10];
    double vid;
    double galut;
};

const int s_kiek = 3;

int main()
{
    Studentas S[s_kiek];

    for (int i = 0; i < s_kiek; i++) {
        cout << "Iveskite savo varda: "; cin >> S[i].vardas;
        cout << "Iveskite savo pavarde: "; cin >> S[i].pavarde;
        cout << "Iveskite egzamino bala: "; cin >> S[i].egz;
        cout << "Iveskite atliktu namu darbu skaiciu: "; cin >> S[i].n;
        int paz = 0;
        for (int j = 0; j < S[i].n; j++) {
            cout << "Iveskite pazymi: "; cin >> S[i].nd[j];
            paz += S[i].nd[j];
        } 
        S[i].vid = double(paz) / S[i].n;
        S[i].galut = 0.4 * S[i].vid + 0.6 * S[i].egz;
    }
    cout << left << setw(15)<< "Pavarde" << setw(15) << "Vardas" << setw(20)<< "Galutinis (Vid.)" << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    for (int i = 0; i < s_kiek; i++) {
      cout << left<< setw(15)<< S[i].pavarde << setw(15) << S[i].vardas << setw(15)<<fixed<<setprecision(2)<< S[i].galut << endl;
    }
}
