#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int multiplier(int n){
    if (n == 0){
        return 781;
    }
    return (multiplier(n - 1) - 1) / 5;
}

int main(){
    for(int i = 0; i < 5; i++){
        cout << multiplier(i) << endl;
    }
    
    
    return 0;
}