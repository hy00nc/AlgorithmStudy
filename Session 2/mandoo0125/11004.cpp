#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[5000001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+k);
    cout<<arr[k-1]<<'\n';
}