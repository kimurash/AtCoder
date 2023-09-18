// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define MAX 100'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

vector<i32> adjlst[MAX];
i32 indeg[MAX];

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 x, y;
    rep(i, 1, M){
        cin >> x >> y;
        adjlst[x].push_back(y);
        indeg[y]++;
    }

    queue<i32> yet;
    rep(i, 1, N){
        if(indeg[i] == 0){
            yet.push(i);
        }
    }

    i32 answer = 0;
    i32 dp[N + 1] = {0};
    while(!yet.empty()){
        i32 now = yet.front();
        yet.pop();

        for(i32 to: adjlst[now]){
            dp[to] = max(dp[to], dp[now] + 1);
            answer = max(answer, dp[to]);

            indeg[to]--;
            if(indeg[to] == 0){
                yet.push(to);
            }
        }
    }

    cout << answer << endl;
    return(0);
}