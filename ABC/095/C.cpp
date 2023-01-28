#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int16_t A, B, C;
    cin >> A >> B >> C;

    int32_t X, Y;
    cin >> X >> Y;

    // Aピザx1 + Bピザx1 vs. ABピザx2
    int32_t price = 0;
    if (A + B < 2 * C) {
        price += (A + B) * min(X, Y);
    } else {
        price += 2 * C * min(X, Y);
    }

    if (X < Y) {    // Bピザを追加
        if (B < 2 * C) {  // Bピザ
            price += B * (Y - X);
        } else {
            price += 2 * C * (Y - X);
        }
    } else {  // Aピザを追加
        if (A < 2 * C) {
            price += A * (X - Y);
        } else {
            price += 2 * C * (X - Y);
        }
    }

    cout << price << endl;
}