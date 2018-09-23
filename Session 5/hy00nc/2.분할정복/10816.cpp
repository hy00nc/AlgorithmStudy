#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int m; cin>>m;
    for(int i=0;i<m;i++){
        int num; cin>>num;
        auto e = equal_range(a.begin(),a.end(),num);
        cout<<(e.second-e.first)<<' ';
    }
}