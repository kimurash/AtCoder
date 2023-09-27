// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define MAX 409

using namespace std;

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

// dp[l][r]; [l, r]までのスラインをまとめるための最小コスト
i64 dp[MAX][MAX];

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 a;
    i64 acc[N + 1] = {0};
    rep(i, 1, N){
        cin >> a;
        acc[i] =  acc[i - 1] + a;
        dp[i][i] = a;
    }

    rep(len, 1, N){
        rep(l, 1, N - len){
            i32 r = l + len;
            dp[l][r] = INT64_MAX;
            rep(sep, l, r - 1){
                i64 cost = 0;
                if(l != sep){
                    cost += dp[l][sep];
                }
                if(sep + 1 != r){
                    cost += dp[sep + 1][r];
                }

                chmin(
                    dp[l][r],
                    dp[l][sep]
                    + dp[sep + 1][r]
                    + (acc[sep] - acc[l - 1])
                    + (acc[r] - acc[sep])
                );
            }
        }
    }

    cout << dp[1][N] - acc[N] << endl;
    return(0);
}