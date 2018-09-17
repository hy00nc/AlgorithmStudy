#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m,k;
    cin>>n>>m>>k;
    vector <int> a(n);
    vector <int> g;
    if(n>=(m+k-1) && n<=m*k){
        //배열 초기화 부분
        for(int i=0;i<n;i++){
            a[i]=i+1;
        }
        //그룹 나누는 부분
        g.push_back(0);
        g.push_back(k);
        n-=k;
        m-=1;
        int gsize = m ==0 ? 1 : n/m;
        int r = m == 0 ? 0 : n%m;
        for(int i=0;i<m;i++){
            g.push_back(g.back()+gsize+(r>0 ? 1 : 0));
            if(r>0){
                r-=1;
            }
        }
        for(int i=0;i<g.size()-1;i++){
            reverse(a.begin()+g[i], a.begin()+g[i+1]);
        }
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
        return 0;
    }
    else{
        cout<<-1<<'\n';
        return 0;
    }
    
}