// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

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

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i64 a[N + 1];
    rep(i, 1, N){
        cin >> a[i];
    }

    // dp[i][j]: [i, j]の状態から最適に行動した場合のX-Yの値
    i64 dp[N + 1][N + 1];
    if(N & 1){ // 奇数 => 最後に取り除くのは太郎
        rep(i, 1, N){
            dp[i][i] = a[i];
        }
    } else{ // 偶数 => 最後に取り除くのは次郎
        rep(i, 1, N){
            dp[i][i] = -a[i];
        }
    }

    rep(len, 2, N){
        for(int l = 1; l + len-1 <= N; l++){
            int r = l + len-1;
            i32 removed = N - len; // 取り除かれた個数
            if(removed & 1){ // 奇数 => これから取り除くのは次郎
                dp[l][r] = min(
                    dp[l][r - 1] - a[r],
                    dp[l + 1][r] - a[l]
                );
            } else{ // 偶数 => これから取り除くのは太郎
                dp[l][r] = max(
                    dp[l][r - 1] + a[r],
                    dp[l + 1][r] + a[l]
                );
            }
        }
    }

    cout << dp[1][N] << endl;
    return(0);
}