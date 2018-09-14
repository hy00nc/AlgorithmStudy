#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    } 
    int d[n+1][3];
    d[0][0]=d[0][1]=d[0][2]=0;
    for(int i=1;i<=n;i++){
        d[i][0]=max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
        d[i][1]=d[i-1][0]+arr[i];
        d[i][2]=d[i-1][1]+arr[i];
    }
    int ans=max(d[n][1],max(d[n][0],d[n][2]));
    cout<<ans;
}