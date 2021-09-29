#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(int i, int j){
    return j < i;
}

vector<bool> primes(int max_num){
    vector<bool> primes(max_num + 1, true);
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i <= max_num; i++){
        if (primes[i]){
            for(int j = 2; j <= max_num / i; j++){
                primes[i * j] = false;
            }
        }
    }
    return primes;
}

int solution(string numbers){
    vector<char> nums;
    vector<int> poss_nums;
    int answer = 0;

    string::iterator iter;
    for(iter = numbers.begin(); iter != numbers.end(); iter++){
        nums.push_back(*iter);
    }

    sort(nums.begin(), nums.end(), compare);

    string max_num;
    for(int i = 0; i < nums.size(); i++){
        max_num.push_back(nums[i]);
    }

    vector<bool> prime;
    prime = primes(stoi(max_num) + 1);

    reverse(nums.begin(), nums.end());

    do {
        string temp = "";

        for(int j = 0; j < nums.size(); j++){
            temp.push_back(nums[j]);
            poss_nums.push_back(stoi(temp));
        }
    } while (next_permutation(nums.begin(), nums.end()));

    sort(poss_nums.begin(), poss_nums.end());
    poss_nums.erase(unique(poss_nums.begin(), poss_nums.end()), poss_nums.end());

    for(int k = 0; k < poss_nums.size(); k++){
        if (prime[poss_nums[k]]){
            answer++;
        }
    }

    return answer;
}

int main(){
    string numbers = "17";
    
    cout << solution(numbers) << endl;

    return 0;
}