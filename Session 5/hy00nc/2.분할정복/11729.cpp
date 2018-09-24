#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt;

void hanoi(int from, int to, int num){
    if(num==0) return;
    hanoi(from,6-from-to,num-1);
    cout<<from<<" "<<to<<'\n';
    hanoi(6-from-to,to,num-1);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    cout<<(1<<n)-1<<'\n';
    hanoi(1,3,n);
}