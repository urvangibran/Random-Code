#include <iostream>
#include <queue>
using namespace std;

typedef struct pQueue
{
    int prior;
    string order;
}PQ;

int main()
{
    int n, e;
    cin >> n >> e;
    priority_queue<PQ, vector<PQ>, greater<int>> pq_asc;

    while(e--)
    {
        int a; string opr;
        scanf("%d %c",&a, opr);
        pq_asc.push(PQ{a, opr});
    }
    
    if(e > pq_asc.top())
    {
        printf("%d", pq_asc.top().order);
        e-=pq_asc.top();
    }
    else
    {
        printf("PAK ARYA");
    }
    return 0;
}