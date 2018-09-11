#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int cnt = 1;
    queue<int> q;
    queue<int> result;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    cout << '<';
    while(!q.empty()){
        
        int tmp = q.front();
        q.pop();
        if(cnt%m == 0){
            cnt = 1;
            result.push(tmp);
        }
        else{
             q.push(tmp);
             cnt++;
        }
       
        
    }
    int j;
    for(j=0; j<n-1; j++){
        cout << result.front() << ", ";
        result.pop();
    }
    cout << result.front();

    cout << ">\n";
    return 0;
}