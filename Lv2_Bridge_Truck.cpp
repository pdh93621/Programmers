#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int truck_num = 0;
    int now_weight = truck_weights[0];
    queue<int> now_bridge;

    now_bridge.push(101);
    
    while(truck_num < truck_weights.size() and now_bridge.empty()){
        if(answer == now_bridge.front()){
            now_bridge.pop();
        }
        answer += 1;
    }

    return answer;
}

int main(){

    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};

    return 0;
}