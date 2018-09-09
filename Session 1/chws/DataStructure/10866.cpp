//10866 덱(Deque)
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    deque<int> q;
    while(n--){
        cin >> s;
        if(s == "push_front"){
            int x;
            cin >> x;
            q.push_front(x);   
        }else if(s == "push_back"){
            int x;
            cin >> x;
            q.push_back(x);
        }else if(s == "pop_front"){
            cout << (q.empty()? -1: q.front()) << "\n";
            if(!q.empty()){
                q.pop_front();
            }
        }else if(s == "pop_back"){
            cout << (q.empty()? -1: q.back()) << "\n";
            if(!q.empty()){
                q.pop_back();
            }
        }else if(s == "size"){
            cout << q.size() << "\n";
        }else if(s == "empty"){
            cout << (q.empty()? 1: 0) << "\n";
        }else if(s == "front"){
            cout << (q.empty()? -1: q.front()) << "\n";
        }else if(s == "back"){
            cout << (q.empty()? -1: q.back()) << "\n";
        }
    
    }
    return 0;

}