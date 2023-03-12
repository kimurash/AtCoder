#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

// 許容誤差は10^-8以下
#define EPS 1e-9

using namespace std;

double P;

double objective(double x){
    return(x + P * pow(2.0, -(x / 1.5)));
}

int main(){
    cin >> P;

    /* 3分探索で目的関数の極値を求める */
    // Pが最大値の場合でも極値が100以下になることをdesmosで確認
    double low = 0, high = 100.0;
    while(abs(high - low) > EPS){
        double x1 = (2.0 * low + high) / 3.0;
        double x2 = (low + 2.0 * high) / 3.0;

        double f1 = objective(x1);
        double f2 = objective(x2);

        if(f1 < f2){
            high = x2;
        } else{
            low = x1;
        }
    }

    cout << setprecision(15) << objective(min(low, high)) << endl;
}