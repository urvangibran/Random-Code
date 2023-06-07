#include<bits/stdc++.h>
using namespace std;

struct game{
    string nama, username;
    int versi;

    game *next, *prev;
};

game *head, *tail, *cur, *newNode, *del, *before;

void inputLin(string nama, string uname, int versi){
    head = new game();
    //head = (game*) malloc(sizeof(game));
    head->nama = nama;
    head->username = uname;
    head->versi = versi;
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

int countLin(){
    cur = head;
    int idx = 0;
    while(cur != NULL){
        cur = cur->next;
        idx++;
    }
    return (idx);
}

void addFirst(string nama, string uname, int versi){
    newNode = new game();
    newNode->nama = nama;
    newNode->username = uname;
    newNode->versi = versi;
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
}

void addMiddle(string nama, string uname, int versi, int pos){
    newNode = new game();
    newNode->nama = nama;
    newNode->username = uname;
    newNode->versi = versi;
    cur = head;
    int idx = 0;
    while(idx < pos-2){
        cur = cur->next;
        idx++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    newNode->prev = cur;
}

void addLast(string nama, string uname, int versi){
    newNode = new game();
    newNode->nama = nama;
    newNode->username = uname;
    newNode->versi = versi;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void changeFirst(string nama, string uname, int versi){
    head->nama = nama;
    head->username = uname;
    head->versi = versi;
}

void changeMiddle(string nama, string uname, int versi, int pos){
    cur = head;
    int idx = 0;
    while(idx < pos - 1){
        cur = cur->next;
        idx++;
    }
    cur->nama = nama;
    cur->username = uname;
    cur->versi = versi;    
}

void changeLast(string nama, string uname, int versi){
    tail->nama = nama;
    tail->username = uname;
    tail->versi = versi;
}

void removeFirst(){
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
}

void removeMiddle(int pos){
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
    cur->prev = before;
    delete del;
}

void removeLast(){
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void displayLin(){
    cout << "Berikut "<< countLin() << " data game: " << endl;
    cur = head;
    while(cur != NULL){
        cout << "Nama Game \t: " << cur ->nama << endl;
        cout << "Username \t: " << cur ->username<< endl;
        cout << "Versi \t\t: " << cur ->versi<< endl;
        cur = cur->next;
    }
    cout << "\n\n";
}


int main(){
    cout << "\n";

    inputLin("ML", "urvangibran", 12);
    displayLin();
    
    inputLin("Duolingo", "urvangibran", 99);
    displayLin();

    addFirst("PUBG", "suzy", 55);
    displayLin();

    addLast("Xmas", "drugsyeee", 1);
    displayLin();

    // removeFirst();
    // displayLin();

    // removeLast();
    // displayLin();

    addMiddle("Layangan", "hiu Besar", 5, 2);
    displayLin();

    removeMiddle(3);
    displayLin();

    changeFirst("Typing Test", "Horse", 6);
    displayLin();

    changeLast("FRIV", "Many", 3);
    displayLin();

    addMiddle("Jurasic Park", "Tarzan", 89, 3);
    displayLin();

    changeMiddle("MAMAMIAA", "YO MAMA", 6, 3);
    displayLin();

}