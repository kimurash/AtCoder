// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define bit(n, k) ((n >> k) & 1)

#define MAX 25

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// dp[S]: 集合Sに属する女性がペアを作る方法の数
mint dp[1 << MAX] = {0};

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 chemist;
    bool a[N][N];
    rep(i, 0, N - 1){
        rep(j, 0, N - 1){
            cin >> chemist;
            a[i][j] = chemist == 1;
        }
    }

    dp[0] = 1;

    rep(S, 1, (1 << N) - 1){
        i16 male = __builtin_popcount(S);
        rep(female, 0, N - 1){
            if(bit(S, female) == 1 && a[male - 1][female]){
                dp[S] += dp[S ^ (1 << female)];
            }
        }
    }

    cout << dp[(1 << N) - 1].val() << endl;
    return(0);
}