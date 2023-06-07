#include<bits/stdc++.h>
using namespace std;

struct num{
    int n;

    num *next;
};

int data = 0;
num *head, *tail, *cur, *del, *newNode;

int countLin(){
    cur = head;
    int idx=0;
    if(cur->next != NULL){
        idx++;
        cur = cur->next;
    }
    return (idx+1);
}

void pb_single(int x){
    head = new num();
    head->n = x;
    head->next = NULL;
    tail = head;
    data++;
}

void pb_front(int x){
    newNode = new num();
    newNode->n = x;
    newNode->next = head;
    head = newNode;
    data++;
}

void pb_back(int x){
    if(data == 0) pb_single(x);
    else{

    newNode = new num();
    newNode->n = x;
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
    data++;
    }
}

void popb_front(){
    del = head;
    head = head->next;
    delete del;
    data++;
}

void popb_back(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    data--;
}

void displayLin(){
    cur = head;
    while(cur!= NULL){
        cout << cur->n << endl;
        cur = cur->next;
    }
}

int main(){
    int tc;
    cin>>tc;
     while(tc--){
        string a;
        int g;
        cin >> a;
        if(a == "push_front"){
            cin >> g;
            pb_front(g);
        }
        else if(a == "push_back"){
            cin >> g;
            pb_back(g);
        }
        else if(a == "pop_front"){
            popb_front();
        }
        else if(a == "pop_back"){
            popb_back();
        }
    }
    displayLin();
}