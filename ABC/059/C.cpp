// C - Sequence
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N){
        cin >> a.at(i);
    }

    // 偶数項を正とした場合
    long cntA = 0, cntB = 0;
    long sum = 0;
    rep(i, N){
        sum += a.at(i);
        if(i % 2 == 0){ // even
            if(sum <= 0){
                int upd = abs(sum) + 1;
                cntA += upd;
                sum += upd;
            }
        } else{ // odd
            if(sum >= 0){
                int upd = abs(sum) + 1;
                cntA += upd;
                sum -= upd;
            }
        }
    }

    sum = 0;

    // 奇数項を正としたとき
    rep(i, N){
        sum += a.at(i);
        if(i % 2 == 0){ // even
            if(sum >= 0){
                int upd = abs(sum) + 1;
                cntB += upd;
                sum -= upd;
            }
        } else{ // odd
            if(sum <= 0){
                int upd = abs(sum) + 1;
                cntB += upd;
                sum += upd;
            }
        }
    }

    cout << min(cntA, cntB) << endl;
}
