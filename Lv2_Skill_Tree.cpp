#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_poss_tree(string skill, string skill_tree){
    int dp[27][27] = {0,};

    for(int i = 1; i <= skill.size(); i++){
        for(int j = 1; j <= skill_tree.size(); j++){
            if (skill[i - 1] == skill_tree[j - 1]){
                if (dp[i - 1][j - 1] != i - 1){
                    return false;
                }
                else{
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return true;
}

int solution(string skill, vector<string> skill_trees){
    int answer = 0;    

    for(int i = 0; i < skill_trees.size(); i++){
        if (is_poss_tree(skill, skill_trees[i])){
            answer++;
        }
    }
    
    return answer;
}

int main(){

    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "BDA"};

    cout << solution(skill, skill_trees) << endl;

    return 0;
}