#include<bits/stdc++.h>
using namespace std;

int ma = 5;
string arrayBook[5];
int top = 0;

bool isFull(){
    if ( top == ma ) return true;
    else return false;
}

bool isEmpty(){
    if(top == 0) return true;
    else return false;
}

void pushArray(string data){
    if(isFull()) cout << "Data sudah penuh!" << endl;
    else{
        arrayBook[top] = data;
        top++;
    }
}

void popArray(){
    if(isEmpty()) cout << "Tidak ditemukan data." << endl;
    else {
        arrayBook[top-1] = "";
        top--;
    }
}

void peekArray(int posisi){
    if(isEmpty()) cout << "Tidak ditemukan data." << endl;
    else{
        cout << "Data ke-%d" << pos << " adalah"
    // int index = top;
    // for(int i=0;i<posisi;i++){
    //     index--;
    // }
    // cout << "Data ke-" << index << " adalah: " << arrayBook[index] << endl;
    
    }
}

void displayArray(){
    if(isEmpty()) cout << "Tidak ditemukan data." << endl;
    else{ 
        for(int i=ma-1 ;i>=0;i--)
            if(arrayBook[i] != "")
            cout << "Data : " << arrayBook[i] << endl;
    }
    cout << "\n" << endl;
}

int countArray(){
    if (isEmpty()) return 0;
    else{
        return top;
    }
}

void changeArray(string data, int posisi){
    if(isEmpty()) cout << "Tidak ditemukan data." << endl;
    else{
        int index = top;
        for(int i = 0; i < posisi; i++){
            index--;
        }
        arrayBook[index] = data;
    }    

}

void destroyArray(){
    if(isEmpty()) cout << "Tidak ditemukan data." << endl;
    else{
        for(int i=0;i<top;i++)
            arrayBook[i] = "";
        top = 0;
    }
}

int main(){
    cout << "\n" << endl;
    pushArray("Filosofi Teras");
    displayArray();

    pushArray("You do You");
    pushArray("Manusia Setengah Salmon");
    pushArray("Esensialisme");
    pushArray("Ikigai");
    displayArray();

    popArray();
    displayArray();

    peekArray(2);

    cout << "Jumlah data saat ini: " << countArray() << endl;
    displayArray();

    changeArray("Berani Tidak Disukai", 2);
        peekArray(2);
    displayArray();

    pushArray("For Yourself");

    destroyArray();
    displayArray();

    cout << "Apakah data penuh: " << isFull() << endl;
    cout << "Apakah data kosong: " << isEmpty() << endl;
}