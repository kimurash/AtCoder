#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;
using pi32 = pair<int32_t, int32_t>;

int16_t N;
int32_t H, W;

int64_t shortest_path(const string *field, pi32 start, pi32 goal);

int main() {
    cin >> H >> W >> N;

    string field[H];  // JOI町の平面図
    pi32 factory[N];  // チーズ工場の位置
    pi32 nest;        // スタート時点

    rep(i, 0, H) {
        cin >> field[i];
        rep(j, 0, W) {
            char block = field[i].at(j);
            if (isdigit(block)) {
                factory[block - '1'] = make_pair(j, i);
            } else if (block == 'S') {
                nest = make_pair(j, i);
            }
        }
    }

    int64_t sum = shortest_path(field, nest, factory[0]);
    rep(i, 0, N - 1) {
        sum += shortest_path(field, factory[i], factory[i + 1]);
    }

    cout << sum << endl;
}

int64_t shortest_path(const string *field, pi32 start, pi32 goal) {
    queue<pi32> yet;      // 未訪問の座標
    int64_t dist[W * H];  // スタート地点からの距離
    fill_n(dist, W * H, LONG_MAX);

    dist[start.second * W + start.first] = 0;
    yet.push(start);

    pi32 visiting;
    int32_t dx[] = {0, 1, 0, -1};
    int32_t dy[] = {1, 0, -1, 0};

    while (!yet.empty()) {
        visiting = yet.front();
        yet.pop();
        // printf("(%d, %d)\n", visiting.first, visiting.second);

        if (visiting == goal) {
            return (dist[visiting.second * W + visiting.first]);
        }

        rep(i, 0, 4) {
            pi32 adj = make_pair(visiting.first + dx[i], visiting.second + dy[i]);
            if (adj.first < 0 || W <= adj.first || adj.second < 0 ||
                H <= adj.second) {
                continue;
            }

            int32_t visiting_idx = visiting.second * W + visiting.first;
            int32_t adj_idx = adj.second * W + adj.first;

            if (field[adj.second].at(adj.first) != 'X'
                && dist[visiting_idx] + 1 < dist[adj_idx]) {
                dist[adj_idx] = dist[visiting_idx] + 1;
                yet.push(adj);
            }
        }
    }

    return (0);  // never reached
}
