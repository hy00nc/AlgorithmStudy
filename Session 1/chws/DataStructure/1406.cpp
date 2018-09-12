//1406 에디터
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string input;
    cin >> input;
    int t;
    cin >> t;

    stack<char> left;
    stack<char> right;
    int size = input.size();
    for(int i=0; i<size; i++){
        left.push(input[i]);
    }


    while(t--){
        char cmd;
        cin >> cmd;
        if(cmd == 'L' && !left.empty()){
            right.push(left.top());
            left.pop();
        }else if(cmd == 'D' && !right.empty()){
            left.push(right.top());
            right.pop();
        }else if(cmd == 'B' && !left.empty()){
            left.pop();
        }else if(cmd == 'P'){
            char n;
            cin >> n;
            left.push(n);
        }
    }
    
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    cout << '\n';
}