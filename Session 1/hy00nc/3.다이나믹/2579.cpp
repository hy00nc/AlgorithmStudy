#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int score[n];
    for(int i=0;i<n;i++) cin>>score[i];
    int d[n][2];
    d[0][1]=score[0];
    d[0][0]=0;
    d[1][0]=score[1];
    d[1][1]=score[0]+score[1];
    for(int i=2;i<n;i++){
        d[i][0]=max(d[i-2][1],d[i-2][0])+score[i];
        d[i][1]=d[i-1][0]+score[i];
    }
    cout<<max(d[n-1][1],d[n-1][0])<<"\n";
}