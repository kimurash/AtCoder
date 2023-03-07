#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

struct City{
    int x;
    int y;
};

// 町間の距離を計算する関数
double calc_dist(City a, City b){
    return(sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0)));
}

int main(){
    int N;
    cin >> N;

    int x, y;
    vector<City> cities;
    vector<int> one_case;
    rep(i, N){
        cin >> x >> y;
        City city = {x, y};
        cities.emplace_back(city);

        one_case.emplace_back(i);
    }

    double sum_dist = 0.0;
    int n_case = 0;

    do{
        double dist = 0.0;
        rep2(i, 1, N){
            dist += calc_dist(cities.at(one_case[i-1]), cities.at(one_case[i]));
        }
        sum_dist += dist;
        n_case++;
    } while(next_permutation(all(one_case)));

    cout << setprecision(20) << sum_dist / n_case << endl;
}