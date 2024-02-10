#include <iostream>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    int n;
    int egz;
    int nd[10];
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
        for (int j = 0; j < S[i].n; j++) {
        cout << "Iveskite pazymi: "; cin >> S[i].nd[j];
        }    
    }
}
