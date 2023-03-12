#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int d, n, m;
    cin >> d >> n >> m;

    int branch[n + 1] = {0};
    branch[0] = 0;
    rep(i, n - 1){
        cin >> branch[i + 1];
    }
    branch[n] = d;

    sort(branch, branch + n + 1);

    int dest[m] = {0};
    rep(i, m){
        cin >> dest[i];
    }

    int sum_dist = 0;
    rep(i, m){
        int back = upper_bound(branch, branch + n + 1 ,dest[i]) - branch;
        int front = back - 1;
        
        int diff_back = abs(branch[back] - dest[i]);
        int diff_front = abs(branch[front] - dest[i]);
        
        if(diff_back < diff_front){
            sum_dist += diff_back;
        } else{
            sum_dist += diff_front;
        }
    }

    cout << sum_dist << endl;
}
