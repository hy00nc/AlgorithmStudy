#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    int d1[n];
    int d2[n];
    for(int i=0;i<n;i++){
        d1[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j]&&d1[i]<d1[j]+1) d1[i]=d1[j]+1;
        }
    }
    for(int i=n-1;i>=0;i--){
        d2[i]=1;
        for(int j=i;j<n;j++){
            if(A[i]>A[j]&&d2[i]<d2[j]+1) d2[i]=d2[j]+1;
        }
    }

    int max=0;
    for(int i=0;i<n;i++){
        if(max<d1[i]+d2[i]-1) max=d1[i]+d2[i]-1;
    }
    cout<<max<<"\n";
}
