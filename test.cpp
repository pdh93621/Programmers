#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> k;
    k.push(1);
    cout << !k.empty() << endl;

    return 0;
}