#ifndef IBU_H
#define IBU_H
class ibu {
    public:
        string nama;
        vector<anak*> daftar_anak;

        ibu(string pNama): nama(pNama){
                cout << "ibu \"" << nama << "\" ada\n"
        }

        ~ibu() {
            cout << "ibu \"" << nama << "\" tidak ada\n";
        }
        void tambahAnak(anak*);
        void cetakAnak();
};

void ibu::cetakAnak() {
    cout << "Daftar Anak dari ibu \"" <<
    this->nama << "\":\n";
    for (int i = 0, i < daftar_anak.size(); i++) {
        cout << daftar_anak[i]->nama << endl;
    }
    cout << endl;
}

#endif