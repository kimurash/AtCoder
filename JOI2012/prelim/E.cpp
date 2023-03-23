#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX 100

using namespace std;
using pi16 = pair<int16_t, int16_t>;

int16_t W, H;
int16_t premise[MAX + 2][MAX + 2]; // JOI社の縦問の配置

int dx[2][6] = {
    {1, 0, -1, 0, -1, -1}, // 偶数行
    {1, 0, -1, 0, 1, 1},   // 奇数行
};

int dy[2][6] = {
    {0, 1, 0, -1, 1, -1}, // 偶数行
    {0, 1, 0, -1, 1, -1}, // 奇数行
};

void frame_building(int x, int y);
bool judge_area(int x, int y, int16_t kind);

int main() {
    cin >> W >> H;

    rep(i, 0, H + 2) {
        rep(j, 0, W + 2) {
            if ((i == 0) | (i == H + 1) | (j == 0) | (j == W + 1)) {
                premise[i][j] = 0;
            } else {
                cin >> premise[i][j];
            }
        }
    }

    // 建物の外側をラベリングする
    frame_building(0, 0);
/*
    rep(i, 0, H + 2) {
        rep(j, 0, W + 2) {
            printf("%3d", premise[i][j]);
        }
        putchar('\n');
    }
//*/
    int32_t wall_length = 0;
    rep(i, 0, H + 2) {
        rep(j, 0, W + 2) {
            if(premise[i][j] != -1){
                continue;
            }

            int nx, ny;
            rep(k, 0, 6){
                nx = j + dx[i % 2][k];
                ny = i + dy[i % 2][k];
                if(judge_area(nx, ny, 1)){
                    wall_length++;
                }
            }
        }
    }

    cout << wall_length << endl;
}

void frame_building(int x, int y) {
    premise[y][x] = -1;
    int nx, ny;
    rep(i, 0, 6){
        nx = x + dx[y % 2][i];
        ny = y + dy[y % 2][i];
        if(judge_area(nx, ny, 0)){
            frame_building(nx, ny);
        }
    }
}

bool judge_area(int x, int y, int16_t kind) {
    if ((y < 0) || (H + 2 <= y) || (x < 0) || (W + 2 <= x)) {
        return (false);
    }
    return (premise[y][x] == kind);
}
