// C - Many expressions
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

long enum_formula(const string numlist, int pos);
long calc_formula(const string formula);
vector<string> split(string str, char del);

int main(){
    string numlist;
    cin >> numlist;

    cout << enum_formula(numlist, 1) << endl;
}

long enum_formula(const string numlist, int pos){
    // cout << "enum_formula(" << numlist << ", " << pos << ")" << endl;

    /* ベースケース */
    if(pos >= numlist.size()){
        return(calc_formula(numlist));
        // cout << endl;
    }

    /* 再帰ステップ */
    string clone = numlist;
    long sum = enum_formula(clone.insert(pos, "+"), pos + 2);
    sum += enum_formula(numlist, pos + 1);

    return(sum);
}

long calc_formula(const string formula){
    // cout << "calc_formula(" << formula << ")" << endl;

    long sum = 0;
    vector<string> nums = split(formula, '+');
    for(string num : nums){
        sum += stol(num);
    }
    return(sum);
}

vector<string> split(string str, char del) {
    vector<string> result;

    int pos;
    while((pos = str.find_first_of(del)) != string::npos){
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + 1);
    }
    result.push_back(str);

    return result;
}