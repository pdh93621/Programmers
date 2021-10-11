#include <iostream>

using namespace std;

int solution(int n, int a, int b){
    int answer = 0;

    while(a != b){
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        cout << a << " " << b << endl;
        answer++;
    }

    return answer;
}

int main(){
    int n = 8;
    int a = 4;
    int b = 7;

    cout << solution(n, a, b) << endl;
    return 0;
}