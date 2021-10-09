#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int xdir[4] = {0, 0, 1, -1};
int ydir[4] = {1, -1, 0, 0};

int solution(vector<vector<int>> maps){
    int answer;
    int nx;
    int ny;
    int N = maps.size();
    int M = maps[0].size();

    queue<pair<int, int>> q;

    pair<int, int> temp = make_pair(0, 0);

    q.push(temp);

    while(!q.empty()){
        temp.first = q.front().first;
        temp.second = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
           nx = xdir[i] + temp.first;
           ny = ydir[i] + temp.second;
           if (nx >= 0 and nx < N and ny >= 0 and ny < M and maps[nx][ny] == 1){
               q.push(make_pair(nx, ny));
               maps[nx][ny] = maps[temp.first][temp.second] + 1;
           }
        }
    }

    answer = maps[N - 1][M - 1];
    if (answer == 1){
        return -1;
    }

    return answer;
}

int main(){
    vector<vector<int>> maps = {{1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,0}, {0,0,0,0,1}};

    cout << solution(maps) << endl;

    return 0;
}