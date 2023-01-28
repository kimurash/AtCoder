#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_BUILDING 15

using namespace std;

int main(){
    int16_t N, K;
    cin >> N >> K;

    int32_t building[N];
    rep(i, N){
        cin >> building[i];
    }

    int64_t mincost = INT64_MAX;
    for (int b = 0; b < (1 << N - 1); b++) {
        bitset<MAX_BUILDING> bset(b);
        if(bset.count() < K - 1){
            continue;
        }

        int32_t crrnt_max = building[0];
        int64_t cost = 0;

        rep(i, N - 1){
            if(bset.test(i)){   // 見えるようにする
                if(building[i + 1] <= crrnt_max){
                    cost += (crrnt_max + 1) - building[i + 1];
                    crrnt_max++;
                } else{
                    crrnt_max = building[i + 1];
                }
            } else{     // 見えなくてもよい
                crrnt_max = max(
                    crrnt_max,
                    building[i + 1]
                );
            }
        }
        mincost = min(mincost, cost);
    }

    cout << mincost << endl;
}