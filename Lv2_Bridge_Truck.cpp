#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    queue<int> tw;
    for(int i = 0; i < truck_weights.size(); i++){
        tw.push(truck_weights[i]);
    }

    return answer;
}

int main(){

    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};

    return 0;
}