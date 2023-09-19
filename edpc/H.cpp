// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;
using mint = atcoder::modint1000000007;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    char grid[H + 1][W + 1];
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> grid[i][j];
        }
    }

    // dp[i][j]: (i,j)に到達する経路数
    mint dp[H + 1][W + 1];
    dp[0][1] = dp[1][0] = 1;
    rep(i, 1, H){
        rep(j, 1, W){
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
            } else{
                if(i == 1){ // 1行目
                    dp[i][j] = dp[i][j - 1];
                } else if(j == 1){ // 1列目
                    dp[i][j] = dp[i - 1][j];
                } else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
    }

    cout << dp[H][W].val() << endl;
    return(0);
}