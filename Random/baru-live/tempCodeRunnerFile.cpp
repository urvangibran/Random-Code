#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int path(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

}

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i] >> arr2[i];
    }
    int shortestPath, ans = 0, jarak;

    shortestPath = path(a, b, arr1[0], arr2[0]);
    for (int i = 1; i < n; i++) {
        jarak = path(a, b, arr1[i], arr2[i]);
        if (jarak < shortestPath) {
            ans = i;
            shortestPath = jarak;
        }
    }
    cout << "Titik terdekat adalah (" << arr1[ans] << ", " << arr2[ans] << ")" << endl;

    return 0;
}
