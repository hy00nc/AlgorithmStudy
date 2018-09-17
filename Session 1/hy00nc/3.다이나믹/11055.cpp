#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    int d[n];
    for(int i=0;i<n;i++){
        d[i]=A[i];
        for(int j=0;j<i;j++){
            if(A[i]>A[j]&&d[i]<d[j]+A[i]) d[i]=d[j]+A[i];
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max<d[i]) max=d[i];
    }
    cout<<max<<"\n";
}
