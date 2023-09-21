// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define MAX 309

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i16 N;
/* dp[i][j][k];
1貫のコインがi皿
2貫のコインがj皿
3貫のコインがk皿の状態から食べ終わるまでの回数の期待値
*/
double dp[MAX][MAX][MAX];

double calc_ev(i16 i, i16 j, i16 k);

int main() {
    cin.tie(nullptr);

    cin >> N;

    i16 a[N + 1];
    i16 cnt[4] = {0};
    rep(i, 1, N) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    printf("%.10f\n", calc_ev(cnt[1], cnt[2], cnt[3]));
    return (0);
}

double calc_ev(i16 c1, i16 c2, i16 c3) {
    i16 csum = c1 + c2 + c3;
    if (csum == 0) {
        return (0);
    }

    if (dp[c1][c2][c3] > 0) {
        return (dp[c1][c2][c3]);
    }

    double num = N; // サイコロを1回振る
    if (c1 > 0) {
        num += calc_ev(c1 - 1, c2, c3) * (1.0 * c1);
    }
    if (c2 > 0) {
        num += calc_ev(c1 + 1, c2 - 1, c3) * (1.0 * c2);
    }
    if (c3 > 0) {
        num += calc_ev(c1, c2 + 1, c3 - 1) * (1.0 * c3);
    }
    dp[c1][c2][c3] = num / csum;

    return (dp[c1][c2][c3]);
}