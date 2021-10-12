#include <iostream>
#include <string>

using namespace std;

int solution(string dirs) {
    int answer = 1;
    bool matrix[11][11] = {0,};
    
    char pdir[4] = {'U', 'D', 'R', 'L'};
    int rdirs[4] = {-1, 1, 0, 0};
    int cdirs[4] = {0, 0, 1, -1};

    int x = 5;
    int y = 5;

    int nx = 5;
    int ny = 5;

    matrix[5][5] = true;

    string::iterator iter;
    for(iter = dirs.begin(); iter != dirs.end(); iter++){
        for(int i = 0; i < 4; i++){
            if (*iter == pdir[i]){
                nx += rdirs[i];
                ny += cdirs[i];
                if (nx >= 0 and nx < 11 and ny >= 0 and ny < 11){
                    x = nx;
                    y = ny;
                    if(!matrix[nx][ny]){
                        answer++;
                        matrix[nx][ny] = true;
                    }
                    break;
                }
            }
        }
    }
    
    return answer;
}

int main(){

    string dirs = "LULLLLLLU";

    cout << solution(dirs) << endl;

    return 0;
}