#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> times;
    int temp;
    times.push(0);
    for(int i = 1; i < prices.size(); i++){
        while(!times.empty() and prices[times.top()] > prices[i]){
            temp = times.top();
            answer[temp] = i - temp;
            times.pop();
        }
        times.push(i);
    }

    while (!times.empty()){
        temp = times.top();
        times.pop();
        answer[temp] = prices.size() - 1 - temp;
    }

    return answer;
}

int main(){
    
    vector<int> prices = {1, 2, 3, 2, 3};

    vector<int> answer = solution(prices);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}