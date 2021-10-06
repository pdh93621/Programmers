#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int divide(string u){
    stack<char> temp;
    temp.push(u[0]);
    for(int i = 1; i < u.size(); i++){
        if(temp.top() == u[i]){
            temp.push(u[i]);
        }
        else{
            temp.pop();
        }
        if(temp.empty()){
            return i;
        }
    }
}

string transform_u(string u){
    string result = "";
    for(int i = 1; i < u.size() - 1; i++){
        if(u[i] == ')'){
            result.push_back('(');
        }
        else{
            result.push_back(')');
        }
    }
    return result;
}

string integrate(string u){
    if(u.empty()){
        return u;
    }

    string new_u;
    string new_v;
    int div_pt = divide(u);

    for(int i = 0; i < u.size(); i++){
        if (i <= div_pt){
            new_u.push_back(u[i]);
        }
        else{
            new_v.push_back(u[i]);
        }
    }
    
    if(new_u[0] == '('){
        return new_u + integrate(new_v);
    }
    else{
        return "(" + integrate(new_v) + ")" + transform_u(new_u);
    }
}

string solution(string p){
    string answer = "";
    answer = integrate(p);
    return answer;
}

int main(){

    string p = "";
    string p1 = "(()())()";
    string p2 = ")(";
    string p3 = "()))()((()";

    //cout << integrate(p1) << endl;
    cout << solution(p3) << endl;
}