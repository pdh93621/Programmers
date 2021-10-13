#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int first_term(int n){
    int s = 0;
    for(int i = 1; i < n; i++){
        s += 21 - abs(21 - 2 * i);
    }
    return s;
}

int second_term(int x, int y, int nx, int ny){
    int s1 = x + y;
    int s2 = nx + ny;

    if(s1 > 10){
        y -= s1 - 10;
    }

    if(s2 > 10){
        ny -= s2 - 10;
    }

    return 1 + y + ny;
}

int solution(string dirs) {
    int answer = 0;
    bool visited[221] = {0,};

    char directions[4] = {'U', 'D', 'R', 'L'};
    int xdir[4] = {-1, 1, 0, 0};
    int ydir[4] = {0, 0, 1, -1};

    int x = 5;
    int y = 5;
    int nx;
    int ny;
    int current_root;
    
    string::iterator iter;
    for(iter = dirs.begin(); iter != dirs.end(); iter++){
        for(int i = 0; i < 4; i++){
            if (*iter == directions[i]){
                nx = x + xdir[i];
                ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < 11 and ny < 11){
                    current_root = first_term(max(x+y, nx+ny)) + second_term(x, y, nx, ny);
                    if(!visited[current_root]){
                        answer++;
                        visited[current_root] = true;
                    }
                    x = nx;
                    y = ny;
                }

                break;
            }
        }
    }
        
    return answer;
}

int main(){

    string dirs = "ULURRDLLU";

    cout << solution(dirs) << endl;

    return 0;
}