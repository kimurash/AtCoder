// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return(true);
    }
    return(false);
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return(true);
    }
    return(false);
}

int main(){
    cin.tie(nullptr);

    i16 N;
    i32 K;
    cin >> N >> K;

    i32 a[N + 1];
    rep(i, 1, N){
        cin >> a[i];
    }

    // dp[i][j]: i番目までの子供にj個の飴を配る方法の数
    mint dp[N + 1][K + 1];

    rep(j, 0, K){
        if(j <= a[1]){
            dp[1][j] = 1;
        } else{
            dp[1][j] = 0;
        }
    }

    mint acc[K + 1];
    rep(i, 2, N){
        dp[i][0] = acc[0] = dp[i - 1][0];
        rep(j, 1, K){
            acc[j] = dp[i - 1][j] + acc[j - 1];
            dp[i][j] = acc[j] - (
                j - a[i] - 1 >= 0 ? acc[j - a[i] - 1] : 0
            );
        }
    }

    cout << dp[N][K].val() << endl;
    return(0);
}