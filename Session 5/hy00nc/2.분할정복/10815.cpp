#include <iostream>
#include <algorithm>
using namespace std;

int a[500000];
int b[500000];


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m; cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    
    bool flag;
    for(int i=0;i<m;i++){
        flag = false;
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(a[mid] == b[i]){
                flag = true;
                break;
            }
            else if(a[mid]>b[i]){
                right = mid -1;
            }
            else if(a[mid]<b[i]){
                left = mid +1;
            }
        }
        if(flag) cout<<1<<" ";
        else cout<<0<<" ";
    }
}
