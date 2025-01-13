// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

using mint = atcoder::modint998244353;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, M, K;
    cin >> N >> M >> K;

    mint dp[N + 1][N * M + 1];
    rep(i, 0, N){
        rep(j, 0, N * M){
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    rep(i, 0, N - 1){
        rep(j, 0, N * M){
            rep(k, 1, M){
                if(j + k <= N * M){
                    dp[i + 1][j + k] += dp[i][j];
                }
            }
        }
    }

    mint ans = 0;
    rep(k, 0, K){
        ans += dp[N][k];
    }

    cout << ans.val() << endl;
    return(0);
}
