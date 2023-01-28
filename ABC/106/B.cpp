#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        int count = 2;
        for (int div = 2; div < i; div++) {
            if (i % div == 0) {
                count++;
            }
        }
        if (count == 8) {
            ans++;
        }
    }

    cout << ans << endl;
}