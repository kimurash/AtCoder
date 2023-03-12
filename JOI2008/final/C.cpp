#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int32_t N, M;
    cin >> N >> M;

    // 先頭要素はダーツを投げない場合の0
    int32_t P[N+1] = {0};
    rep(i, 1, N + 1){ cin >> P[i]; }
    
    int32_t n_comb = (N+1) * (N+1); // 点数の組み合わせの数
    int32_t Q[n_comb] = {0};
    rep(i, 0, N + 1){
        rep(j, 0, N + 1){
            Q[i * (N+1) + j] = P[i] + P[j];
        }
    }

    sort(Q, Q + n_comb);

    int32_t max_point = 0;
    rep(i, 0, n_comb){
        int32_t upper = upper_bound(Q, Q + n_comb, M - Q[i]) - Q;
        int32_t point;
        if(upper == 0){
            point = Q[i] + Q[0];
        } else{
            point = Q[i] + Q[upper - 1];
        }

        if(point <= M && max_point < point){
            max_point = point;
        }
    }

    cout << max_point << endl;
}