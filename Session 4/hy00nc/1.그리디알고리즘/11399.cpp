#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> p;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p.push_back(x);
    }
    sort(p.begin(),p.end());
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+=p[i];
        ans+=sum;
    }
    cout<<ans<<'\n';
}