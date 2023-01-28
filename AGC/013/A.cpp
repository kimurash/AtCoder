// A - Sorted Arrays
#include <bits/stdc++.h>

#define ASC true
#define DESC false

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t N;
    cin >> N;

    vector<int64_t> vec(N);
    rep(i, N){
        cin >> vec.at(i);
    }

    bool mode = ASC;
    int count = 0;
    vector<int64_t> temp;
    for(int i = 0; i < vec.size(); ){
        int j = i;
        // 単調非増加 or 単調非減少
        while(j < vec.size()){
            if(vec.at(i) < vec.at(j)){
                mode = ASC;
                break;
            } else if(vec.at(i) > vec.at(j)){
                mode = DESC;
                break;
            } else{
                j++;
            }
        }

        temp.clear();
        temp.push_back(vec.at(i));

        int k = i + 1;
        while(k < vec.size()){
            if(mode){ // ASC
                if(vec.at(k - 1) <= vec.at(k)){
                    temp.push_back(vec.at(k));
                } else{
                    break;
                }
            } else{ // DESC
                if(vec.at(k - 1) >= vec.at(k)){
                    temp.push_back(vec.at(k));
                } else{
                    break;
                }
            }
            k++;
        }
        i += temp.size();
        count++;
    }

    cout << count << endl;
}