#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    for(int i = 0; i < a.size(); i++){
        answer += a[i]*b[i];
    }
    
    return answer;
}

int main(){
    vector<int> a = {1,1,1,1};
    vector<int> b = {2,1,0,3};

    cout << solution(a, b) << endl;

    return 0;
}