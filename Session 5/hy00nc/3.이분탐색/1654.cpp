#include <iostream>
#include <vector>
using namespace std;

long long a[10000];
int k, n;

bool check(long long x){
    int cnt=0;
    for(int i=0;i<k;i++){
        cnt+=a[i]/x;
    }
    if(cnt<n){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>k>>n;
    long long max=0;
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        if(temp>max) max = temp;
        a[i]=temp;
    }

    long long ans = 0;
    long long l = 1;
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