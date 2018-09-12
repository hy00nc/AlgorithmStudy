//11650 좌표 정렬하기 2
//struct와 cmp로 풀기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int x;
    int y;
};
bool cmp(const Point &a, const Point &b){
    if(a.x < b.x){
        return true;
    }else if(a.x == b.x){
        return (a.y < b.y);
    }if(a.x > b.x){
        return false;
    }

}


int main(){
    int n;
    cin >> n;

    vector<Point> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end(), cmp);

    for(int j=0; j<n; j++){
        cout << v[j].x << ' ' << v[j].y << '\n';
    }
    

}