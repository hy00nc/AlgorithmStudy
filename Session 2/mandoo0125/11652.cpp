#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector <long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int cnt=1;
    long long ans=a[0];
    int num=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            cnt=1;
        }
        else cnt++;
        if(num<cnt){
            num=cnt;
            ans=a[i];
        }
    }
    cout<<ans<<'\n';
}