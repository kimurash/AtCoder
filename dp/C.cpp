// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i16 a[N + 1], b[N + 1], c[N + 1];
    rep(i, 1, N){
        cin >> a[i] >> b[i] >> c[i];
    }

    i32 dp[N + 1][3];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];

    rep(i, 2, N){
        rep(j, 0, 2){
            dp[i][j] = 0;
        }
    }

    rep(i, 2, N){
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return(0);
}