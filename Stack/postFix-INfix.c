#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix[50];
int top = -1;

void push (char a){
    infix[++top] = a;
}

char pop (){
    return infix[top--];
}

int main(){
    char a[100];
    scanf("%[^\n]", a);
    
    int idx = 0;
    while(a[idx] != "\0"){
        if(a[idx] == '+' || a[idx] == '-')
            push(a[idx]);
        else(a[idx] == '*' || a[idx] == '/'){
            
        }
            
    }
}