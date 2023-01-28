#include <bits/stdc++.h>

using namespace std;

bool is_base(char ch) {
    switch (ch) {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            return (true);
        default:
            return (false);
    }
}

int main() {
    string S;
    cin >> S;
    S.push_back('*');  // 番兵をセット

    int maxlen = 0;
    int begin = 0, crrnt;
    while (begin < S.size()) {
        int len = 0;
        for (crrnt = begin; crrnt < S.size(); crrnt++) {
            if (is_base(S.at(crrnt))) {
                len++;
            } else {
                maxlen = max(maxlen, len);
                break;
            }
        }
        begin = crrnt + 1;
    }

    cout << maxlen << endl;
}