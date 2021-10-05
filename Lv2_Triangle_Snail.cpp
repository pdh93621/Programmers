#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n);
    int start_row = -1;
    int start_col = 0;
    int stage = 0;
    int current_num = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            snail[i].push_back(0);
        }
    }

    for(int i = n; i > 0; i--){
        for(int j = 0; j < i; j++){
            if (stage % 3 == 0){
                start_row++;
            }
            else if (stage % 3 == 1){
                start_col++;
            }
            else{
                start_row--;
                start_col--;
            }
            //cout << start_row << start_col << endl;
            snail[start_row][start_col] = current_num;
            current_num++;
        }
        stage++;
    }

    for(int k = 0; k < n; k++){
        for(int l = 0; l <= k; l++){
            answer.push_back(snail[k][l]);
            // cout << snail[k][l] << " ";
        }
        // cout << endl;
    }

    return answer;
}

int main(){
    int n = 6;
    vector<int> answer = solution(n);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}