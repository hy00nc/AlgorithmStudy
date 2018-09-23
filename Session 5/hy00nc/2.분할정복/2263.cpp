#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int inorder[100000];
int postorder[100000];
int pos[1000001];

void solve(int in_start,int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start>post_end) return;
    int root = postorder[post_end];
    cout<<root<<' ';
    int p = pos[root];
    int left = p-in_start;
    solve(in_start, p-1,post_start,post_start + left-1);
    solve(p+1,in_end,post_start+left,post_end-1);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
        pos[inorder[i]]=i;
    }
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }
    solve(0,n-1,0,n-1);
}