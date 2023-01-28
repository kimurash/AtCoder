#include <bits/stdc++.h>

// #define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define LIMIT 1000

using namespace std;

int main() {
    int32_t N;
    string S;
    cin >> N >> S;

    int32_t cnt = 0;
    char candidate[4] = "";
    rep(i, LIMIT) {
        snprintf(candidate, 4, "%03d", i);
        // printf("%s\n", candidate);

        int8_t idx = 0;  // 調査対象の候補文字列の位置
        rep(j, S.size()) {
            if (S.at(j) == candidate[idx]) {
                if (++idx >= 3) {
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
}