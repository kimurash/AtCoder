// C - Together
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;

    int a;
    map<int, int> cntmap;
    rep(i, N){
        cin >> a;

        if(a - 1 >= 0){ cntmap[a - 1]++; }
        cntmap[a]++;
        cntmap[a + 1]++;
    }

    int max = 0;
    for(pair<int, int> p : cntmap){
        if(max < p.second){
            max = p.second;
        }
    }

    cout << max << endl;

}