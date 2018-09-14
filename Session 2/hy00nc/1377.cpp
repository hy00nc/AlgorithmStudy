#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector <pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int gap = a[i].second-i;
        if(ans<gap) ans=gap;
    }
    cout<<ans+1<<'\n';
}