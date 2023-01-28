// A - Mr.Takahashi and meat
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

/* greedy method */

int main(){
    int N;
    cin >> N;

    vector<int> time(N);
    rep(i, N){
        cin >> time.at(i);
    }
    sort(time.begin(), time.end(),  greater<int>());

    int sumA = 0;
    int sumB = 0;
    rep(i, time.size()){
        if(sumA < sumB){
            sumA += time.at(i);
        } else{
            sumB += time.at(i);
        }
    }

    cout << max(sumA, sumB) << endl;
}