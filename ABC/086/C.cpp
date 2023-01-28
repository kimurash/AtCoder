#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> t(2, 0);
    vector<int> x(2, 0);
    vector<int> y(2, 0);

    bool parity; // true: even  false: odd
    int crrnt, next;
    int dt, dist;

    rep(i, N){
        if(i % 2 == 0){
            crrnt = 0;
            next = 1;
        } else{
            crrnt = 1;
            next = 0;
        }

        cin >> t.at(next) >> x.at(next) >> y.at(next);
        dt = t.at(next) - t.at(crrnt);
        dist = abs(x.at(next) - x.at(crrnt)) + abs(y.at(next) - y.at(crrnt));

        // cout << "dt:" << dt << endl;
        // cout << "dist:" << dist << endl;

        if(dt < dist){
            cout << "No" << endl;
            exit(0);
        } else{
            if(dt % 2 == 0){ // even
                parity = true;
            } else{ // odd
                parity = false;
            }
            
            if(dist % 2 == 0){ // even
                if(!parity){
                    cout << "No" << endl;
                    exit(0);
                }
            } else{ // odd
                if(parity){
                    cout << "No" << endl;
                    exit(0);
                }
            }
        }

        t.at(crrnt) = t.at(next);
        x.at(crrnt) = x.at(next);
        y.at(crrnt) = y.at(next);
    }

    cout << "Yes" << endl;
}