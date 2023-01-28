// C - Half and Half
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int32_t i = 0; i <= (int32_t)(n); i++)

using namespace std;

int main(){
    int32_t A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int32_t maxXY = max(X, Y);
    int32_t sum = A * X + B * Y + 2 * C * maxXY;
    rep(z, maxXY){
        int32_t x = X - z > 0 ? X - z : 0;
        int32_t y = Y - z > 0 ? Y - z : 0;
        if(A * x + B * y + 2 * C * z < sum){
            sum = A * x + B * y + 2 * C * z;
        }
    }

    cout << sum << endl;
}
