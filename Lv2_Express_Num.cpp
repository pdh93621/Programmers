#include <iostream>

using namespace std;

bool is_true(int n, int start){
    while (start <= n){
        n -= start;
        start++;
    }
    return (bool)n;
}

int solution(int n){
    int answer = 0;

    for(int i = 1; i <= n/2; i++){
        if (! is_true(n, i)){
            answer++;
        }
    }

    return answer + 1;
}

int main(){
    cout << solution(15) << endl;
    return 0;
}