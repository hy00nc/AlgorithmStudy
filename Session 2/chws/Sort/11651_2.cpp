//11651 좌표 정렬하기 2
//cmp 함수 만들어서 짜보기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second < b.second){
        return true;
    }else if(a.second == b.second){
        return (a.first < b.first);
    }else if(a.second > b.second){
        return false;
    }

}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second ;
    }
    sort(v.begin(), v.end(), cmp);

    for(int j=0; j<n; j++){
        cout << v[j].first << ' ' << v[j].second << '\n';
    }
    
    return 0;


}