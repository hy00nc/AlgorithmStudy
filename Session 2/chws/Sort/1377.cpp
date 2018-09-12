//1377 버블 소트
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> d(n);
    for(int i=0; i<n; i++){
        cin >> d[i].first;
        d[i].second = i;
    }

    sort(d.begin(), d.end());

    int max = 0;
    for(int i=0; i<n; i++){

        if(d[i].second - i > max){
            max = d[i].second - i;
        }
    }
    max++;
    cout << max << '\n';
    return 0;





}