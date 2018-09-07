#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int n=0;
        string input;
        cin>>input;
        bool flag=true;
        for(int i=0;i<input.size();i++){
            if(input[i]=='(') n++;
            else n--;

            if(n<0) {
                flag=false;
                break;
                }
        }
        if(n>0) flag=false;
        if(flag==true) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}