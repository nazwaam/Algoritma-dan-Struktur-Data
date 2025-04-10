#include <iostream>
using namespace std;

struct mhs {
    char nama[30], nim[15], jurusan[30];
    int sks, program;
};

int main() {
    mhs bayar[2];
    int tetap, var;

    for (int i = 0; i < 2; i++) {
        cout << "\n\n------------------------------\n";
        cout << "Data Mahasiswa ke-" << i + 1 << endl;

        cin.ignore(); // membersihkan newline dari input sebelumnya
        cout << "Nama mhs                     = ";
        cin.getline(bayar[i].nama, 30);

        cout << "NIM                          = ";
        cin.getline(bayar[i].nim, 15);

        cout << "Jurusan (boleh pakai spasi) = ";
        cin.getline(bayar[i].jurusan, 30);

        // Validasi input program
        while (true) {
            cout << "Program [1 = D3, 2 = S1]     = ";
            cin >> bayar[i].program;

            if (bayar[i].program == 1 || bayar[i].program == 2) {
                break;
            } else {
                cout << "Program tidak sesuai, masukkan 1 atau 2.\n";
            }
        }

        cout << "Jumlah SKS                   = ";
        cin >> bayar[i].sks;

        // Perhitungan biaya
        if (bayar[i].program == 1) {
            tetap = 500000;
            var = bayar[i].sks * 25000;
        } else {
            tetap = 750000;
            var = bayar[i].sks * 50000;
        }

        // Output
        cout << "\n------------------------------\n";
        cout << "Output Mahasiswa ke-" << i + 1 << endl;
        cout << "------------------------------\n";
        cout << "Nama mhs     = " << bayar[i].nama << endl;
        cout << "NIM          = " << bayar[i].nim << endl;
        cout << "Jurusan      = " << bayar[i].jurusan << endl;
        cout << "Program      = " << (bayar[i].program == 1 ? "D3" : "S1") << endl;
        cout << "Jumlah SKS   = " << bayar[i].sks << endl;
        cout << "SPP Tetap    = " << tetap << endl;
        cout << "SPP Variabel = " << var << endl << endl;

        cin.ignore(); // agar tidak bentrok dengan getline di loop berikutnya
    }

    return 0;
}