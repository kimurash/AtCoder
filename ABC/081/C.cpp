// C - Not so Diverse
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    map<int, int> cntmap;
    rep(i, N){
        int a;
        cin >> a;
        cntmap[a]++;
    }

    vector<int> cntvec;
    for(pair<int, int> p : cntmap){
        cntvec.push_back(p.second);
    }
    sort(all(cntvec));

    if(cntmap.size() > K){
        int sum = 0;
        rep(i, cntmap.size() - K){
            sum += cntvec.at(i);
        }
        cout << sum << endl;
    } else{
        cout << "0" << endl;
    }
}


