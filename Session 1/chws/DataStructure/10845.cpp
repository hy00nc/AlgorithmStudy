//10845 큐
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    queue<int> q;
    while(t--){
        string s;
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            q.push(x);
        }else if(s == "pop"){
            cout << (q.empty()? -1: q.front()) << '\n';
            if(!q.empty())
                q.pop();
        }else if(s == "size"){
            cout << q.size() << '\n';
        }else if(s == "empty"){
            cout << (q.empty()? 1: 0) << '\n';
        }else if(s == "front"){
            cout << (q.empty()? -1: q.front()) << '\n';
        }else if(s == "back"){
            cout << (q.empty()? -1: q.back()) << '\n';
        }

    }


    return 0;
}