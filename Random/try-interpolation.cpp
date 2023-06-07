#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int ipSearch(int a[],int n, int key){
    int l = 0, r = n-1;
    while( l <= r && key >= a[l] && key <= a[r]){

        if (l == r) {
        return l;
        return -1;
        }

        int pos = l + ((double)(key - a[l]) / (a[r] - a[l])) * (r-l) ;
            
            if(a[pos] == key) return pos;
            if(a[pos] > key) r = pos - 1;
            else l = pos + 1;
    }
    return -1;
}

int main(){
    int num[] = {41, 51, 223, 250, 700, 1000, 123213};
    int n = sizeof(num) / sizeof(num[0]);

    int a = 1;
    while(a > 0){
    system("cls");
    printf("1. Coba Interpolation Search\n");
    printf("2. EXIT\n");
    printf("Masukkan Pilihian : ");
    int op;
    cin >> op;
    switch (op)
    {
    case 1 :
            system("cls");
            printf("Masukkan Angka Yang Kamu Cari : ");
            int numCari;
            scanf("%d", &numCari);
            int res;
            res = ipSearch(num,n, numCari);

            if(res == -1) printf("GAADA");
            else{   
            printf("Angka yang dicari ada pada indeks : ");
            printf("%d", res);
            }
        getch();
        break;
    case 2:
        return 0;
    default:
        printf("NO");
        break;
    }a++;
    }
}