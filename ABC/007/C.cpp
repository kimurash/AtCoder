#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;
using pi16 = pair<int16_t, int16_t>;

// XXX: 探索が重いので問題によってはTLE
// distの大小で訪問済みかは判定できる see JOI2011 予選5
bool contain(const vector<pi16>& vec, pi16 elem);

int main() {
    int16_t R, C;
    cin >> R >> C;

    int16_t x, y;
    pi16 start, goal;
    cin >> y >> x;
    start = make_pair(x - 1, y - 1);
    cin >> y >> x;
    goal = make_pair(x - 1, y - 1);

    string field[R];
    rep(i, 0, R) { cin >> field[i]; }

    queue<pi16> yet;           // 未訪問の座標
    vector<pi16> enqueued;     // キューに追加済みの座標
    int16_t dist[C * R] = {0}; // スタート地点からの距離

    yet.push(start);
    enqueued.push_back(start);

    pi16 visiting;
    int16_t dx[] = {0, 1, 0, -1};
    int16_t dy[] = {1, 0, -1, 0};

    while (!yet.empty()) {
        visiting = yet.front();
        yet.pop();
        // printf("(%d, %d)\n", visiting.first, visiting.second);

        if (visiting == goal) {
            cout << dist[visiting.second * C + visiting.first] << endl;
            break;
        }

        rep(i, 0, 4) {
            pi16 adj = make_pair(visiting.first + dx[i], visiting.second + dy[i]);

            if (field[adj.second].at(adj.first) == '.'
                && !contain(enqueued, adj)) {
                yet.push(adj);
                enqueued.push_back(adj);
                dist[adj.second * C + adj.first] = dist[visiting.second * C + visiting.first] + 1;
            }
        }
    }
}

bool contain(const vector<pi16>& vec, pi16 elem) {
    if (find(all(vec), elem) == vec.end()) {
        return (false);
    } else {
        return (true);
    }
}