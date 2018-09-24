#include <iostream>
#include <algorithm>
using namespace std;

int n,r;
int a[200000];

bool check(int x){
    int cnt =1;
    int last= a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last >= x){
            cnt+=1;
            last = a[i];
        }
    }
    return cnt>=r;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>r;
    long long max =0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(max<a[i]) max = a[i];
    }
    sort(a,a+n);
    int l = 1;
    int r = a[n-1]-a[0];
    int ans = 1;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            if(mid>ans){
                ans = mid;
            }
            l = mid +1;
        }
        else{
            r = mid-1;
        }
    }
    cout<<ans<<'\n';
}