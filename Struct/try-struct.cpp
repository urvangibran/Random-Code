#include<bits/stdc++.h>
using namespace std;

struct Nilai{ 
    int matematika, fisika, kimia;
};
/*Cara2
typedef struct Mahasiswa{
    string nama, npm, jurusan;
    int umur;
    char nilai;
    Nilai MatKul;
};
*/

struct Mahasiswa{
    string nama, npm, jurusan;
    int umur;
    char nilai;
    Nilai MatKul;
};//mhs[0], mhs2; //global declared


void DisplayMhs(Mahasiswa data){
    cout << "Nama \t\t:" << data.nama << endl;
    cout << "NPM \t\t:" << data.npm << endl;
    cout << "Jurusan \t:" << data.jurusan << endl;
    cout << "Umur \t\t:" << data.umur << endl;
    cout << "Nilai \t\t:" << data.nilai << endl;
    cout << "Nilai MTK \t:" << data.MatKul.matematika << endl;
    cout << "Nilai Fisika \t:" << data.MatKul.fisika<< endl;
    cout << "Nilai Kimia \t:" << data.MatKul.kimia<< endl;
    cout << "------" << endl;
}

int main(){
   // Mahasiswa mhs3; //local declared
    Mahasiswa mhs[3];
    //cara 1
    mhs[0].nama = "Muchammad Urvan Gibran";
    mhs[0].npm = "5025221172";
    mhs[0].jurusan = "Teknik Informatika";
    mhs[0].umur = 19;
    mhs[0].nilai = 'A';
    mhs[0].MatKul.matematika = 99;
    mhs[0].MatKul.fisika = 98;
    mhs[0].MatKul.kimia = 100;

    //cara 2
    // mhs2 = {"Chilyah Aulia", "5025221130", "Teknologi Informasi", 17, 'A'};

    // //cara 3
    // Mahasiswa mhs3 = {"Remanda", "5052118432", "Farmasi", 20, 'B'};

    DisplayMhs(mhs[0]);
    // DisplayMhs(mhs2);
    // DisplayMhs(mhs3);

    
}