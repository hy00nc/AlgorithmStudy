#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum+=gcd(arr[i],arr[j]);
            }
        }
        cout<<sum<<'\n';
    }
}
