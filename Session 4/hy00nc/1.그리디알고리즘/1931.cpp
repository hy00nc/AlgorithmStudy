#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting{
    int start;
    int end;
    Meeting(int start, int end): start(start), end(end){}
};

bool cmp(const struct Meeting &a, const struct Meeting &b){
    if(a.end==b.end) return a.start<b.start;
    else return a.end<b.end;
}

vector <Meeting> a;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        a.push_back(Meeting(s,e));
    }
    
    sort(a.begin(),a.end(),cmp);
    int now=0;
    int ans=0;
    for(int i=0;i<a.size();i++){
        if(now<=a[i].start){
            now = a[i].end;
            ans++;
        }
    }
    cout<<ans<<'\n';
}