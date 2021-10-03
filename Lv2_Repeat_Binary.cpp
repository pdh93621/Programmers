#include <string>
#include <vector>
#include <iostream>

using namespace std;

string int2bin(int n){
    string bin = "";
    
    while(n){
        bin = to_string(n % 2) + bin;
        n /= 2;
    }
    
    return bin;
}

string transformer(string s, int* num_zero){
    int num_one = 0;
    string::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        if(*iter == '0'){
            (*num_zero)++;
        }
        else{
            num_one++;
        }
    }
    return int2bin(num_one);
}

vector<int> solution(string s) {
    vector<int> answer;
    int num_zero = 0;
    int num_trans = 0;

    while(s != "1"){
        s = transformer(s, &num_zero);
        num_trans++;
    }

    answer = {num_trans, num_zero};

    return answer;
}

int main(){

    string s = "110010101001";
    vector<int> sol = solution(s);

    cout << sol[0] << sol[1] << endl;

    return 0;
}