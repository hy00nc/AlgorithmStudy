#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n=20;
    int m;
    cin>>m;
    int s = 0;
    for(int i=0;i<m;i++){
        string input;
        cin>>input;
        int x;
        if(input=="add"){
            cin>>x; x--;
            s = (s | (1<<x));
        }
        else if(input=="remove"){
            cin>>x; x--;
            s = (s & ~(1<<x));
        }
        else if(input=="check"){
            cin>>x; x--;
            if(s & (1<<x)){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else if(input=="toggle"){
            cin>>x; x--;
            s = (s ^ (1<<x));
        }
        else if(input=="all"){
            s = (1<<n) -1;
        }
        else if(input=="empty"){
            s = 0;
        }
    }
}