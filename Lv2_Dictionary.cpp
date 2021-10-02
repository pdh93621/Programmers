#include <iostream>
#include <string>

using namespace std;

int char2int(char c){
    switch(c){
        case 'A':
        return 0;
        
        case 'E':
        return 1;

        case 'I':
        return 2;
        
        case 'O':
        return 3;

        case 'U':
        return 4;
    }
}

int multiplier(int n){
    if (n == 0){
        return 781;
    }
    return (multiplier(n - 1) - 1) / 5;
}

int solution(string word){
    int answer = 0;


    for(int i = 0; i < word.size(); i++){
        answer += 1 + char2int(word[i]) * multiplier(i);
    }


    return answer;
}

int main(){
    string word = "AAAE";
    cout << solution(word) << endl;
}