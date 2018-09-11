//10828 스택
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> s;
    while(n--){
        string in;
        cin >> in;
        if(in == "push"){
            int x;
            cin >> x;
            s.push(x);
        }
        else if (in == "pop"){
            cout << (s.empty() ? -1 : s.top()) << '\n';
            if(!s.empty()){
                s.pop();
            }

        }
        else if (in == "size"){
            cout << s.size() << '\n';
        }
        else if (in == "empty"){
            cout << s.empty() << '\n';
        }
        else if (in == "top"){
            cout << (s.empty() ? -1 : s.top()) << '\n';
        }
    }
    return 0;
}
