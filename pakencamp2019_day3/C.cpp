#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MAX_MEMBER 100
#define MAX_SONG 100

using namespace std;

int16_t N, M;
int32_t score[MAX_MEMBER][MAX_SONG];

long total_score(int i, int j){
    long sum = 0;
    rep(member, N){
        sum += max(score[member][i], score[member][j]);
    }
    return(sum);
}

int main(){
    cin >> N >> M;

    rep(i, N){
        rep(j, M){
            cin >> score[i][j];
        }
    }

    // 全てに曲の組合せについて得点を求める
    long total, max_total = 0;
    rep(i, M){
        rep2(j, i + 1, M){
            total = total_score(i, j);
            max_total = max(max_total, total);
        }
    }

    cout << max_total << endl;
}