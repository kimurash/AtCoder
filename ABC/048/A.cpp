// A - AtCoder *** Contest
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

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

int main() {
    string S;
    getline(cin, S);

    vector<string> splitted = split(S, ' ');

    char initial = splitted[1].at(0);
    cout << "A" << initial << "C" << endl;
}
