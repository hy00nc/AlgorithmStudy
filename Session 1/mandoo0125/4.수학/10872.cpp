#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int fact=1;
    for(int i=2;i<=n;i++){
        fact=fact*i;
    }
    cout<<fact<<'\n';
}
