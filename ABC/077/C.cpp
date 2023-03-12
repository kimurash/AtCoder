#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N], B[N], C[N];
    rep(i, N){ cin >> A[i]; }
    rep(i, N){ cin >> B[i]; }
    rep(i, N){ cin >> C[i]; }

    sort(A, A + N);
    sort(C, C + N);

    long sum_comb = 0;
    rep(i, N){
        long top = lower_bound(A, A + N, B[i]) - A; // B以上の最小値
        long bottom = N - (upper_bound(C, C + N, B[i]) - C); // Bより大きい最小値

        sum_comb += top * bottom;
    }

    cout << sum_comb << endl;
}
