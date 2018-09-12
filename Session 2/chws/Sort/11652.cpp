//11652 카드
#include <iostream>
#include <algorithm>
using namespace std;
long long d[1000001];
int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> d[i];
    }

    sort(d, d+n);

    int count = 1;
    int max = 1;
    long long result = d[0];
    for(int i=1; i<n; i++){
        if(d[i-1]==d[i]){
            count ++;
        }else{
            if(max<count){
                max = count;
                result = d[i-1];
            }
            count = 1;
        }

    }


    if(max<count){
        max = count;
        result = d[n-1];
    }


    cout << result << '\n';
    return 0;


}