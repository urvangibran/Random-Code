#include <bits/stdc++.h>    

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* orderlist(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Konversi linked list menjadi vector
    std::vector<int> vec;
    Node* curr = head;
    while (curr != nullptr) {
        vec.push_back(curr->data);
        curr = curr->next;
    }

    // Urutkan vector
    std::sort(vec.begin(), vec.end());

    // Konversi vector menjadi linked list
    Node* new_head = new Node(vec[0]);
    Node* new_tail = new_head;
    for (int i = 1; i < vec.size(); i++) {
        Node* new_node = new Node(vec[i]);
        new_tail->next = new_node;
        new_tail = new_node;
    }

    return new_head;
}

int main() {
    // Contoh penggunaan
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);

    std::cout << "Sebelum diurutkan: ";
    printlist(head);

    head = orderlist(head);

    std::cout << "Setelah diurutkan: ";
    printlist(head);

    return 0;
}
