#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int h,w;
    cin>>h>>w;
    if(h==1){
        cout<<1<<'\n';
        return 0;
    }
    if(h==2){
        cout<<min(4,(w+1)/2);
        return 0;
    }
    if(h>=3){
        if(w>=7){
            cout<<w-2<<'\n';
        }
        else if(w<7){
            cout<<min(4,w)<<'\n';
        }
    }
}