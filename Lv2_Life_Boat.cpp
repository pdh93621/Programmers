#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit){
    int answer = 0;
    int heavy = people.size() - 1;

    sort(people.begin(), people.end());

    for(int i = 0; i <= heavy; i++){
        while(heavy > i and people[heavy] + people[i] > limit){
            heavy--;
            answer++;
        }
        heavy--;
        answer++;
    }

    return answer;
}

int main(){
    vector<int> people = {30, 30, 30, 30, 30, 30, 30};
    int limit = 100;

    cout << solution(people, limit) << endl;

    return 0;
}