#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tnode_t
{
    int id;
    char *order;
    struct tnode_t *next;
}pQueueNode;

typedef struct priorQueue
{
    pQueueNode *top;
}PriorityQueue;

void init(PriorityQueue *ipq)
{
    ipq->top = 0;
}

bool pq_isEmpty(PriorityQueue *ipq)
{
    return(ipq->top == 0);
}

void pq_push(PriorityQueue *ipq, int id, char order[])
{
    pQueueNode *temp = ipq->top;
    pQueueNode *newNode = (pQueueNode*)malloc(sizeof(pQueueNode));
    newNode->id = id;
    newNode->order = order;
    newNode->next = NULL;
    
    if(pq_isEmpty(ipq))
    {
        ipq->top = newNode;
    }
    else
    {
        if(id < ipq->top->id)
        {
            newNode->next = ipq->top;
            ipq->top = newNode;
        }
        else
        {
            while(temp->next != NULL && id > temp->next->id)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void pq_pop(PriorityQueue *ipq)
{
    if(!pq_isEmpty(ipq))
    {
        pQueueNode *temp = ipq->top;
        ipq->top = ipq->top->next;
        free(temp);
    }
}

void pq_layani(PriorityQueue *ipq, int n)
{
    if(n > ipq->top->id)
    while(n > ipq->top->id)
    {
        printf("%c", ipq->top->order);
        n -= ipq->top->id;
    }
    else
    {
        printf("Pak Aya will do the rest");
    }
}

int main()
{
    PriorityQueue pq;
    int n, e;
    scanf("%d %d", &n, &e);
    while(e--)    
    {
        char order[30]; int a;
        scanf("%d %c", &a, order);
        pq_push(&pq, a, order);
    }
    pq_layani(&pq, n);
}