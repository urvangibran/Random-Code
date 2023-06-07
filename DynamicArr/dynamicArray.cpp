#include<iostream>
using namespace std;

int main(){
    int *myDinamycArray;
    myDinamycArray = new int [3];

    myDinamycArray[0] = 11;
    myDinamycArray[1] = 12;
    myDinamycArray[2] = 13;
    myDinamycArray[3] = 14;
    myDinamycArray[4] = 15;
    myDinamycArray[5] = 16;
    myDinamycArray[6] = 17;
    
    for(int i=0;i<7;i++){
        cout << myDinamycArray[i] << endl;
    }


    return 0;
}