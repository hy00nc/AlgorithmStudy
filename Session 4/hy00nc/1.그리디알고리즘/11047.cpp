#include <iostream>
using namespace std;

int a[10];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    for(int i=n-1;i>=0;i--){
        count+=k/a[i];
        k=k%a[i];
    }
    cout<<count<<'\n';
}