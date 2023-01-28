#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

class Coord{
public:
    int32_t x;
    int32_t y;

    Coord(){}
    Coord(int32_t x, int32_t y): x(x), y(y){}

    /*
        メンバ変数は全てpublicなのでfriendは付けなくてもよいが,
        付けないと仮引数が多すぎると怒られた
    */
    friend Coord operator+(const Coord& right, const Coord& left){
        return(Coord(right.x + left.x, right.y + left.y));
    }

    friend Coord operator-(const Coord& right, const Coord& left){
        return(Coord(right.x - left.x, right.y - left.y));
    }

    friend bool operator==(const Coord& right, const Coord& left){
        return(right.x == left.x && right.y == left.y);
    }
};

// 与えられた点が平面内に含まれるか
bool contain(vector<Coord>& plane, Coord coord){
    if(find(plane.begin(), plane.end(), coord) == plane.end()){
        return(false);
    } else{
        return(true);
    }
}

int main(){
    int m;
    cin >> m;

    int32_t x, y;
    Coord constel[m]; // 星座
    rep(i, m){
        cin >> x >> y;
        constel[i] = Coord(x, y);
    }

    int n;
    cin >> n;

    vector<Coord> plane; // 平面
    rep(i, n){
        cin >> x >> y;
        plane.push_back(Coord(x, y));
    }

    rep(i, n){ // 写真中の1点を始点として選ぶ
        Coord crrnt = plane.at(i);
        Coord next;
        bool flg = true;
        rep2(j, 1, m){ // 平行移動後の全ての点が写真に含まれるか調べる
            next = crrnt + (constel[j] - constel[j - 1]);
            if(contain(plane, next)){
                crrnt = next;
            } else{
                flg = false;
                break;
            }
        }

        // 全て含まれていれば移動量を出力して終了
        if(flg){
            Coord diff = plane.at(i) - constel[0];
            cout << diff.x << " " << diff.y << endl;
            break;
        }
    }
}
