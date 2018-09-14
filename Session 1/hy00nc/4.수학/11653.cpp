#include <iostream>
using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    int div=2;
    while(n!=1){
        if(n%div==0){
            cout<<div<<'\n';
            n=n/div;
        } 
        else div++;
    }
}