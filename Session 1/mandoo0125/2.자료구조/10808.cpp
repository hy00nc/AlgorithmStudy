#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    string input;
    cin>>input;
    int count[26]={0,};
    for(int i=0;i<input.size();i++){
        count[input[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cout<<count[i]<<" ";
    }
}