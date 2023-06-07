#include <bits/stdc++.h>
using namespace std;

typedef struct pQueue
{
    int prior;
    string order;
} PQ;

struct CompareHeight
{
    bool operator()(PQ const &p1, PQ const &p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.prior > p2.prior;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    priority_queue <PQ, vector<PQ>, CompareHeight> pq_asc;

    int i;
    for(i = 0; i < e; i++)
    {
        int a; string order;
        cin >> a >> order;
        pq_asc.push(PQ{a, order});
    }

    int flag = 0;
    while(n >= pq_asc.top().prior)
    {
        flag = 1;
        n -= pq_asc.top().prior;
        cout << pq_asc.top().order << endl;
        pq_asc.pop();
    }
    if(flag == 0)
        printf("PAK ARYA");
}