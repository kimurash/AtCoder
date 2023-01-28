#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

// 中央値からの|差|を合計する
int64_t sun_from_median(int32_t *items, int N){
    sort(items, items + N);

    // 中央値を求める
    int32_t median;
    if(N & 1){  // odd
        median = items[N / 2];
    } else{ // even
        median = (items[(N / 2) - 1] + items[(N / 2)]) / 2;
    }
    
    // 中央値との|差|を合計する
    int64_t dist = 0;
    rep(i, N){
        dist += abs(items[i] - median);
    }

    return(dist);
}

int main(){
    int N;
    cin >> N;

    int32_t A[N], B[N];
    int64_t dist = 0;
    rep(i, N){
        cin >> A[i] >> B[i];
        dist += abs(A[i] - B[i]);
    }

    dist += sun_from_median(A, N);
    dist += sun_from_median(B, N);

    cout << dist << endl;
}