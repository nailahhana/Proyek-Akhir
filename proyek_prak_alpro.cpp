#include <iostream>
#include <string>

using namespace std;

const int max_user = 100;
const int max_pasien = 100;

struct User {
    string username;
    string password;
};

struct Pasien {
    string nama;
    string alamat;
    string sakit;
    int umur;
    int nik;
    int biaya;
};

User users[max_user];
Pasien daftarpasien [max_pasien];
int totalUsers = 0;
int totalpasien = 0;

bool login() {
    string username, password;
    int attempts = 0;
    
    while (attempts < 3) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (int i = 0; i < totalUsers; i++) {
            if (users[i].username == username && users[i].password == password) {
                cout << "Login berhasil!\n";
                return true;
            }
        }

        attempts++;
        cout << "Login gagal! Percobaan ke-" << attempts << " dari 3.\n";
    }

    cout << "Kesempatan habis! Program keluar.\n";
    return false;
}

void registerUser() {
    if (totalUsers >= max_user) {
        cout << "Maksimal user sudah tercapai!\n";
        return;
    }

    string username, password;
    cout << "Masukkan username: ";
    cin >> username;

    for (int i = 0; i < totalUsers; i++) {
        if (users[i].username == username) {
            cout << "Username sudah digunakan! Silakan coba lagi.\n";
            return;
        }
    }

    cout << "Masukkan password: ";
    cin >> password;

    users[totalUsers].username = username;
    users[totalUsers].password = password;
    totalUsers++;

    cout << "Registrasi berhasil!\n";

}
void input () {
    if (totalpasien >= max_pasien){
        cout << "Maksimal pasien rawat inap sudah tercapai";
        return;
    }
    cout << "Masukkan nama pasien : ";
    cin >> daftarpasien[totalpasien].nama;
    cout << "Masukkan nik pasien : ";
    cin >> daftarpasien[totalpasien].nik;
    cout << "Masukkan alamat pasien : ";
    cin >> daftarpasien[totalpasien].alamat;
    cout << "Masukkan umur pasien : ";
    cin >> daftarpasien[totalpasien].umur;
    cout << "Masukkan sakit pasien : ";
    cin >> daftarpasien[totalpasien].sakit;
    cout << "Biaya : ";
    cin >> daftarpasien[totalpasien].biaya;
}
void output () {
    if(totalpasien == 0){
        cout << "Belum ada data pasien yang dimasukkan";
        return;
    }
    for(int i = 0; i < totalpasien; i++) {
        cout << "Pasien ke-" << (i + 1) << " : "<<"/n";
        cout << "Nama : " << daftarpasien[i].nama << "/n";
        cout << "NIK : " << daftarpasien[i].nik << "/n";
        cout << "Alamat : " << daftarpasien[i].alamat << "/n";
        cout << "Umur : " << daftarpasien[i].umur << "/n";
        cout << "NIK : " << daftarpasien[i].nik << "/n";
        cout << "Sakit : " << daftarpasien[i].sakit << "/n";
    }
}

void cari () {
    if(totalpasien == 0){
        cout << "Belum ada data pasien yang dicatat /n";
        return;
    }
    int cari_nik;
    cout << "Masukkan nik yang ingin dicari : ";
    cin >> cari_nik;
    bool ditemukan = false;
    for(int i=0; i<totalpasien; i++){
        cout << "Data pasien ditemukan : /n";
        cout << "Pasien ke-" << (i + 1) << " : "<<"/n";
        cout << "Nama : " << daftarpasien[i].nama << "/n";
        cout << "NIK : " << daftarpasien[i].nik << "/n";
        cout << "Alamat : " << daftarpasien[i].alamat << "/n";
        cout << "Umur : " << daftarpasien[i].umur << "/n";
        cout << "NIK : " << daftarpasien[i].nik << "/n";
        cout << "Sakit : " << daftarpasien[i].sakit << "/n";
        ditemukan = true;
        break;
    }
    if(!ditemukan){
        cout << "Data pasien tidak ditemukan";
    }
}

int total(int jumlah) {
    if(jumlah <= 0)
    return 0;
    return daftarpasien [jumlah-1].biaya+total(jumlah-1);
}



void menuutama () {
    do{
    int pilihan;
        cout << "----- Menu Utama -----" << endl;
        cout << "1. Input data pasien" << endl;
        cout << "2. Rekap data pasien" << endl;
        cout << "3. Mencari data pasien" << endl;
        cout << "4. Total tagihan" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

    switch(pilihan)
    {
        case 1 : 
        input();
        break;
        case 2 :
        output ();
        break;
        case 3 :
        cari();
        break;
        case 4 :
        {
            int jumlah;
            cout<<"Masukkan jumlah data yang ingin di total : ";
            cin>>jumlah;
            if(jumlah>totalpasien || jumlah<=0)
            {
                cout<<"Data tidak valid \n";
            }
            else
            {
                cout<<"Total tagihan pasien : "<<total(jumlah)<<endl;
            }
            break;
        }
        case 5 :
        cout<<"Program Keluar .... ";
        return;
        default :
        cout<<"Pilihan tudak valid";
    
    }
    }while(true);
}

int main() {
    int pilihan;
    do {
        cout << "\n--- Sistem Login ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                registerUser();
                break;
            case 2:
                if (login()) {
                    menuutama();
                }
                break;
            case 3:
                cout << "Program keluar...\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    }while(true);
}