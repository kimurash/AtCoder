// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return(true);
    }
    return(false);
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return(true);
    }
    return(false);
}

int main(){
    cin.tie(nullptr);

    i16 N;
    i32 K;
    cin >> N >> K;

    i32 a[N + 1];
    rep(i, 1, N){
        cin >> a[i];
    }

    bool dp[K + 1];
    dp[0] = true;
    rep(i, 1, K){
        dp[i] = false;
        rep(j, 1, N){
            if(a[j] == i){
                dp[i] = true;
            } else if(a[j] < i){
                dp[i] |= !dp[i - a[j]];
            }
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;
    return(0);
}