#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

bool is_same_seq(const vector<int>& a, const vector<int>& b){
    rep(i, a.size()){
        if(a.at(i) != b.at(i)){
            return(false);
        }
    }
    return(true);
}

int main(){
    int N;
    cin >> N;

    int digit;
    vector<int> one_case, P, Q;
    rep(i, N){
        cin >> digit;
        P.emplace_back(digit);

        one_case.emplace_back(i + 1);
    }

    rep(i, N){
        cin >> digit;
        Q.emplace_back(digit);
    }

    int order = 1;
    int porder = 0, qorder = 0;
    do{
        if(!porder){
            if(is_same_seq(one_case, P)){
                porder = order;
            }
        }

        if(!qorder){
            if(is_same_seq(one_case, Q)){
                qorder = order;
            }
        }
        
        if(porder != 0 && qorder != 0){
            break;
        }

        order++;
    } while(next_permutation(all(one_case)));

    cout << abs(porder - qorder) << endl;
}