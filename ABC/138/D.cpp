#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_NODE 200000

using namespace std;

// countだとstd::countと重複する
int32_t sumx[MAX_NODE] = {0};
vector<int32_t> edge[MAX_NODE];

void dfs(int32_t visiting, int32_t parent){
    for(int32_t adj : edge[visiting]){
        if(adj != parent){
            sumx[adj] += sumx[visiting];
            dfs(adj, visiting);
        }
    }
}

int main(){
    int32_t N, Q;
    cin >> N >> Q;

    int32_t a, b;
    rep(i, 0, N - 1){
        cin >> a >> b;
        edge[a - 1].push_back(b - 1);
        edge[b - 1].push_back(a - 1);
    }

    int32_t p, x;
    rep(i, 0, Q){
        cin >> p >> x;
        sumx[p - 1] += x;
    }

    dfs(0, -1);

    rep(i, 0, N - 1){
        printf("%d ", sumx[i]);
    }
    cout << sumx[N - 1] << endl;
}