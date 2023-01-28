// C - Train Ticket
#include <bits/stdc++.h>

#define MAX 4
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool divide_cases(vector<int> abcd, string output, int value, int depth){
    /* ベースケース */
    if(depth >= MAX){
        if(value == 7){
            cout << output << "=7" << endl;
            return(true);
        } else{
            return(false);
        }
    }

    /* 再帰ステップ */
    if(divide_cases(abcd, output + "+" + to_string(abcd.at(depth)), 
            value + abcd.at(depth), depth + 1)){
        return(true);
    } else if(divide_cases(abcd, output + "-" + to_string(abcd.at(depth)), 
            value - abcd.at(depth), depth + 1)){
        return(true);
    } else{
        return(false);
    }
}

int main(){
    string input;
    cin >> input;

    vector<int> abcd(MAX);
    rep(i, input.size()){
        abcd.at(i) = (int) input.at(i) - '0';
    }

    divide_cases(abcd, to_string(abcd.at(0)), abcd.at(0), 1);
}