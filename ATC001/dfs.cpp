// A - Depth-First  Search
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool is_reachable(vector<string> &map, vector<vector<bool>> &checked,  int i, int j);
bool is_valid_move(vector<string> &map, vector<vector <bool>> &checked, int i, int j);

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> map(H);
    rep(i, H){
        cin >> map.at(i);
    }

    int sx, sy;
    rep(i, map.size()){
        rep(j, map.at(0).size()){
            if(map.at(i).at(j) == 's'){
                sy = i;
                sx = j;
                break;
            }
        }
    }

    vector<vector<bool>> checked(map.size(), vector<bool>(map.at(0).size(), false));
    if(is_reachable(map, checked, sy, sx)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

bool is_reachable(vector<string> &map, vector<vector<bool>> &checked, int i, int j){
    /* ベースケース */
    if(map.at(i).at(j) == 'g'){
        return(true);
    }

    /* 再帰ステップ */
    checked.at(i).at(j) = true;
    bool result = false;
    
    if(is_valid_move(map, checked, i - 1, j)
        && is_reachable(map, checked, i - 1, j)){
        result = true;
    }

    if(is_valid_move(map, checked, i + 1, j)
        && is_reachable(map, checked, i + 1, j)){
        result = true;
    }

    if(is_valid_move(map, checked, i, j - 1)
        && is_reachable(map, checked, i, j - 1)){
        result = true;
    }

    if(is_valid_move(map, checked, i, j + 1)
        && is_reachable(map, checked, i, j + 1)){
        result = true;
    }

    return(result);
}

bool is_valid_move(vector<string> &map, vector<vector <bool>> &checked, int i, int j){

    /* 移動先が地図の外 */
    if(i < 0 || map.size() <= i || j < 0 || map.at(0).size() <= j){
        return(false);
    }

    /* 移動先が壁マス */
    if(map.at(i).at(j) == '#'){
        return(false);
    }

    /* 移動先が既に調べているマス */
    if(checked.at(i).at(j)){
        return(false);
    }

    return(true);
}