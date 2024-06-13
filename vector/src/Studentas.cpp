#include "Studentas.h"
using namespace std;

Studentas::Studentas()
    : vardas_(""), pavarde_(""), n_(0), egz_(0), vidurkis_(0), galutinis_(0), mediana_(0) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde, int n, int egz, const std::vector<int>& nd, double vidurkis, double galutinis, double mediana)
    : vardas_(vardas), pavarde_(pavarde), n_(n), egz_(egz), nd_(nd), vidurkis_(vidurkis), galutinis_(galutinis), mediana_(mediana) {}

Studentas::~Studentas() {}

// Copy konstruktorius
Studentas::Studentas(const Studentas& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_), n_(other.n_), egz_(other.egz_), nd_(other.nd_), vidurkis_(other.vidurkis_), galutinis_(other.galutinis_), mediana_(other.mediana_) {}

// Copy priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other) {
    if (this == &other) return *this;

    vardas_ = other.vardas_;
    pavarde_ = other.pavarde_;
    n_ = other.n_;
    egz_ = other.egz_;
    nd_ = other.nd_;
    vidurkis_ = other.vidurkis_;
    galutinis_ = other.galutinis_;
    mediana_ = other.mediana_;

    return *this;
}

// Move konstruktorius
Studentas::Studentas(Studentas&& other) noexcept
    : vardas_(""), pavarde_(""), n_(0), egz_(0), nd_(), vidurkis_(0), galutinis_(0), mediana_(0) {
    swap(vardas_, other.vardas_);
    swap(pavarde_, other.pavarde_);
    swap(n_, other.n_);
    swap(egz_, other.egz_);
    swap(nd_, other.nd_);
    swap(vidurkis_, other.vidurkis_);
    swap(galutinis_, other.galutinis_);
    swap(mediana_, other.mediana_);
}

// Move priskyrimo operatorius
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this == &other) return *this;

    swap(vardas_, other.vardas_);
    swap(pavarde_, other.pavarde_);
    swap(n_, other.n_);
    swap(egz_, other.egz_);
    swap(nd_, other.nd_);
    swap(vidurkis_, other.vidurkis_);
    swap(galutinis_, other.galutinis_);
    swap(mediana_, other.mediana_);

    return *this;
}

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
    switch (rusiavimas) {
    case 1:
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getGalutinis() > b.getGalutinis();
            });
        break;
    case 2:
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getGalutinis() < b.getGalutinis();
            });
        break;
    case 3:
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
            });
        break;
    case 4:
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() > b.getVardas();
            });
        break;
    case 5:
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
            });
        break;
    case 6:
        sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() > b.getPavarde();
            });
        break;
    }
}

string Studentas::allLetters() {
    string value;
    cin >> value;
    for (char c : value) {
        if (!isalpha(c)) {
            throw runtime_error("Ivesties klaida! Iveskite tik raides.");
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

    vector<int> sorted_nd = nd_;
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
    return static_cast<double>(suma) / nd_.size();
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
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }

    std::cout << "Iveskite atliktu namu darbu skaiciu: ";
    setN(IntInput());

    std::cout << "Iveskite pazymius nuo [1 - 10]: ";
    for (int i = 0; i < n_; i++) {
        int nd;
        while (true) {
            std::cout << "Pazymys " << i + 1 << ": ";
            nd = IntInput();
            if (nd < 1 || nd > 10) {
                cout << "Netinkamas pasirinkimas!" << endl;
            }
            else break;
        }
        nd_.push_back(nd);
    }

    if (pasirinkimas == 1) {
        setVidurkis(Vidurkis());
        setGalutinis(0.4 * getVidurkis() + 0.6 * getEgz());
    }
    if (pasirinkimas == 2) {
        setMediana(Mediana());
        setGalutinis(0.4 * getMediana() + 0.6 * getEgz());
    }
}



int Studentas::generateGrade() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1, 10);
    return distribution(rng);
}

void Studentas::ManualNameInput(int pasirinkimas) {
    std::cout << "Iveskite savo varda: ";
    setVardas(StringInput());

    std::cout << "Iveskite savo pavarde: ";
    setPavarde(StringInput());

    std::cout << "Iveskite atliktu namu darbu skaiciu: ";
    setN(IntInput());

    setEgz(generateGrade());

    for (int i = 0; i < n_; i++) {
        int nd = generateGrade();
        nd_.push_back(nd);
    }

    if (pasirinkimas == 1) {
        setVidurkis(Vidurkis());
        setGalutinis(0.4 * getVidurkis() + 0.6 * getEgz());
    }
    if (pasirinkimas == 2) {
        setMediana(Mediana());
        setGalutinis(0.4 * getMediana() + 0.6 * getEgz());
    }
}

int Studentas::generateND() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(6, 6);
    return distribution(rng);
}

