// B - Two Colors Card Game
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int N, M;
    cin >> N;
    vector<string> blue(N);
    rep(i, N){
        cin >> blue.at(i);
    }

    cin >> M;
    vector<string> red(M);
    rep(i, M){
        cin >> red.at(i);
    }

    int max = 0;
    while(blue.size() > 0){
        string target = blue.at(0);
        blue.erase(blue.begin());
        int bcnt = 1;

        int j = 0;
        while(j < blue.size()){
            if(target.compare(blue.at(j)) == 0){
                bcnt++;
                blue.erase(blue.begin() + j);
            } else{
                j++;
            }
        }

        j = 0;
        int rcnt = 0;
        while(j < red.size()){
            if(target.compare(red.at(j)) == 0){
                rcnt++;
                red.erase(red.begin() + j);
            } else{
                j++;
            }
        }

        int result = bcnt - rcnt;
        if(max < result){
            max = result;
        }
    }
    cout << max<< endl;
}