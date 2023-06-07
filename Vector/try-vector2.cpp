#include<bits/stdc++.h>
using namespace std;

/*try
push_back()
pop_back()
insert()
erase()
clear()

iterator -- begin() end()
*/

int main(){
    vector<int> score;
    score.push_back(40);
    score.push_back(30);
    score.push_back(10);

    // Normal
    cout << "Try Push Back : " << endl;
    for(int i = 0; i < score.size(); i++){
        cout << i + 1 << " : " << score[i] << endl;
    }

    //Pop back = menghilangkan bagian terakhir (mengurangi score.size())
    cout << "Try Pop Back : " << endl;
    score.pop_back(); 
    for(int i = 0; i < score.size(); i++){
        cout << i + 1 << " : " << score[i] << endl;
    }

    //insert
    cout << "Try Insert : " << endl;
    score.insert(score.begin(), 99);
    score.insert(score.begin() + 2, 1231);
    score.insert(score.end(), 12);
    for(int i = 0; i < score.size(); i++){
        cout << i + 1 << " : " << score[i] << endl;
    }

    //erase
    // cout << "Try Erase : " << endl;
    // score.erase(score.begin());
    // score.erase(score.begin() + 2);
    // score.erase(score.end()); //menghapus semua
    // for(int i = 0; i < score.size(); i++){
    //     cout << i + 1 << " : " << score[i] << endl;
    // }

    //mengganti nilai
    cout << "Try Ganti Score : " << endl;
    score[1] = 5;
    for(int i = 0; i < score.size(); i++){
        cout << i + 1 << " : " << score[i] << endl;
    }
    return 0;
}