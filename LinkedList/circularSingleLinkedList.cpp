#include<iostream>
using namespace std;

struct Mahasiswa{
    string nama, npm, jurusan;

    Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del, *before;

void inputLin(string Data[3]){
    head = new Mahasiswa();
    head->nama = Data[0];
    head->npm = Data[1];
    head->jurusan = Data[2];
    tail = head;
    tail->next = head;
}

int countLin(){
    cur = head;
    int idx = 0;
    while(cur->next != head){
        cur = cur->next;
        idx++;
    }
    return (idx+1);
}

void addFirst(string Data[3]){
    newNode = new Mahasiswa();
    newNode->nama = Data[0];
    newNode->npm = Data[1];
    newNode->jurusan = Data[2];
    newNode->next = head; 
    tail->next = newNode; 
    head = newNode;
}

void addMiddle(string Data[3], int pos){
    newNode = new Mahasiswa();
    newNode->nama = Data[0];
    newNode->npm = Data[1];
    newNode->jurusan = Data[2];
    cur = head;
    before = head;
    int idx = 0;
    while(idx < pos-1){
        if(idx < pos-2)
            before = cur;
        cur = cur->next;
        idx++;
    }
    before->next = newNode;
    newNode->next = cur;
}

void addLast(string Data[3]){
    newNode = new Mahasiswa();
    newNode->nama = Data[0];
    newNode->npm = Data[1];
    newNode->jurusan = Data[2];
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void removeFirst(){
    del = head;
    cur = head->next;
    tail->next = cur;
    head = cur;
    delete del;
}

void removeMiddle(int pos){
    cur = head;
    int idx = 0;
    while (idx < pos-2){
        cur = cur->next;
        idx++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;

}

void removeLast(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    cur->next = head;
    tail = cur;
    delete del;
}

void changeFirst(string Data[3]){
    head->nama = Data[0];
    head->npm = Data[1];
    head->jurusan = Data[2];
}

void changeMiddle(string Data[3], int pos){
    cur = head;
    int idx = 0;
    while (idx < pos-1){
        cur = cur->next;
        idx++;
    }
    cur->nama = Data[0];
    cur->npm = Data[1];
    cur->jurusan = Data[2];
}

void changeLast(string Data[3]){
    tail->nama = Data[0];
    tail->npm = Data[1];
    tail->jurusan = Data[2];
}

void displayLin(){
    cout << "Data "<< countLin() << " Mahasiswa" <<endl;
    cur = head;
    while(cur->next != head){   
    cout << "Nama\t: " << cur->nama << endl;
    cout << "NPM\t: " << cur->npm << endl;
    cout << "Jurusan\t: " << cur->jurusan << endl;
        cur = cur->next;
    }
    cout << "Nama\t: " << cur->nama << endl;
    cout << "NPM\t: " << cur->npm << endl;
    cout << "Jurusan\t: " << cur->jurusan << endl;
    cout << "\n\n";
}

int main(){
    string data_1[3] = {"Aina", "2201163", "Psikologi"};
    cout << "\n";

    inputLin(data_1);
    displayLin();

    string data_2[3] = {"Gibran", "5025221172", "Informatika"};
    addFirst(data_2);
    displayLin();

    string data_3[3] = {"Hilya", "5024335", "Kedokteran"};
    addLast(data_3);
    displayLin();

    // removeFirst();
    // displayLin();

    // removeLast();
    // displayLin();
    string data_4[3] = {"Lanaa", "5025221130", "Informatika"};
    addMiddle(data_4, 2);
    displayLin();

    removeMiddle(3);
    displayLin();

    string data_5[3] = {"Urvan", "502522111172", "Kedokteran"};
    changeFirst(data_5);
    displayLin();

    string data_6[3] = {"Aulia", "202211710", "Kedokteran"};
    changeLast(data_6);
    displayLin();

    string data_7[3] = {"Nabiilah", "5022216310", "Informatika"};
    changeMiddle(data_7, 2);
    displayLin();
}