#include <bits/stdc++.h>
#include "Minesweeper.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    Minesweeper sweeper(H, W);

    rep(i, H){
        rep(j, W){
            sweeper.count_bomb(i, j);
        }
        cout << endl;
    }
}