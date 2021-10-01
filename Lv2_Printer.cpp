#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location){
    int answer = 0;
    int temp_max = 0;
    int temp_num;
    int num = 101;
    queue<int> temp_que;
    queue<int> current;

    for(int i = 0; i < priorities.size(); i++){
        current.push(i);
    }
    
    while(num != location){
        while(!current.empty()){
            temp_num = current.front();
            current.pop();
            if (temp_max < priorities[temp_num]){
                while(!temp_que.empty()){
                    current.push(temp_que.front());
                    temp_que.pop();
                }
                temp_max = priorities[temp_num];
            }
            temp_que.push(temp_num);
        }        
        num = temp_que.front();
        //cout << num << endl;
        temp_que.pop();
        while(!temp_que.empty()){
            current.push(temp_que.front());
            temp_que.pop();
        }
        answer += 1;
        temp_max = 0;
    }
    
    return answer;
}

int main(){
    vector<int> priorities = {1,2,8,3,4};
    int location = 4;

    cout << solution(priorities, location) << endl;
    return 0;
}