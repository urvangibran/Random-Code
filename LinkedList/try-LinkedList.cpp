#include<bits/stdc++.h>
using namespace std;

typedef struct kuliah{
    string kampus, jurusan;
    int semester;

    kuliah *next;
}gibran;

kuliah *head, *tail, *cur, *newNode, *before, *next, *del;

// hanya satu inputan
void inputLin(string kps, string jrsn, int smt){ 
    head = new kuliah();
    head->kampus = kps; 
    head->jurusan = jrsn;
    head->semester = smt;
    head->next = NULL;
    tail = head;    
}

int countLin(){
    cur = head;
    int idx = 0;
    while(cur->next!=NULL){
        cur = cur->next;
        idx++;
    }
    return (idx+1);
}

void addFirst(string kps, string jrsn, int smt){
    newNode = new kuliah();
    newNode->kampus = kps;
    newNode->jurusan = jrsn;
    newNode->semester = smt;
    newNode->next = head;
    head = newNode;
}

void addMiddle(string kps, string jrsn, int smt, int pos){
    newNode = new kuliah();
    newNode->kampus = kps;
    newNode->jurusan = jrsn;
    newNode->semester = smt; 
    cur = head;
    int idx = 0;
    while(idx < pos - 2){
        cur = cur->next;
        idx++;
    }
    newNode->next = cur->next; 
    cur->next = newNode;
}

void addLast(string kps, string jrsn, int smt){
    newNode = new kuliah();
    newNode->kampus = kps;
    newNode->jurusan = jrsn;
    newNode->semester = smt; 
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
    // cur = head;
    // while(cur->next != NULL)
    //     cur = cur->next;
    // cur->next = newNode;
    // newNode->next = NULL;
}

void removeFirst(){
    if(countLin() == 0) cout << "Data sudah kosong!" << endl;
    del = head;
    head = head->next;
    delete del;
}

void removeMiddle(int pos){
    if(pos < 1 || pos > countLin()) cout << "Tidak dapat dijangkau" << endl;
    if(pos == 1 || pos == countLin()) cout << "Gunakan fungsi lain!" << endl;
    cur = head;
    int idx = 0;
    while(idx < pos ){
        if(idx < pos-1)
            before = cur;
        if(idx < pos)
            del = cur;
        idx++;
        cur = cur->next;
    }
    before->next = cur;
    delete del;
}

removeLast(){
    if(countLin() == 0) cout << "Data sudah kosong!" << endl;
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    cur->next = NULL;
    delete del;
}

changeFirst(string kps, string jrsn, int smt){
    head->kampus = kps;
    head->jurusan = jrsn;
    head->semester = smt;
}

changeMiddle(string kps, string jrsn, int smt, int pos){
    cur = head;
    int idx = 0;
    while(idx < pos-1){
        cur = cur->next;
        idx++;
    }
    cur->kampus = kps;
    cur->jurusan = jrsn;
    cur->semester = smt;
}

changeLast(string kps, string jrsn, int smt){
    tail->kampus = kps;
    tail->jurusan = jrsn;
    tail->semester = smt;
}

void displayLin(){
    cout << "Tampilan " << countLin() << " Data:" << endl;
    cur = head;
    while(cur != NULL){
        cout << "Nama kampus\t: " << cur->kampus << endl;
        cout << "Jurusan\t\t: " << cur->jurusan << endl;
        cout << "Semester\t: " << cur->semester << endl;
        
        cur = cur->next;
    }
        cout << "\n\n";
}

int main(){
    cout << "\n";

    inputLin("ITS", "Infor", 2);
    displayLin();

    // ketika inputLin dijalankan dengan input yang berbada
    // otomatis input di sebelumnya hilang
    inputLin("UNER", "Farmasi", 1);
    displayLin();

    addFirst("UB", "TI", 3);
    displayLin();

    addMiddle("ITB", "STEI", 8, 2);
    displayLin();

    addLast("UI", "Sisfor", 3);
    displayLin();
    
    // removeFirst();
    // displayLin();

    // removeMiddle(2);
    // displayLin();

    // removeLast();
    // displayLin();

    changeFirst("UMM", "Biologi", 2);
    displayLin();

    changeMiddle("UNAIR", "FK", 11, 3);
    displayLin();

}


