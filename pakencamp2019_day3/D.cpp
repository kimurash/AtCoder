// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main() {
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 cnt[N + 1][3];
    rep(j, 1, N) {
        rep(c, 0, 2) {
            cnt[j][c] = 0;
        }
    }

    char S;
    rep(i, 1, 5) {
        rep(j, 1, N) {
            cin >> S;
            switch (S) {
                case 'R':
                    cnt[j][0]++;
                    break;
                case 'B':
                    cnt[j][1]++;
                    break;
                case 'W':
                    cnt[j][2]++;
                    break;
            }
        }
    }

    // dp[j][c]: j列目を色cで塗ったときの塗り替え回数の最小値
    i16 dp[N + 1][3];

    dp[1][0] = 5 - cnt[1][0];
    dp[1][1] = 5 - cnt[1][1];
    dp[1][2] = 5 - cnt[1][2];

    rep(j, 2, N) {
        rep(c, 0, 2) {
            dp[j][c] = min(
                dp[j - 1][(c + 1) % 3],
                dp[j - 1][(c + 2) % 3]
            ) + (5 - cnt[j][c]);
        }
    }

    cout << min({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return (0);
}