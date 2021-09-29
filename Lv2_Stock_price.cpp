#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

// int time_diff(vector<int> prices, int i){
//     for(int j = i + 1; j < prices.size(); j++){
//         if (prices[i] > prices[j]) {
//             return j - i;
//         }
//     }
//     return prices.size() - i - 1;
// }

// vector<int> solution(vector<int> prices) {
//     vector<int> answer;
    
//     for(int i = 0; i < prices.size(); i++){
//         answer.push_back(time_diff(prices, i));
//     }
//     return answer;
// }

vector<int> solution(vector<int> prices) {
    vector<int> answer = {0};
    stack<pair<int, int>> times;
    pair<int, int> temp;

    times.push(make_pair(prices.back(), 0));
    // cout << times.top().first << endl;

    for(int i = prices.size() - 2; i >= 0; i--){
        temp = make_pair(prices[i], 1);
        // cout << i << endl;
        while (prices[i] <= times.top().first and !times.empty()) {
            // cout << times.top().first << endl;
            temp.second += times.top().second;
            times.pop();
        }
        times.push(temp);
        //cout << temp.first << " " << temp.second << endl;
        answer.push_back(temp.second);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main(){
    
    vector<int> prices = {1, 2, 3};

    vector<int> answer = solution(prices);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}