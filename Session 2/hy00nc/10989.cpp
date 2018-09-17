#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int cnt[10001];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    while(n--){
        int input;
        cin>>input;
        cnt[input]++;
    }
    for(int i=1;i<10001;i++){
        while(cnt[i]>0){
            cout<<i<<'\n';
            cnt[i]--;
        }
    }
}