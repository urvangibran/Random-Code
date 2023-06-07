#include <iostream>
#include <deque>
using namespace std;

    int getMax(const deque<int>& dq) {
        int ma = 0;
        for (int num : dq) {
            if (num > ma)
                ma = num;
        }
        return ma;
    }

    void print(deque<int>dq) {
        while(!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n";
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int tc;
        cin >> tc;

        while (tc--) {
            int n, k;
            cin >> n >> k;

            deque<int> dq(n);
            for (int i = 0; i < n; i++) {
                cin >> dq[i];
            }

            int ras = n - k;
            for (int j = 0; j <= ras; j++) {
                deque<int> dq_temp(dq.begin() + j , dq.begin() + j + k);
                cout << getMax(dq_temp) << " ";
                // print(dq_temp);
                // while(!dq_temp.empty()) {
                //     cout << dq_temp.front();
                //     dq_temp.pop_front();
                // }
            }
            cout << "\n";
        }
        return 0;
    }
