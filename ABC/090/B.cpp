// B - Palindromic Number
#include <bits/stdc++.h>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int sum = 0;
    for (int i = A; i <= B; i++){
        int temp = i;
        string comp = "";
        while(temp > 0){
            comp.append(to_string(temp % 10));
            temp /= 10;
        }
        // cout << i << "==" << comp << endl;

        if(to_string(i) == comp){
            sum++;
        }
    }

    cout << sum << endl;
}