void Studentas::GenerateRandomData(const std::vector<std::string>& Vardai_v, const std::vector<std::string>& Vardai_m, const std::vector<std::string>& Pavardes_v, const std::vector<std::string>& Pavardes_m, int pasirinkimas) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 10);
    std::uniform_int_distribution<int> lyties_num(0, 1); // 0 - vyras, 1 - moteris

    int lytis = lyties_num(gen);

    if (lytis == 0) {
        setVardas(Vardai_v[std::uniform_int_distribution<int>(0, Vardai_v.size() - 1)(gen)]);
        setPavarde(Pavardes_v[std::uniform_int_distribution<int>(0, Pavardes_v.size() - 1)(gen)]);
    }
    else {
        setVardas(Vardai_m[std::uniform_int_distribution<int>(0, Vardai_m.size() - 1)(gen)]);
        setPavarde(Pavardes_m[std::uniform_int_distribution<int>(0, Pavardes_m.size() - 1)(gen)]);
    }
    setEgz(distribution(gen));

    setN(generateND());

    int sum = 0;
    for (int i = 0; i < getN(); i++) {
        int nd = generateGrade();
        sum += nd;
        nd_.push_back(nd);
    }

    if (pasirinkimas == 1) {
        setVidurkis(Vidurkis());
        setGalutinis(0.4 * getVidurkis() + 0.6 * getEgz());
    }
    else {
        setMediana(Mediana());
        setGalutinis(0.4 * getMediana() + 0.6 * getEgz());
    }
}

string Studentas::FailoPatikrinimas() {
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

void Studentas::readFile(const string& fileName, vector<Studentas>& studentai, int pasirinkimas) {
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

    while (true) {
        df >> pavarde_ >> vardas_;

        if (df.eof()) {
            break;
        }

        nd_.clear();
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            df >> tmp;
            nd_.push_back(tmp);
        }

        df >> egz_;

        setN(nd_.size());

        if (pasirinkimas == 1) {
            setVidurkis(Vidurkis());
            setGalutinis(0.4 * getVidurkis() + 0.6 * getEgz());
        }
        else {
            setMediana(Mediana());
            setGalutinis(0.4 * getMediana() + 0.6 * getEgz());
        }
        studentai.push_back(*this);
    }

    df.close();
}

string Studentas::intToString(int value) {
    return to_string(value);
}

void Studentas::generateFile(const string& fileName, int studentAmount) {
    ofstream file(fileName);
    random_device rd;
    mt19937 rng(rd());

    int ndCount = generateND();
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
            file << setw(10) << intToString(generateGrade());
        }

        file << setw(10) << intToString(generateGrade()) << endl;
    }

    file.close();
}

void Studentas::separateStudents(vector<Studentas>& studentai, vector<Studentas>& Blogi) {
    vector<Studentas> temp;
    for (auto it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->getGalutinis() < 5) {
            Blogi.push_back(std::move(*it));
        }
        else {
            temp.push_back(std::move(*it));
        }
    }
    studentai = std::move(temp);
}

void Studentas::generateSeperateFile(const vector<Studentas>& studentai, const string& fileName, int pasirinkimas) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)  /" << setw(20) << "Galutinis (Med.)" << endl;
        outFile << setfill('-') << setw(68) << "" << setfill(' ') << endl;
        for (const auto& S : studentai) {
            if (pasirinkimas == 1) {
                outFile << left << setw(15) << S.getPavarde() << setw(15) << S.getVardas() << setw(20) << fixed << setprecision(2) << S.getGalutinis() << setw(20) << " " << endl;
            }
            else {
                outFile << left << setw(15) << S.getPavarde() << setw(15) << S.getVardas() << setw(20) << " " << setw(20) << fixed << setprecision(2) << S.getGalutinis() << endl;
            }
        }
        outFile.close();
    }
}

void Studentas::clearVectors(vector<Studentas>& studentai, vector<Studentas>& Blogi) {
    studentai.clear();
    Blogi.clear();
}

void Studentas::printInfo() {
    std::cout << "Vardas: " << vardas_ << std::endl;
    std::cout << "Pavarde: " << pavarde_ << std::endl;
    std::cout << "Egzamino balas: " << egz_ << std::endl;
    std::cout << "Namu darbu skaicius: " << n_ << std::endl;
    std::cout << "Namu darbu pazymiai: ";
    for (const auto& grade : nd_) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
    std::cout << "Vidurkis: " << vidurkis_ << std::endl;
    std::cout << "Mediana: " << mediana_ << std::endl;
}

std::string Studentas::output() const {
    std::ostringstream eil;
    eil << vardas_ << "\t" << pavarde_ << "\t" << n_ << "\t" << egz_ << "\t";

    for (const auto& grade : nd_) {
        eil << grade << " ";
    }

    eil << "\t" << std::fixed << std::setprecision(1) << vidurkis_ << "\t"
        << std::fixed << std::setprecision(1) << galutinis_ << "\t"
        << std::fixed << std::setprecision(1) << mediana_;

    return eil.str();
}
