#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int row;
    int column;
    for(long long i = left; i <= right; i++){
        answer.push_back(max(i / n, i % n) + 1);
    }

    return answer;
}

int main(){

    int n = 3;
    long long left = 2;
    long long right = 5;

    vector<int> result = solution(n, left, right);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}