// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

class SegmentTree{
private:
    // セグメント木の要素数の上限
    // N以上で最小の2のべき+1乗とする
    static const int32_t MAX_NODE = 1 << 20;
    // 1始まりのセグメント木
    // dp[h]:単調増加列の最後の高さがhとなる場合の美しさの総和の最大値
    int64_t data[MAX_NODE];
public:
    int32_t range = 1; // セグメント木がカバーする配列の範囲

    /**
     * @param[in] N 配列の要素数
    */
    SegmentTree(int32_t N){
        while(this->range < N){
            this->range *= 2;
        }
        // 葉をN個以上にするにはもう1段深くしないといけない
        rep(i, 1, this->range * 2){
            this->data[i] = 0;
        }
    }

    /**
     * data[pos]をxで更新する
     * 
     * @param[in] pos 更新対象の配列の添字
     * @param[in] x   更新後の値
    */
    void update(int32_t pos, int64_t x){
        pos = pos + this->range - 1;
        if(this->data[pos] >= x){
            return;
        }

        this->data[pos] = x;
        while(pos > 1){
            pos /= 2;
            this->data[pos] = max(
                this->data[2 * pos],
                this->data[2 * pos + 1]
            );
        }
    }

    /**
     * [l, r]に対するクエリに答える
     * 
     * @param[in] l 求めたい区間の左端
     * @param[in] r 求めたい区間の右端
     * @param[in] a 節に対応する区間の左端
     * @param[in] b 節に対応する区間の右端
     * @param[in] u 現在の節番号
     * @return int32_t [L, R]に対するクエリの結果
    */
    int64_t query(int32_t l, int32_t r, int32_t a, int32_t b, int32_t u){
        // ベースケース
        if(b < l || r < a){
            // 結果に影響しない値を返す
            return(0);
        }
        if(l <= a && b <= r){
            return(this->data[u]);
        }

        // 再帰ステップ
        int m = (a + b) / 2;
        return(max(
            this->query(l, r, a, m, 2 * u),
            this->query(l, r, m + 1, b, 2 * u + 1)
        ));
    }
};

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 h[N + 1], a[N + 1];
    rep(i, 1, N){
        cin >> h[i];
    }
    rep(i, 1, N){
        cin >> a[i];
    }

    SegmentTree segtree = SegmentTree(N);

    rep(i, 1, N){
        i64 cand = segtree.query(1, h[i] - 1, 1, segtree.range, 1) + a[i];
        segtree.update(h[i], cand);
    }

    cout << segtree.query(1, segtree.range, 1, segtree.range, 1) << endl;
    return(0);
}