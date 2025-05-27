#ifndef ANAK_H
#define ANAK_H

class anak{
    
    public:
        string nama;
        anak(string pNama): nama (pNama) {
            cout <<anak \"" << nama << "\" ada\n";
        }

        anak() {
            cout << "anak \"" << nama << "\" tidak ada\n";
            }
};
#endif