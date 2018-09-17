#include <iostream>
#include <vector>
using namespace std;

vector <int> a(100001);
vector <int> visitNum(100001);
vector <int> group(100001);
int ans=0;

void dfs(int start, int vNum, int gnum){
    group[start] =gnum;
    visitNum[start]=vNum;
    int next = a[start];
    if(!visitNum[next]){
        dfs(next,vNum+1,gnum);
    }
    else if(group[next]==group[start]){
        ans-=vNum+1-visitNum[next];
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        //그래프 청소
        a.clear();
        a.resize(100001);
        visitNum.clear();
        visitNum.resize(100001);
        group.clear();
        group.resize(100001);
        //그래프 값 설정
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int num;
            cin>>num;
            a[i]=num;
        }
        ans=n;
        //dfs
        for(int i=1;i<=n;i++){
            if(!visitNum[i]) dfs(i,1,i);
        }
        //정답
        cout<<ans<<'\n';
    }
}