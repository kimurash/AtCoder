#include <bits/stdc++.h>
#include "Minesweeper.h"

/* in order to throw exception of std::out_of_range */
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

Minesweeper::Minesweeper(int H, int W) : height(H), width(W){
    this->field.resize(H);
    rep(i, H){
        cin >> this->field[i];
    }
}

Minesweeper::~Minesweeper(){ }

void Minesweeper::count_bomb(int i, int j){
    if(this->field[i][j] == '#'){
        cout << '#';
    } else{
        int cnt = 0;
        for (int k = i - 1; k <= i + 1; k++){
            for(int l = j - 1; l <= j + 1; l++){
                if(k == i && l == j){
                    continue;
                } else{
                    if(this->is_bomb(k, l)){
                        cnt++;
                    }
                }
            }
        }
        cout << cnt;
    }
}

bool Minesweeper::is_bomb(int i, int j) const {
    if(i < 0 || this->height <= i ||
        j < 0 || this->width <= j){
        return(false);        
    } else{
        if(this->field[i][j] == '#'){
            return(true);
        } else{
            return(false);
        }
    }
}
