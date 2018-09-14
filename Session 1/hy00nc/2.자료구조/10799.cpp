#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    string input;
    cin>>input;
    int count=0;
    int n=0;
    for(int i=0;i<input.size();i++){
        if(input[i]=='(') n++;
        else{
            if(input[i-1]==')'){
                count++;
                n--;
                }
            else{
            n--;
            count+=n;
            }
        }
    }
    cout<<count<<"\n";
}