#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    while(n--){
        string cmd;
        cin>>cmd;
        if(cmd=="push"){
            int input;
            cin>>input;
            s.push(input);
        }
        else if(cmd=="pop"){
            if(s.empty()) cout<<"-1"<<"\n";
            else{
                int temp=s.top();
                cout<<temp<<"\n";
                s.pop();
            } 
        }
        else if(cmd=="size"){
            cout<<s.size()<<"\n";
        }
        else if(cmd=="empty"){
            if(s.empty()) cout<<"1"<<"\n";
            else cout<<"0"<<"\n";
        }
        else if(cmd=="top"){
            if(s.empty()) cout<<"-1"<<"\n";
            else cout<<s.top()<<"\n";
        }
    }
    
 }