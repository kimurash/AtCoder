// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()
// #define bit(n, k) ((n >> k) & 1)

#define MAX 100'009
#define MOD 1'000'000'007

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

vector<i32> adjlst[MAX];
bool visited[MAX];

// dp[i][j]: iを根とする部分木においてiを(黒く|白く)塗る方法の総数
mint dp[MAX][2];

void dfs(i32 now);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 x, y;
    rep(i, 1, N - 1){
        cin >> x >> y;
        adjlst[x].push_back(y);
        adjlst[y].push_back(x);

        dp[i][0] = dp[i][1] = 1;
    }
    dp[N][0] = dp[N][1] = 1;

    dfs(1);

    cout << (dp[1][0].val() + dp[1][1].val()) % MOD << endl;
    return(0);
}

void dfs(i32 now){
    if(visited[now]){
        return;
    }

    visited[now] = true;

    for(i32 next: adjlst[now]){
        if(!visited[next]){
            dfs(next);
            dp[now][0] *= dp[next][0] + dp[next][1];
            dp[now][1] *= dp[next][0];
        }
    }

    return;
}