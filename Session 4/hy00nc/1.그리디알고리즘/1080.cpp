#include <iostream>
#include <vector>
using namespace std;

int a[50][50];
int b[50][50];

void flip(int w, int h){
    for(int i=w;i<w+3;i++){
        for(int j=h;j<h+3;j++){
            a[i][j]=1-a[i][j];
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    //행렬 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&b[i][j]);
        }
    }
    //A 뒤집기 
    int cnt=0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(a[i][j]!=b[i][j]){
                flip(i,j);
                cnt++;
            }
        }
    }
    //뒤집은 A와 B가 같은지 확인
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){
                cout<<-1<<'\n';
                return 0;
            }
        }
    }
    cout<<cnt<<'\n';
}
