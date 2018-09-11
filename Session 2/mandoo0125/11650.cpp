#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector <pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        cout<<a[i].first<<" "<<a[i].second<<'\n';
    }
}