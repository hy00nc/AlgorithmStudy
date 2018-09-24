#include <iostream>
using namespace std;

int p,n;
int a[10001];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>p>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(p<=n){
        cout<<p<<'\n';
        return 0;
    }
    long long l=0;
    long long r = 2000000000LL * 10000LL;
    while(l<=r){
        long long mid = (l+r)/2;
        long long start=0;
        long long end = n;
        for(int i=1;i<=n;i++){
            end+=mid/a[i];
        }
        start = end;
        for(int i=1;i<=n;i++){
            if(mid % a[i] == 0){
                start -=1;
            }
        }
        start+=1;
        if(p<start){
            r = mid -1;
        }
        else if(p>end){
            l= mid+1;
        }
        else{
            for(int i=1;i<=n;i++){
                if(mid%a[i]==0){
                    if(p==start){
                        cout<<i<<'\n';
                        return 0;
                    }
                    start+=1;
                }
            }
        }
    }
}