#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Point{
    int x,y;
    Point(){
    }
    Point(int x, int y) : x(x), y(y){
    }
    bool operator < (const Point &v) const{
        if(x == v.x){
            return y < v.y;
        }
        else return x < v.x;
    }
};

vector <Point> a;


bool cmp(const Point &u, const Point &v){
    return u.y < v.y;
}


int dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}


int brute_force(int start, int end){
    int ans = -1;
    for(int i=start;i<=end-1;i++){
        for(int j=i+1;j<=end;j++){
            int d = dist(a[i],a[j]);
            if(ans==-1 || ans>d){
                ans = d;
            }
        }
    }
    return ans;
}

int solve(int start, int end){
    int n = end - start + 1;
    if(n<=3){
        return brute_force(start, end);
    }
    int mid = (start + end) /2;
    int ans = min(solve(start, mid),solve(mid+1,end));
    vector <Point> b;
    for(int i=start; i<=end;i++){
        int d = a[i].x - a[mid].x;
        if(d*d<ans){
            b.push_back(a[i]);
        }
    }
    sort(b.begin(),b.end(),cmp); //y기준으로 정렬
    int m = b.size();
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            int y = b[j].y - b[i].y;
            if(y*y<ans){
                int d = dist(b[i],b[j]);
                if(d<ans){
                    ans = d;
                }
            }
            else{
                break;
            }
        }
    }
    return ans;
}   


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x, y; 
        cin>>x>>y;
        a.push_back(Point(x,y));
    }
    sort(a.begin(), a.end());
    cout<<solve(0,n-1)<<'\n';

}