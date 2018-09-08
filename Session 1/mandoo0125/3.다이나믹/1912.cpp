#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    int d[n];
    d[0]=A[0];
    for(int i=1;i<n;i++){
        d[i]=max(d[i-1]+A[i],A[i]);
    }

 // int max=0; 띠용
    int max=d[0];
    for(int i=1;i<n;i++){
        if(max<d[i]) max=d[i];
    }
    cout<<max<<"\n";
}