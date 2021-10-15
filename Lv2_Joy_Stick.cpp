#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int upordown(char s){
    return min(s - 'A', 'Z' - s + 1);
}

int solution(string name) {
    int leng = name.size();
    int temp;
    bool iszero_start = false;
    int zero_start_point;
    int zero_seq_leng = 0;
    int total_UD = 0;
    int total_LR = leng - 1;

    for(int i = 0; i < leng; i++){
        temp = upordown(name[i]);
        total_UD += temp;
        
        if(temp){
            if(iszero_start){
                iszero_start = false;
                total_LR = min(total_LR, 2 * (zero_start_point - 1) + leng - i);
            }
        }
        else{
            if(!iszero_start){
                zero_start_point = i;
                iszero_start = true;
                zero_seq_leng = 1;
            }
            else{
                zero_seq_leng++;
            }
        }
    }

    if(name[leng - 1] == 'A'){
        total_LR = min(total_LR, zero_start_point - 1);
    }

    return total_UD + total_LR;
}

int main(){
    
    string name = "ABBBBBAAAAAAAA";

    cout << solution(name) << endl;

    return 0;
}