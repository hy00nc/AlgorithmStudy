//11650 좌표 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>//vector 사용
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for(int j=0; j<n; j++){
        cout << v[j].first << ' ' << v[j].second << '\n';
    }

    return 0;


    

}