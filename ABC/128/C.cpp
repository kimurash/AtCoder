#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int16_t k, sw;
    vector<int16_t> bulbs[M];
    rep(i, M){
        cin >> k;
        rep(j, k){
            cin >> sw;
            bulbs[i].push_back(sw);
        }
    }
    
    int16_t r;
    bool p[M];
    rep(i, M){
        cin >> r;
        p[i] = r == 1 ? true : false;
    }

    // 全てのスイッチのon/offの組み合わせを列挙
    int16_t ans = 0;
    for(int b = 0; b < (1 << N); b++){
        bool flg = true;
        rep(i, M){  // 全ての電球が点灯するか調べる
            int16_t on = 0; // 接続されているスイッチのonの個数
            rep(j, bulbs[i].size()){
                if((b >> (bulbs[i].at(j)) - 1) & 1){
                    on++;
                }
            }

            if(p[i]){   // 余り1のとき点灯
                if(on % 2 != 1){
                    flg = false;
                    break;
                }
            } else{ // 余り0のとき点灯
                if(on % 2 != 0){
                    flg = false;
                    break;
                }
            }
        }

        if(flg){ ans++; }
    }

    cout << ans << endl;
}