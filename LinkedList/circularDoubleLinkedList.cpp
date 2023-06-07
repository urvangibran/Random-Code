#include<bits/stdc++.h>
using namespace std;

struct Friend{
    string nama;
    int umur, hub;

    Friend *next, *prev;
};

Friend *head, *tail, *cur, *newNode, *del, *afterNode;

void inputLin(string nama, int umur, int hub){
    head        = new Friend();
    head->nama  = nama;
    head->umur  = umur;
    head->hub   = hub;
    head->next  = head;
    head->prev  = head;
    tail        = head;
 }

 int countLin(){
    cur = head;
    int idx = 0;
    while(cur->next != head){
        cur=cur->next;
        idx++;
    }
    return (idx+1);
 }

 void addFirst(string nama, int umur, int hub){
    newNode         = new Friend();
    newNode->nama   = nama;
    newNode->umur   = umur;
    newNode->hub    = hub;
    newNode->prev   = tail;
    newNode->next   = head;
    head->prev      = newNode;
    head->next      = newNode;
    head            = newNode;
 }

 void addMiddle(string nama, int umur, int hub, int pos){
    newNode         = new Friend();
    newNode->nama   = nama;
    newNode->umur   = umur;
    newNode->hub    = hub;
    cur = head;
    int idx = 0;
    while (idx < pos-2){
        cur = cur->next;
        idx++;
    }
    afterNode = cur->next;
    afterNode->prev = newNode;
    newNode->next = afterNode;
    newNode->prev = cur;
    cur->next = newNode;
 }

 void addLast(string nama, int umur, int hub){
    newNode         = new Friend();
    newNode->nama   = nama;
    newNode->umur   = umur;
    newNode->hub    = hub;
    newNode->prev   = tail;
    newNode->next   = head;
    head->prev      = newNode;
    tail->next      = newNode;
    tail            = newNode;       
 }

 void removeFirst(){
    /*
     cara1
    del = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete del;
    */

    cur = head->next;
    del = head;
    cur->prev = tail;
    tail->next = cur;
    head = cur;
    delete del;
 }

 removeMiddle(int pos){
    cur = head;
    int idx = 0;
    while (idx < pos-2){
        cur = cur->next;
        idx++;
    }
    del = cur->next;;
    afterNode = del->next;
    cur->next = afterNode;
    afterNode->prev = cur;
    delete del;
 }

 void removeLast(){
    /*
     cara 1
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del; 
    */
    cur = tail->prev;
    del = tail;
    cur->next = head;
    head->prev = cur;
    tail = cur;
    delete del;
 }

 void displayLin(){
    if ( head == NULL) cout << "Linked List Kosong!"<<endl;
    else{
        cout << "Data " << countLin() << " Teman : " << endl;
        cur = head;
        while(cur->next != head){
            cout << "Nama\t: " << cur->nama << endl;
            cout << "Umur\t: " << cur->umur << endl;
            cout << "Hub\t: " << cur->hub << endl;
            cur = cur->next;
        }
            cout << "Nama\t: " << cur->nama << endl;
            cout << "Umur\t: " << cur->umur << endl;
            cout << "Hub\t: " << cur->hub << endl;
            cout << "\n\n";
    }
 }

 int main(){
    cout << "\n\n";

    inputLin("Chilyaaah", 18, 10);
    displayLin();

    addFirst("Remandaa", 19, 10);
    displayLin();

    addLast("Lanaaa", 20, 7 );
    displayLin();
    
    // removeFirst();
    // displayLin();

    // removeLast();
    // displayLin();

    addMiddle("Ainaa", 19, 7, 9);
    displayLin();

    removeMiddle(7);
    displayLin();
    
 }