#include <bits/stdc++.h>
using namespace std;
#define pi pair <int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back 
#define FOR(i,a,b) for(int i=(a); i<(b); i++)

template <class Pair>
void displayVecPair(const vector <Pair> &v){
	cout << "---" << endl;
	for(int i=0;i<v.size();i++){
		cout << '(' << v[i].F << ", " << v[i].S << ')' << endl;
	}
    cout << "Printed " << v.size() << " pairs  of the vector!" << endl;
}

template <class Pair>
bool displayVecThird(const vector<Pair> &v){
    cout << "---" << endl;
	for(int i=0;i<v.size();i++){
		cout << '(' << v[i].F << ", " << v[i].S.F << ", " << v[i].S.S << ')' << endl;
	}
    cout << "Printed " << v.size() << " pairs  of the vector!" << endl;
}

bool sortBySec(const pair<string, int> &a, const pair<string, int> &b){
    return a.S < b.S;
}

bool sortBySecDesc(const pair<string, int> &a, const pair<string, int> &b){
    return a.S > b.S;
}

bool sortFirstDesc(const pair<string, int> &a, const pair<string, int> &b){
    return a.F > b.F;
}

bool sortByThirdAsc(const pair<int, pi> &a, const pair<int, pi> &b){
    return a.S.S < b.S.S;
}

bool sortDescAsc(const pi &a, const pi &b){
    if(a.S != b.S) return a.S < b.S;
    return a.F > b.F;
}

int main(){
	pi a;
	a = mp(1,3);
	cout << a.F << " " << a.S << endl;
	vector <pi> v;
	v.pb(mp(41, 51));
	v.pb({8, 2});
    v.pb(mp(21, 31));
    v.pb(mp(41, 14));
	// displayVecPair(v);

    cout << "--------------" << endl;

    // vector <pair<int, string> > v2;
    // v2.pb(mp(2, "UHUY"));
    // displayVecPair(v2);

    vector<pair <string, int> > namaUmur;
    namaUmur.pb(mp("Gibran", 19));
    namaUmur.pb(mp("Chilyah", 18));
    namaUmur.pb(mp("Remanda", 20));
    namaUmur.pb(mp("Gulia", 11));
    namaUmur.pb(mp("Urvan", 1));

    //sort ascending first value
    // cout << "Sorting Ascending The First Value: " << endl;
    sort(namaUmur.begin(), namaUmur.end());
    // displayVecPair(namaUmur);

    //sort ascending second value
    // cout << "Sorting Ascending The Second Value: " << endl;
    sort(namaUmur.begin(), namaUmur.end(), sortBySec);
    // displayVecPair(namaUmur);

    //sort descending first value
    // cout << "Sorting Descending The First Value: " << endl;
    sort(namaUmur.begin(), namaUmur.end(), sortFirstDesc);
    // displayVecPair(namaUmur);

    //sort descending second value
    // cout << "Sorting Descending The Second Value: " << endl;
    sort(namaUmur.begin(), namaUmur.end(), sortBySecDesc);
    // displayVecPair(namaUmur);

    vector<pair<int, pi> > v3;
    v3.pb(mp(2, mp(14, 1)));
    v3.pb(mp(5, mp(13, 5)));
    v3.pb(mp(1, mp(11, 8)));
    v3.pb(mp(6, mp(3, 20)));
    sort(v3.begin(), v3.end(), sortByThirdAsc);
    // displayVecThird(v3);

    vector<pi> number;
    number.pb(mp(2, 1));
    number.pb(mp(3, 1));
    number.pb(mp(1, 2));
    number.pb(mp(5, 2));
    number.pb(mp(7, 0));
    sort(number.begin(), number.end(), sortDescAsc);
    displayVecPair(number);
	return 0;
}