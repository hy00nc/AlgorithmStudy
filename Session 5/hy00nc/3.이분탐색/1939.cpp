#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <pair<int,int> > a[10001];
int n,m;
bool c[10001];

int start, dest;

bool check(int node, int limit){
    if(c[node]){
        return false;
    }
    c[node] = true;
    if(node == dest){
        return true;
    }
    for(auto &p : a[node]){
        int next = p.first;
        int cost = p.second;
        if(cost>=limit){
            if(check(next,limit)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y,value;
        cin>>x>>y>>value;
        a[x].push_back(make_pair(y,value));
        a[y].push_back(make_pair(x,value));
    }
    cin>>start>>dest;
    int ans = 0;
    int l = 1;
    int r = 1000000000;
    while(l<=r){
        int mid = (l+r)/2;
        memset(c,false, sizeof(c));
        if(check(start, mid)){
            ans = mid;
            l = mid +1;
        }
        else{
            r= mid -1;
        }
    }
    cout<<ans<<'\n';
}