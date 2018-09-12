//10989 수 정렬하기 3
#include <iostream>
using namespace std;
int a[10001];
int main(){

    int n;
    cin >> n;
    
    int v;
    int maxx = 0;

    for(int i=0; i<n; i++){
        cin >> v;
        a[v]++;
        maxx = (maxx<v?v:maxx);
    }

    for(int i=0; i<maxx+1; i++){
        if(a[i]!=0){
            for(int j=0; j<a[i]; j++){
                cout << i << '\n';
            }
        }
    }
    return 0;


}