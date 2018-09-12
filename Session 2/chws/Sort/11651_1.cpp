//11651 좌표 정렬하기 2
#include <iostream>
#include <algorithm>
#include <vector>//vector 사용
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    for(int j=0; j<n; j++){
        cout << v[j].second << ' ' << v[j].first << '\n';
    }

    return 0;


    

}