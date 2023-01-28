// B - Reclamation
#include <bits/stdc++.h>

#define HW 10
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

/* 全ての陸地は繋がっているか */
bool is_connected(vector<string> map);
/* (i, j)から到達できる全陸地マスのcheckedをtrueにする */
void fill_island(vector<string> map, vector<vector<bool>> &checked, int i, int j);
bool is_valid_move(vector<string> map, vector<vector <bool>> checked, int i, int j);

int main(){
    vector<string> map(HW);
    // vector<vector<bool>> checked(HW, vector<bool>(HW, false));
    
    rep(i, HW){
        cin >> map.at(i);
    }

    if(is_connected(map)){
        cout << "YES" << endl;
    } else{
        rep(i, HW){
            rep(j, HW){
                if(map.at(i).at(j) == 'o'){
                    continue;
                }
                map.at(i).at(j) = 'o'; // 埋め立てたと仮定
                // cout << "i:" << i << " j:" << j << endl;

                if(is_connected(map)){
                    cout << "YES" << endl;
                    return(0);
                }

                map.at(i).at(j) = 'x'; // 戻す
            }
            // cout << endl;
        }
        cout << "NO" << endl;
    }
}

bool is_connected(vector<string> map){
    // 陸地マスを1つ見つける
    int x, y;
    rep(i, HW){
        rep(j, HW){
            if(map.at(i).at(j) == 'o'){
                y = i;
                x = j;
                break;
            }
        }
    }

    vector<vector<bool>> checked(HW, vector<bool>(HW, false));
    fill_island(map, checked, y, x);

    bool connected = true;
    rep(i, HW){
        rep(j, HW){
            if(map.at(i).at(j) == 'o'){
                if(!checked.at(i).at(j)){
                    // 到達できていない陸地マスがある
                    connected = false;
                }
            }
        }
    }
    return(connected);
}


void fill_island(vector<string> map, vector<vector<bool>> &checked, int i, int j){
    /* ベースケース */

    /* 再帰ステップ */
    checked.at(i).at(j) = true;

    if(is_valid_move(map, checked, i - 1, j)){
        fill_island(map, checked, i - 1, j);
    }

    if(is_valid_move(map, checked, i + 1, j)){
        fill_island(map, checked, i + 1, j);
    }

    if(is_valid_move(map, checked, i, j - 1)){
        fill_island(map, checked, i, j - 1);
    }

    if(is_valid_move(map, checked, i, j + 1)){
        fill_island(map, checked, i, j + 1);
    }
}

bool is_valid_move(vector<string> map, vector<vector <bool>> checked, int i, int j){
    int N = map.size();

    /* 移動先が地図の外 */
    if(i < 0 || N <= i || j < 0 || N <= j){
        return(false);
    }

    /* 移動先が海マス */
    if(map.at(i).at(j) == 'x'){
        return(false);
    }

    /* 移動先が既に調べているマス */
    if(checked.at(i).at(j)){
        return(false);
    }

    return(true);
}