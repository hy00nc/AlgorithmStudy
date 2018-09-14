#include <iostream>
#include <vector>
using namespace std;

int check[10000000];

int pow(int a, int p){
    int result=1;
    for(int i=0;i<p;i++){
        result*=a;
    }
    return result;
}

int next(int a, int p){
    int result = 0;
    while(a!=0){
        result+=pow(a%10,p);
        a=a/10;
    }
    return result;
}

int length(int a, int p, int cnt){
    if(check[a]!=0) return check[a]-1;
    check[a]=cnt;
    int n = next(a,p);
    return length(n,p,cnt+1);
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a,p;
    cin>>a>>p;
    cout<<length(a,p,1)<<'\n';
}