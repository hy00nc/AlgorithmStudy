#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int count=0;
    while(n--){
        int a;
        cin>>a;
        bool flag = false;
        if(a==1) flag=true;
        else{
            for(int j=2;j<a;j++){
                 if(a%j==0){
                    flag=true;
                    break;
                    } 
                }
            }
        if(!flag) count++;
    }
    cout<<count<<'\n';
}
