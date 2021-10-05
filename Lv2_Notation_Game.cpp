#include <string>
#include <vector>
#include <iostream>

using namespace std;

string change_notation(int n){
    if (n < 10){
        return to_string(n);
    }
    else{
        string s;
        s.push_back((char)('A' + (n - 10)));
        return s;
    }
}

string convert_num(int target, int notation){
    if (target == 0){
        return "0";
    }

    string result = "";

    while(target){
        result = change_notation(target % notation) + result;
        target /= notation;
    }

    return result;
}

string solution(int n, int t, int m, int p) {
    p = p % m;
    string answer = "";
    int current_num = 0;
    string converted_num;
    int current_order = 1;

    while(1){
        converted_num = convert_num(current_num, n);
        for(int i = 0; i < converted_num.size(); i++){
            if (answer.size() == t){
                return answer;
            }
            if (current_order % m == p){
                answer += converted_num[i];            
            }
            current_order++;
        }
        current_num++;
    }

    return answer;
}

int main(){
    int n = 16, t = 16, m = 2, p = 2;
    cout << solution(n, t, m, p) << endl;
    return 0;
}