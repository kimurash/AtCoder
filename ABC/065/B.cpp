// B - Trained?
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> buttons(N);
    rep(i, N){ cin >> buttons.at(i); }

    // vector<int> pushed(0);
    // cout << pushed.size() << endl;
    int on = 1;
    int count = 0;
    while(count < N){
        if(on == 2){
            cout << count << endl;
            break;
        } else{
            // pushed.push_back(on);
            // cout << "push:" << on << endl;
            count++;
            on = buttons.at(on - 1);
            // cout << "next:" << on << endl;
        }
    }

    if(count >= N){
        cout << -1 << endl;
    }
}