// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    double p[N + 1];
    rep(i, 1, N){
        cin >> p[i];
    }

    // dp[i][j]: i枚目までのコインを投げたときに表がj枚出る確率
    double dp[N + 1][N + 1];
    rep(i, 2, N){
        rep(j, 0, N){
            dp[i][j] = 0;
        }
    }

    dp[1][0] = 1 - p[1];
    dp[1][1] = p[1];
    rep(i, 2, N){
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
        rep(j, 1, i - 1){
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
        }
        dp[i][i] = dp[i - 1][i - 1] * p[i];
    }

    double answer = 0;
    rep(j, N / 2 + 1, N){
        answer += dp[N][j];
    }

    printf("%.10f\n", answer);
    return(0);
}