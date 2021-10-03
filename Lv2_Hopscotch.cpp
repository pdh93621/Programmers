#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land){
    int temp = 0;
    int N = land.size();
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if (j == k){
                    continue;
                }
                else{
                    if (temp < land[i - 1][k]){
                        temp = land[i - 1][k];
                    }
                }
            }
            land[i][j] += temp;
            temp = 0;
        }
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << land[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return *max_element(land[N - 1].begin(), land[N - 1].end());
}

int main(){
    vector<vector<int>> land = {{1,2,3,5}, {5,6,7,8}, {4,3,2,1}};
    cout << solution(land) << endl;
}