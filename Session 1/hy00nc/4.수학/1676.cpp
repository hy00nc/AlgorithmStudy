#include <iostream>
using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int count=0;
    for (int i = 2; i <= n; i++) {
        int temp = i;
        while(temp%5==0){
                count++;
                temp=temp/5;            
        }
    }
    cout<<count<<'\n';
}