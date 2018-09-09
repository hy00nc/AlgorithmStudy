//10799 쇠막대기
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int count(string s){
    stack<int> input;
    int result = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            input.push(i);
        }
        else if(s[i]==')'){
            int x = input.top();
            input.pop();
            if(i-x==1){
                result += input.size();
            }
            else result++;
        }
    }
    return result;

}

int main(){
    string s;
    cin >> s;

    cout << count(s) << '\n';
    

    return 0;
}