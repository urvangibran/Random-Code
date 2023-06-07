#include <bits/stdc++.h>
using namespace std;

typedef struct pQueue
{
    int prior;
    string order;
} PQ;

struct CompareHeight
{
    bool operator()(strukkk const &p1, strukkk const &p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.dibutuhkan > p2.dibutuhkan;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    priority_queue <PQ, vector<PQ>, CompareHeight> pq_asc;

    while(e--)
    {
        int a; string opr;
        scanf("%d %c",&a, opr);
        pq_asc.push(PQ{a, opr});
    }
    
    if(n > pq_asc.top())
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