//11004 K번째 수
#include <iostream>
#include <algorithm>
using namespace std;
int d[5000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    k--;
    nth_element(d, d+k, d+n);

    cout << d[k] << '\n';
    return 0;

}