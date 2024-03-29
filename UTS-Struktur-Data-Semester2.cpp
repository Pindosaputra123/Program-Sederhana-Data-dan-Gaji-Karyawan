#include <iostream>
#include <string>
using namespace std;

struct GajiKaryawan {
    int jamKerja;
    int tarifPerJam;
    int bonus;
    int totalGaji;
};

struct Karyawan {
    char nama[50];
    string ID;
    GajiKaryawan gaji;

    Karyawan *next, *prev;
};

Karyawan *head = NULL, *tail = NULL, *baru, *bantu, *sementara;

void inputDataKaryawan() {
    system("cls");
    baru = new Karyawan();
    baru->next = NULL;
    baru->prev = NULL;

    cout << "Pakai underscore jika lebih dari 1 kata." << endl;
    cout << "Nama karyawan      : ";
    cin >> baru->nama;
    cout << "ID karyawan        : ";
    cin >> baru->ID;
    cout << "Jam kerja karyawan : ";
    cin >> baru->gaji.jamKerja;
    cout << "Tarif per jam      : ";
    cin >> baru->gaji.tarifPerJam;
    cout << "Bonus karyawan     : ";
    cin >> baru->gaji.bonus;

    int jamKerja = baru->gaji.jamKerja;
    int tarifPerJam = baru->gaji.tarifPerJam;
    int bonus = baru->gaji.bonus;

    baru->gaji.totalGaji = (jamKerja * tarifPerJam) + bonus;

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
    };
    cout << "Data telah berhasil ditambahkan!" << endl;
    system("pause");
};

void hapusDataKaryawan() {
    system("cls");
    if (head == NULL) {
        cout << "Data karyawan masih kosong!" << endl;
        system("pause");
        return;
    };
    string ID;
    cout << "Masukkan ID karyawan yang ingin dihapus : ";
    cin >> ID;

    if (head->ID == ID) {
        bantu = head;
        head = head->next;
        delete bantu;
        cout << "Data telah berhasil dihapus!" << endl;
        system("pause");
        return;
    }

    bantu = head;
    sementara = head->next;
    while (sementara->ID != ID) {
        bantu = sementara;
        sementara = sementara->next;
        if (sementara == NULL) {
            cout << "ID karyawan tidak ditemukan!" << endl;
            system("pause");
            return;
        }
    };

    bantu->next = sementara->next;
    delete sementara;
    cout << "Data telah berhasil dihapus!" << endl;
    system("pause");
};

void tampilkanDataKaryawan() {
    system("cls");

    bantu = head;
    if (bantu == NULL) {
        cout << "Data karyawan masih kosong!" << endl;
        system("pause");
        return;
    };

    cout << "\n\tData Karyawan" << endl;
    cout << "==============================" << endl;
    while (bantu != NULL) {
        cout << "Nama karyawan : " << bantu->nama << endl;
        cout << "ID karyawan   : " << bantu->ID << endl;
        cout << "Total Gaji    : Rp " << bantu->gaji.totalGaji << endl << endl;
        bantu = bantu->next;
    };
    system("pause");
};

void editDataKaryawan() {
    system("cls");
    if (head == NULL) {
        cout << "Data karyawan masih kosong!" << endl;
        system("pause");
        return;
    }
    string ID;
    cout << "Masukkan ID karyawan yang ingin diedit: ";
    cin >> ID;

    bantu = head;
    while (bantu != NULL) {
        if (bantu->ID == ID) {
            cout << "Masukkan data baru untuk karyawan dengan ID " << ID << endl;
            cout << "Nama karyawan      : ";
            cin >> bantu->nama;
            cout << "Jam kerja karyawan : ";
            cin >> bantu->gaji.jamKerja;
            cout << "Tarif per jam      : ";
            cin >> bantu->gaji.tarifPerJam;
            cout << "Bonus karyawan     : ";
            cin >> bantu->gaji.bonus;

            int jamKerja = bantu->gaji.jamKerja;
            int tarifPerJam = bantu->gaji.tarifPerJam;
            int bonus = bantu->gaji.bonus;

            bantu->gaji.totalGaji = (jamKerja * tarifPerJam) + bonus;

            cout << "Data karyawan berhasil diubah!" << endl;
            system("pause");
            return;
        }
        bantu = bantu->next;
    }
    cout << "Karyawan dengan ID " << ID << " tidak ditemukan!" << endl;
    system("pause");
}

int main() {
    int pilihan;

    do {
        system("cls");
        cout << "================================================|" << endl;
        cout << "|          Program Penggajian Karyawan          |" << endl;
        cout << "================================================|" << endl;
        cout << "|1.| Input data karyawan                        |" << endl;
        cout << "|2.| Tampilkan semua data karyawan              |" << endl;
        cout << "|3.| Hapus data karyawan                        |" << endl;
        cout << "|4.| Edit data karyawan                         |" << endl;
        cout << "|0.| Keluar                                     |" << endl;
        cout << "================================================|" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputDataKaryawan();
                break;
            case 2:
                tampilkanDataKaryawan();
                break;
            case 3:
                hapusDataKaryawan();
                break;
            case 4:
                editDataKaryawan();
                break;
            case 0:
                delete head;
                break;
            default:
                cout << "Silahkan pilih opsi yang sesuai!" << endl;
                system("pause");
                break;
        }

    } while (pilihan != 0);

    cout << "Program Selesai." << endl;
    return 0;
}
