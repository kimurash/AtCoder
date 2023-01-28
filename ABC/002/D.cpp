// D - Faction
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int ans = 0;

void dfs(vector<vector<bool>> &mat, vector<int> v, int k){
    if(k == mat.size()){
        // vに格納されている頂点集合がクリークであるか
        rep(i, v.size()){
            rep2(j, i + 1, v.size()){
                if(!mat.at(v.at(i)).at(v.at(j))){
                    return;
                }
            }
        }
        ans = max(ans, (int) v.size());
    } else{
        dfs(mat, v, k + 1);
        v.push_back(k);
        dfs(mat, v, k + 1);
        v.pop_back();
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<bool>> mat(N, vector<bool>(N, false));
    rep(i, M){
        int x, y;
        cin >> x >> y;
        mat.at(x - 1).at(y - 1) = true;
        mat.at(y - 1).at(x - 1) = true;
    }
    vector<int> v;
    dfs(mat, v, 0);
    cout << ans << endl;
}