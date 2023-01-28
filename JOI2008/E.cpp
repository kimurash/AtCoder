#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_ROW 10

using namespace std;

int R, C;

// 行を裏返す関数
void flip_row(bool *row){
    rep(j, C){
        if(row[j]){
            row[j] = false;
        } else{
            row[j] = true;
        }
    }
}

int main(){
    cin >> R >> C;

    int cracker;
    bool mat[R][C];
    rep(i, R){
        rep(j, C){
            cin >> cracker;
            if(cracker == 1){
                mat[i][j] = true;   // 表面が焼ける
            } else{
                mat[i][j] = false;  // 裏面が焼ける
            }
        }
    }

    bool sim[R][C];     // シミュレーション状態
    int max_cnt = 0;    // 出荷できる最大枚数
    for (int b = 0; b < (1 << R); b++) {
        bitset<MAX_ROW> bset(b);

        rep(i, R){
            memcpy(sim[i], mat[i], sizeof(bool) * C); // 1行分コピー
            if(bset.test(i)){
                flip_row(sim[i]);   // 列を反転
            }
        }

        int32_t cnt = 0; // 出荷できる枚数
        rep(j, C){
            int32_t n_salable = 0;  // 裏面が焼ける枚数
            rep(i, R){
                if(!sim[i][j]){
                    n_salable++;
                }
            }

            if(n_salable <= (R / 2)){    // 列を裏返す
                cnt += R - n_salable;
            } else{
                cnt += n_salable;
            }
        }

        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << endl;
}