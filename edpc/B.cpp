// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define INF 2'000'000'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    i32 h[N + 1];
    rep(i, 1, N){
        cin >> h[i];
    }

    // dp[i]: 足場iに辿り着くまでに支払うコスト
    i32 dp[N + 1];
    dp[1] = 0;
    rep(i, 2, N){
        dp[i] = INF;
    }

    rep(i, 1, N){
        rep(k, 1, K){
            if(i + k <= N){
                dp[i + k] = min(
                    dp[i + k],
                    dp[i] + abs(h[i] - h[i + k])
                );
            }
        }
    }

    cout << dp[N] << endl;
    return(0);
}