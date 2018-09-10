#include <iostream>
using namespace std;

#define MAX 1000001
bool check[MAX];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    check[0]=check[1]=true; //0 과 1은 소수가 아니다.
    for(int i=2;i<=MAX;i++){
        if(check[i]==false){
            for(int j=i+i;j<=MAX;j+=i){
                check[j]=true;
            }
        }
    }
    
    while(true){
        int n;
        cin>>n;
        if(n==0) return 0;
        for(int i=3;i<=n;i++){
            if(check[i]==false && check[n-i]==false){
                    cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
                    break;
            }
        }
    }
}