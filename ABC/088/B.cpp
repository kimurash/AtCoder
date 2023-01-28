// B - Card Game for Two
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;

    vector< pair< pair<string, int>, int>> rest(N);
    string city;
    int score;
    rep(i, N){
        cin >> city >> score;
        rest.at(i) = make_pair(make_pair(city, -score), i + 1);
    }

    sort(rest.begin(), rest.end());
    
    int id;
    rep(i, N){
        tie(ignore, id) = rest.at(i);
        cout << id << endl;
    }
}