#include <string>
#include <iostream>
#include <vector>

using namespace std;

string make_binary(int n){
    string binary = "";
    int remainder;
    while (n){
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    return binary;
}

int count_one(string binary){
    int num_one = 0;

    string::iterator iter;
    for(iter = binary.begin(); iter != binary.end(); iter++){
        if (*iter == '1') {
            // cout << *iter << endl;
            num_one++;
        }
    }
    return num_one;
}

int solution(int n){
    
    int num_one = count_one(make_binary(n));
    
    int temp = 0;

    while (temp != num_one){
        temp = count_one(make_binary(++n));
    }

    return n;
}

int main(){
    
    cout << solution(15) << endl;

    return 0;
}