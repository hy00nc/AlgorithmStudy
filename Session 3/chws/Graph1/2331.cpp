//2331
#include <iostream>
using namespace std;
int isChecked[300000];

int nextNum(int a, int p){
    int sum = 0;
    while(a>0){
        int tmp = a%10;
        int res = 1;
        for(int i=0; i<p; i++){
            res *= tmp;
        }
        sum += res;
        a /= 10;
    }
    return sum;
}

int main() 

    {ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    int p;
    cin >> a >> p;
    
    int ans = 0;
    int cnt = 0;
    while(!isChecked[a]){
        cnt ++;
        isChecked[a] = cnt;
        a = nextNum(a, p);

    }

    ans = isChecked[a] - 1 ;

    cout << ans << '\n';

    return 0;

}