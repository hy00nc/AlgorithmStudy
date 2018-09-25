#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=1;i<=n;i++){
        a[i-1] = i;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    while(next_permutation(a.begin(),a.end())){
        for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}