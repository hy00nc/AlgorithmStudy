#include <iostream>
using namespace std;

long long a[1000000];
int n, m;

bool check(long long x){
    long long cnt=0;
    for(int i=0;i<n;i++){
        long long gap = a[i]-x;
        if(gap>=0){
            cnt+=gap;
        }
    }
    if(cnt<m){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    long long max=0;
    for(int i=0;i<n;i++){
        long long temp;
        cin>>temp;
        if(temp>max) max = temp;
        a[i]=temp;
    }

    long long ans = 0;
    long long l = 0;
    long long r = max;
    while(l<=r){
        long long mid = (l+r)/2;
        if(check(mid)){
            if(ans<mid){
                ans = mid;
            }
            l = mid+1;
        }
        else{
            r = mid -1;
        }
    }
    cout<<ans<<'\n';
}