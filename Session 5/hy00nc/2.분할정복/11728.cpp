#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    vector <int> A(n);
    vector <int> B(m);
    vector <int> C(n+m);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    int a =0;
    int b =0;
    int i=0;
    while(a<n && b<m){
        if(A[a]>=B[b]){
            C[i]=B[b];
            i++; b++;
        }
        else if(A[a]<B[b]){
            C[i]=A[a];
            i++; a++;
        }
    }
    while(b<m){
        C[i]=B[b++];
        i++;
    }
    while(a<n){
        C[i]=A[a++];
        i++;
    }
    for(int i=0;i<n+m;i++){
        cout<<C[i]<<' ';
    }
    cout<<'\n';
}