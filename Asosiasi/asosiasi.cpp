#include <iostream>
#include <vector>
using namespace std;

class dokter;

class pasien{
    public:
    string nama;
    vector<dokter*> daftar_dokter;
    pasien(string pNama): nama(pNama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    }
    ~pasien() {
        cout << "Pasien \"" << nama
        << "\" tidak ada\n";
    }
    void tambahanDokter(dokter*);
    void cetakDokter();
};

class dokter {
    public:
        string nama;
        vector<pasien*> daftar_pasien;

        dokter(string pNama): nama(pNama) {
            cout << "dokter \"" << nama << "\" ada\n";
        }
        ~dokter() {
            cout << "Dokter \"" << nama
            << "\" tidak ada\n";
        }
        void tambahanPasien(pasien*);
        void cetakPasien();
    
};

void pasien::tambahanDokter(dokter* pDokter){
    daftar_dokter.push_back(pDokter);
}


void pasien::cetakDokter() {
    cout << "Daftar dokter yang menangani pasien \""
    << this->nama << "\":\n";
    // aouto digunakan dalam perulangan
    for (auto& a : daftar_dokter) {
        cout << a->nama << "\n";
    }
    cout << endl;
}
void dokter:: tambahanPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
    pPasien->tambahanDokter(this);
}
void dokter::cetakPasien() {
    cout << "Daftar pasien dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    dokter* varDokter1 = new dokter("dr.Budi");
    dokter* varDokter2 = new dokter("dr.Tono");
    dokter* varPasien1 = new dokter("Andi");
    dokter* varPasien2 = new dokter("Lia");

    varPasien1->tambahanPasien(varDokter1);
    varPasien1->tambahanPasien(varDokter2);
    varPasien2->tambahanPasien(varDokter2);

    varDokter1->cetakPasien();
    varDokter2->cetakPasien();
    varPasien1->cetakDokter();
    varPasien2->cetakDokter();

}