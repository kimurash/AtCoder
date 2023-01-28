// A - Airport Bus
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int N, C, K;
    cin >> N >> C >> K;

    priority_queue<int, vector<int>, greater<int>> T;
    int t;
    rep(i, N){
        cin >> t;
        T.push(t);
    }

    int bus = 0; // バスの台数
    int dtime;   // バスの出発時刻

    int pssnger = 0;    //  乗客の数 
    int next;           // 次の乗客

    while(!T.empty()){
        dtime = T.top() + K;
        T.pop();
        bus++;  pssnger++;

        while(!T.empty() && pssnger < C){
            next = T.top();
            T.pop();
            if(next > dtime){
                T.push(next);
                break;
            }
            pssnger++;
        }

        pssnger = 0;
    }

    cout << bus << endl;
}