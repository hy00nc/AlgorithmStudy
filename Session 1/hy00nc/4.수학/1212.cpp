#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    int n=s.size();
    int r1,r2,r3;
    bool flag = true;
    for(int i=0;i<n;i++){
        int digit = s[i]-'0';
        r1 = (digit)%2; 
        r2 = (digit/2)%2; 
        r3 = (digit/4)%2; 
        if(flag){
            if(digit==0){
                cout<<"0";
                flag=false;
            }
            else if(digit>1 && digit<4){
                cout<<r2<<r1;
                flag=false;
            }
            else if(digit<=1){
                cout<<r1;
                flag = false;
            }
            else {
                cout<<r3<<r2<<r1;
                flag = false;
                }
        }
        else{
            cout<<r3<<r2<<r1;
            flag = false;
        } 

    }
    cout<<'\n';
}