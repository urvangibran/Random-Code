#include<bits/stdc++.h>
using namespace std;

struct Film{
    string judul, produser, tokohUtama;
    int rating;

    Film *next;
};

Film *head, *cur, *tail, *newNode ,*del, *before;

int countFilm(){
    cur = head;
    int num=1;
    while( cur->next != NULL){
        cur = cur -> next;
        num++;
    }
    return num;
}

void inputFilm (string judul, string produser, string tU, int Rating){
    head = new Film();
    head -> judul = judul;
    head -> produser = produser;
    head -> tokohUtama = tU;
    head -> rating = Rating;
    head -> next = NULL;
    tail = head;
}

void addFirst(string judul, string produser, string tU, int Rating){
    newNode = new Film();
    newNode -> judul = judul;
    newNode -> produser = produser;
    newNode -> tokohUtama = tU;
    newNode -> rating = Rating;
    newNode -> next = head;
    head = newNode;
}

void addMiddle(string judul, string produser, string tU, int Rating, int posisi){
    newNode = new Film();
    newNode -> judul = judul;
    newNode -> produser = produser;
    newNode -> tokohUtama = tU;
    newNode -> rating = Rating;
    cur = head;
    int num = 1;
    while( num < posisi - 1){
        cur = cur->next;
        num++;
    }
    newNode -> next = cur -> next; 
    cur -> next = newNode;
    
}

void addLast(string judul, string produser, string tU, int Rating){
    newNode = new Film();
    newNode -> judul = judul;
    newNode -> produser = produser;
    newNode -> tokohUtama = tU;
    newNode -> rating = Rating;
    newNode -> next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void removeFirst(){
    del = head;
    head = head -> next;
    delete del;
}

void removeMiddle(int posisi){
    //pengkondisian
    if(posisi == 1 || posisi == countFilm()) 
        cout << "Posisi bukan tengah" << endl;
    if(posisi < 1 || posisi > countFilm())
        cout << "Posisi di luar jangkauan";
    cur = head;
    int num = 1;
    while( num <= posisi){
        if(num == posisi - 1) before = cur;
        if(num == posisi) del = cur;
        cur = cur -> next;
        num++;
    }
    before->next = cur;
    delete del;
}

void removeLast(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = head->next;
    }
    tail=cur ;
    tail->next = NULL;
    delete del;
}

void changeFirst(string judul, string produser, string tU, int Rating){
    head->judul = judul;
    head->produser = produser;
    head->tokohUtama = tU;
    head->rating = Rating;
}

void changeMiddle(string judul, string produser, string tU, int Rating, int posisi){
    if(posisi == 1 || posisi == countFilm()) 
        cout << "Posisi bukan tengah" << endl;
    if(posisi < 1 || posisi > countFilm())
        cout << "Posisi di luar jangkauan";
    cur = head;
    int num = 1;
    while( num < posisi){
        cur = cur -> next;
        num++;
    }
    cur->judul = judul;
    cur->produser = produser;
    cur->tokohUtama = tU;
    cur->rating = Rating;
}

void changeLast(string judul, string produser, string tU, int Rating){
    tail->judul = judul;
    tail->produser = produser;
    tail->tokohUtama = tU;
    tail->rating = Rating;
}


void displayFilm(){
    cout << "Jumlah data Film\t: "<< countFilm() << endl;
    cur = head;
    while(cur != NULL){
        
        cout << " Judul Film\t\t: " << cur->judul<<endl;
        cout << "Produser Film\t\t: " << cur->produser<<endl;
        cout << "tokohUtama Film\t\t: " << cur->tokohUtama<<endl;
        cout << "Rating\t\t\t: " << cur->rating<<endl;
        

        cur = cur ->next;
    }
}

int main(){
    
    inputFilm("Hangout", "Radit", "Bayu", 9);
    
    displayFilm();
    cout << "\n" << endl;
    

    addFirst("Money Heist", "Jerina Ladika", "Profesor", 10);
    
    displayFilm();
    cout << "\n" << endl;
    addLast("Glory", "Aina", "Gibran", 8);

    displayFilm();
    cout << "\n" << endl;
    // removeFirst();

    // displayFilm();
    cout << "\n" << endl;
    // removeLast();
    // displayFilm();
    cout << "\n" << endl;

    changeFirst("Upin dan Ipin", "Malaysian", "Kak Ros", 6);
    changeLast("Boboiboy", "Malaysian", "Adudu", 6);
    displayFilm();
    cout << "\n" << endl;

    addMiddle("Ibu", "Kartini", "Harum", 10, 2);
    displayFilm();
    cout << "\n" << endl;

    // removeMiddle(2);
    // displayFilm();
    cout << "\n" << endl;

    changeMiddle("Tuyul dan Mbak Yul", "Wong Hebat", "Yo Tuyul", 9, 2);
    displayFilm();
    cout << "\n" << endl;
}