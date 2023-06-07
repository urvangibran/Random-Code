#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// struct Date{
//     char tempat[15];
//     int tanggal, bulan, tahun;
// };

struct Alamat{
    char jalan[20], Kel[20], Kec[20], Prov[20];
    int RT, RW; 
};

struct DataKTP{
    char nama[200];
    char gender[15];
    char golDarah[5]; 
    char agama[10]; 
    char pekerjaan[20];
    char statusPerkawinan[30];
    char NIK[20];
    char TTL[50];
    int umur;

    // struct Date TTL;
    struct Alamat alamat;
};

struct DataKTP dataMahasiswa[50];
int cntMahasiswa = 0;

struct DataKTP tambahData(){
    char nama[200], gender[15], golDarah[5], agama[10], pekerjaan[20], statusPerkawinan[30], NIK[20], TTL[50];
    int umur;
    // char tempat[15];
    // int tanggal, bulan, tahun;
    char jalan[20], Kel[20], Kec[20], Prov[20];
    int RT, RW; 

    printf("=============================\n");
    printf("INPUT DATA KTP MAHASISWA\n\n");
    fflush(stdin);
    printf("Nama Mahasiswa \t\t : ");
    gets(nama);
    printf("Jenis Kelamin \t\t : ");
    gets(gender);
    printf("Golongan Darah \t\t : ");
    gets(golDarah);
    printf("Agama \t\t\t : ");
    gets(agama);
    printf("Pekerjaan \t\t : ");
    gets(pekerjaan);
    printf("Status Perkawinan \t : ");
    gets(statusPerkawinan);
    printf("NIK \t\t\t : ");
    gets(NIK);
    printf("Umur \t\t\t : ");
    scanf("%d", &umur);
    printf("TTL (Place, dd-mm-yyy) : ");
    gets(TTL);
    fflush(stdin);
    printf("Alamat Tinggal : \n\n");
    printf("\ta) Jalan \t : ");
    gets(jalan);
    printf("\tb) Kelurahan \t : ");
    gets(Kel);
    printf("\tc) Kecamatan \t : ");
    gets(Kec);
    printf("\tc) Provinsi \t : ");
    gets(Prov);
    printf("\te) RT \t\t : ");
    scanf("%d", &RT);
    printf("\tf) RW \t\t : ");
    scanf("%d", &RW);

    struct DataKTP dataBaru = 
    {"", "", "", "", "", "", "", umur, "", "", "", "", "", RT, RW};
    strcpy(dataBaru.nama, nama);
    strcpy(dataBaru.gender, gender);
    strcpy(dataBaru.golDarah, golDarah);
    strcpy(dataBaru.agama, agama);
    strcpy(dataBaru.pekerjaan, pekerjaan);
    strcpy(dataBaru.statusPerkawinan, statusPerkawinan);
    strcpy(dataBaru.NIK, NIK);
    strcpy(dataBaru.TTL, TTL);
    strcpy(dataBaru.alamat.jalan, jalan);
    strcpy(dataBaru.alamat.Kel, Kel);
    strcpy(dataBaru.alamat.Kec, Kec);
    strcpy(dataBaru.alamat.Prov, Prov);

    return dataBaru;    
}

void displayData(int i){
        printf("\nData ke-%d\n", i+1);
        printf("Nama Mahasiswa \t : %s\n", dataMahasiswa[i].nama);
        printf("NIK \t\t : %s\n", dataMahasiswa[i].NIK);
        printf("TTL \t\t : %s\n", dataMahasiswa[i].TTL);
        printf("Umur \t\t : %d\n", dataMahasiswa[i].umur);
        printf("Jenis Kelamin \t : %s\n", dataMahasiswa[i].gender);
        printf("Golongan Darah \t : %s\n", dataMahasiswa[i].golDarah);
        printf("Agama \t\t : %s\n", dataMahasiswa[i].agama);
        printf("Pekerjaan \t : %s\n", dataMahasiswa[i].pekerjaan);
        printf("Alamat \t\t : Jalan %s, RT.%d, RW.%d, Kelurahan %s, Kecamatan %s, Provinsi %s.\n",
        dataMahasiswa[i].alamat.jalan, dataMahasiswa[i].alamat.RT, dataMahasiswa[i].alamat.RW, dataMahasiswa[i].alamat.Kel, dataMahasiswa[i].alamat.Kec, dataMahasiswa[i].alamat.Prov);
        printf("Status Perkawinan : %s\n\n", dataMahasiswa[i].statusPerkawinan);
        // printf("Press any key to back to the menu . . .");
}
int main(){
    int option = 0, option2 = 0, option3 = 0, a = 1;
    while(a > 0){
        system("cls");
    printf("Menu Utama:\n\n");
    printf("1. Entri KTP\t\n");
    printf("2. Lihat KTP\t\n");
    printf("3. Exit\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &option);
    switch(option){
        case 1 :
            system ("cls");
            printf("1. Tambah Data\t\n");
            printf("2. Hapus Data\t\n");
            printf("Masukkan pilihan : ");
            scanf("%d", &option2);
            switch(option2){
                case 1 :
                    system ("cls");
                    dataMahasiswa[cntMahasiswa] = tambahData();
                    cntMahasiswa++;
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
                case 2 :
                    system ("cls");
                    printf("SABAR MASIH BELAJAR");
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
            }
            break;
    case 2 : 
         if(cntMahasiswa == 0){
                system("cls");
                printf("Data Mahasiswa Belum Ada."); 
                printf("\nPress any key to back to the menu . . .");
                getch();
                break;
        }else{
        system ("cls");
        printf("1. Lihat Semua Data KTP : \n");
        printf("2. Cari Data KTP \t: \n");
        printf("Masukkan pilihan : ");
        scanf("%d", &option3);
        switch(option3){
            case 1 :
                system ("cls");
                printf("Data KTP Mahasiswa : \n");
                for(int i=0;i<cntMahasiswa;i++)
                displayData(i);
                getch();
                break;
            case 2 :
                char NIKCari[20];
                system ("cls");
                printf("Masukkan NIK : ");
                scanf("%s", NIKCari);
                for(int i=0;i<cntMahasiswa;i++){
                    if(strcmp(dataMahasiswa[i].NIK, NIKCari)==0){
                        printf("Berikut Data Lengkapnya : \n");
                        displayData(i);
                        break;
                    }
                    }
                        printf("Press any key to back to the menu . . .");
                        getch();
                        break;
                    }
        }
        break;
    case 3 :
        printf("\n\nBERHASIL KELUAR.");
        return 0;
    } a++;
    }
}