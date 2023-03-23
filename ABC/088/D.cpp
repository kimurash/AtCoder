#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_H 50
#define MAX_W 50

using namespace std;
using pi16 = pair<int16_t, int16_t>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char field[MAX_H + 2][MAX_W + 2];
int16_t visited[MAX_H + 2][MAX_W + 2];

bool bfs(int16_t H, int16_t W);

int main(){
    int16_t H, W;
    cin >> H >> W;

    int16_t black_count = 0;
    rep(i, 0, H + 2){
        rep(j, 0, W + 2){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                field[i][j] = '#';
            } else{
                cin >> field[i][j];
                if(field[i][j] == '#'){
                    black_count++;
                }
            }
            visited[i][j] = -1;
        }
    }

    bool result = bfs(H, W);
    if(result){
        cout << H * W - visited[H][W] - black_count << endl;
    } else{
        cout << -1 << endl;
    }
}

bool bfs(int16_t H, int16_t W){
    queue<pi16> yet;
    yet.push({1, 1});
    visited[1][1] = 1;

    int16_t x, y;
    while(!yet.empty()){
        pi16 visiting = yet.front();
        yet.pop();

        tie(x, y) = visiting;
        if(x == W && y == H){
            return(true);
        }

        rep(i, 0, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(field[ny][nx] == '.' && visited[ny][nx] == -1){
                yet.push({ nx, ny });
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }

    return(false);
}
