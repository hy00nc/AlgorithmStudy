 #include <iostream>
using namespace std;

int pow2(int n){
    return 1<<n;
}


int solve(int x, int y, int n){
    if(n==1){
        return 2*x+y;
    }
    else{
        if(x<pow2(n-1)){
            if(y<pow2(n-1)){
                return solve(x,y,n-1);
            }
            else{
                return solve(x,y-pow2(n-1),n-1) + pow2(2*n-2);
            }
        }
        else{
            if(y<pow2(n-1)){
                return solve(x-pow2(n-1),y,n-1) + 2* pow2(2*n-2);
            }
            else{
                return solve(x-pow2(n-1),y-pow2(n-1),n-1) + 3*pow2(2*n-2);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, r, c;
    cin>>N>>r>>c;
    
    cout<<solve(r,c,N)<<'\n';
}