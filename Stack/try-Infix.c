#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Struct untuk menampung karakter pada stack
struct Stack {
    char data[MAX_SIZE];
    int top;
};

// Fungsi untuk menambahkan karakter pada stack
void push(struct Stack* s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++s->top] = c;
}

// Fungsi untuk menghapus karakter dari stack
char pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[s->top--];
}

// Fungsi untuk mendapatkan nilai precedensi operator
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Fungsi untuk mengubah notasi infix menjadi postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    s.top = -1;
    int i, j;
    char c;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) { // Jika karakter merupakan operand
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') { // Jika karakter merupakan tanda kurung buka
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') { // Jika karakter merupakan tanda kurung tutup
            while ((c = pop(&s)) != '(')
                postfix[j++] = c;
        }
        else { // Jika karakter merupakan operator
            while (precedence(infix[i]) <= precedence(s.data[s.top]) && s.top != -1)
                postfix[j++] = pop(&s);
            push(&s, infix[i]);
        }
    }
    while (s.top != -1) // Push semua karakter yang tersisa pada stack ke postfix
        postfix[j++] = pop(&s);
    postfix[j] = '\0'; // Menambahkan karakter null pada akhir postfix
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Masukkan notasi infix: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Menghapus karakter newline dari input

    infixToPostfix(infix, postfix);
    printf("Notasi postfix: %s\n", postfix);

    return 0;
}