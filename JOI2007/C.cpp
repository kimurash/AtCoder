/* 最古の遺跡 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

uint32_t calc_area(int16_t x_diff, int16_t y_diff) {
    return (x_diff * x_diff + y_diff * y_diff);
}

int main() {
    int16_t n;
    cin >> n;

    vector<pair<int16_t, int16_t> > pillars;
    int16_t x, y;
    rep(i, n) {
        cin >> x >> y;
        pillars.push_back(make_pair(x, y));
    }

    sort(all(pillars));

    // ソートされているか確認
    // pair<int16_t, int16_t> pillar;
    // rep(i, n){
    //     pillar = pillars.at(i);
    //     cout << pillar.first << " " << pillar.second << endl;
    // }

    uint32_t max_area = 0;
    int16_t x_k, y_k;
    int16_t x_l, y_l;
    pair<int16_t, int16_t> pillar_i, pillar_j;
    rep(i, n) {
        rep2(j, i + 2, n) {
            pillar_i = pillars.at(i);
            pillar_j = pillars.at(j);
            x_k = pillar_j.first + (pillar_j.second - pillar_i.second);
            y_k = pillar_j.second - (pillar_j.first - pillar_i.first);

            x_l = pillar_i.first + (pillar_j.second - pillar_i.second);
            y_l = pillar_i.second - (pillar_j.first - pillar_i.first);

            if (binary_search(all(pillars), make_pair(x_k, y_k)) &&
                binary_search(all(pillars), make_pair(x_l, y_l))) {
                uint32_t area = calc_area(abs(x_k - x_l), abs(y_k - y_l));
                if (max_area < area) {
                    max_area = area;
                }
            }
        }
    }

    cout << max_area << endl;
}