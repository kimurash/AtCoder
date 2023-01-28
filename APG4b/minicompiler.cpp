#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

struct Compiler{
    map<string, int> int_table;
    map<string, vector<int>> vec_table;
    
    void compile_int_dec(queue<string> &split){
        string name = split.front();
        split.pop();
        split.pop();

        int value = compile_int_exp(split);

        // cout << name << " => " << value << endl;
        int_table[name] = value;
    }

    int compile_int_exp(queue<string> &split){
        string term = split.front();
        split.pop();
        int sum = compile_int_term(term);

        while(split.front() != ";"){
            string op = split.front();
            split.pop();

            term = split.front();
            int operand = compile_int_term(term);
            split.pop();

            if(op == "+"){
                sum += operand;
            } else if(op == "-"){
                sum -= operand;
            }
        }
        split.pop();
        return(sum);
    }

    int compile_int_term(string term){
        // 数字か判定
        if(all_of(term.cbegin(), term.cend(), 
                [](char c){ return isdigit(c) != 0; })){
            return(stoi(term));
        } else{
            return(int_table.at(term));
        }
    }

    void compile_print_int(queue<string> &split){
        cout << compile_int_exp(split) << endl;
    }

    void compile_vec_dec(queue<string> split){
        string name = split.front();
        split.pop();
        split.pop();

        vector<int> result = compile_vec_exp(split);

        vec_table[name] = result;
        /* cout << name << " => [ ";
        rep(i, result.size()){
            cout << result.at(i) << " ";
        }
        cout << "]" << endl; */
    }

    vector<int> compile_vec_exp(queue<string> &split){
        // cout << "compile_vec_exp" << endl;

        vector<int> result = compile_vec_term(split);
        while(split.front() != ";"){
            string op = split.front();
            split.pop();

            vector<int> temp = compile_vec_term(split);

            if(op == "+"){
                rep(i, result.size()){
                    result.at(i) += temp.at(i);
                }
            } else if(op == "-"){
                rep(i, result.size()){
                    result.at(i) -= temp.at(i);
                }
            }
        }
        split.pop();
        return(result);
    }

    vector<int> compile_vec_term(queue<string> &split){
        string symbol = split.front();
        split.pop();
        if(symbol == "["){
            vector<int> temp;
            while(split.front() != "]"){
                string elem = split.front();
                if(elem != ","){
                    temp.push_back(compile_int_term(elem));
                }
                split.pop();
            }
            split.pop();
            return(temp);
        } else{
            return(vec_table.at(symbol));
        }
    }

    void compile_print_vec(queue<string> &split){
        vector<int> result = compile_vec_exp(split);
        cout << "[ ";
        rep(i, result.size()){
            cout << result.at(i) << " ";
        }
        cout << "]" << endl;
    }
};

int main(){
    int N;
    cin >> N;
    cin.ignore();

    Compiler compiler;
    string input, str;
    queue<string> split;
    rep(i, N){
        while(!split.empty()){
            split.pop();
        }

        getline(cin, input);
        stringstream ss(input);

        // 空白で分割
        // cout << "[";
        while(getline(ss, str, ' ')){
            split.push(str);
            // cout << str << ", ";
        }
        // cout << "]" << endl;

        // 命令によって場合分け
        string inst = split.front();
        split.pop();
        if(inst == "int"){
            compiler.compile_int_dec(split);
        } else if(inst == "print_int"){
            compiler.compile_print_int(split);
        } else if(inst == "vec"){
            compiler.compile_vec_dec(split);
        } else if(inst == "print_vec"){
            compiler.compile_print_vec(split);
        }
    }
}
