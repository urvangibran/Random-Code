#include<stdio.h>

typedef struct node_t{
    int data;
    struct node_t *next;
}ListNode;

typedef struct list_t{
    unsigned _size;
    ListNode *_head;
}SinglyList;

bool list_isEmpty(SinglyList *list){
    return (list->_size == NULL);
}

void push_back(SinglyList *list, int value){
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    
    if(newNode){
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

    if(list_isEmpty(list)){
        list->_head = newNode;
    }
    else{
        ListNode *cur = list->_head;
        while(cur->next != NULL){
            cur = cur->next;
        } 
        cur->next = newNode;
    }
    }
}

void push_Front(SinglyList *list, int value){
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    if(newNode){
        list->_size++;
        newNode->data = value;

        if (list_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
            
        list->_head = newNode;
    }
}

void insertAt(SinglyList *list, int value, int idx){
    if(idx - 1 >= list->_size || list_isEmpty(list)){
        push_back(list, value);
        return;
    }
    if(idx == 0) {
        push_Front(list, value);
        return;
    }
        
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    if(newNode){
        ListNode *cur = list->_head;
        int i = 0;

        while(cur->next != NULL && i < idx-1){
            cur = cur->next;
            i++;
        }
        newNode->data = value;
        newNode->next = cur->next;
        cur->next = newNode;
        list->_size ++;
    }

}



int main(){

}