#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer;
    stack<char> stk;
    
    if (s[0] != '('){
        return false;
    }

    for(int i = 0; i < s.size(); i++){
        if(!stk.empty() and stk.top() == '(' and s[i] == ')'){
            stk.pop();
        }
        else{
            stk.push(s[i]);
        }
    }

    return stk.empty();
}

int main(){

    string s = "(()(";

    cout << (bool)solution(s) << endl;

    return 0;
}