#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_BLOCK 90

using namespace std;

int16_t max_block = 0;
int16_t plaza[MAX_BLOCK + 2][MAX_BLOCK + 2];

void dfs(int16_t i, int16_t j, int16_t block_count){
    plaza[i][j] = 0; // 薄氷を割る

    bool can_move = false;
    if(plaza[i - 1][j] == 1){ // 北
        can_move = true;
        dfs(i - 1, j, block_count + 1);
    }
    if(plaza[i][j + 1] == 1){ // 東
        can_move = true;
        dfs(i, j + 1, block_count + 1);
    }
    if(plaza[i + 1][j] == 1){ // 南
        can_move = true;
        dfs(i + 1, j, block_count + 1);
    }
    if(plaza[i][j - 1] == 1){ // 西
        can_move = true;
        dfs(i, j - 1, block_count + 1);
    }

    plaza[i][j] = 1; // 割った薄氷を元に戻す
    
    if(!can_move){
        max_block = max(max_block, block_count);
    }
}

int main(){
    int16_t m, n;
    cin >> m >> n;

    rep(i, 0, n + 2){
        rep(j, 0, m + 2){
            if(i == 0 || i == (n+1) || j == 0 || j == (m+1)){
                plaza[i][j] = 0;
            } else{
                cin >> plaza[i][j];
            }
        }
    }

    rep(i, 1, n + 1){
        rep(j, 1, m + 1){
            if(plaza[i][j] == 1){
                dfs(i, j, 1);
            }
        }
    }

    cout << max_block << endl;
}
