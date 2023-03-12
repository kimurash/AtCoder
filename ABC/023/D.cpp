#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long> H(N), S(N);
    long max_limit = 0;
    rep(i, 0, N){
        cin >> H.at(i) >> S.at(i);
        long limit = H.at(i) + S.at(i) * N;
        max_limit = max_limit < limit ? limit : max_limit;
    }

    long low = 0, middle, high = max_limit;
    while(low < high){
        middle = (low + high) / 2;
        // printf("%ld %ld %ld\n", low, middle, high);

        bool can_be_shot = true;
        vector<long> time_limit(N);

        // 制限時間の設定
        rep(i, 0, N){
            if(middle < H.at(i)){
                can_be_shot = false;
                break;
            }
            time_limit.at(i) = (middle - H.at(i)) / S.at(i);
        }

        if(!can_be_shot){
            low = middle + 1;
            continue;
        }

        sort(all(time_limit));

        // 全ての風船を制限時間内に割れるか確認
        rep(i, 0, N){
            if(time_limit.at(i) < i){
                can_be_shot = false;
                break;
            }
        }

        if(can_be_shot){
            high = middle;
        } else{
            low = middle + 1;
        }
    }

    cout << high << endl;
}