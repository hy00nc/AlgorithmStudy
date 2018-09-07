#include <iostream>
#include <string>
using namespace std;

#define max(X,Y) ((X) > (Y) ? (X) : (Y))

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int score[2][n+1];
		int d[n+1][3];
		//초기화 부분
		for(int i=1;i<=n;i++){
			cin>>score[0][i];
		}
		for(int i=1;i<=n;i++){
			cin>>score[1][i];
		}
		d[0][0] =d[0][1] = d[0][2] =0;
		for(int i=1;i<=n;i++){
			d[i][0]=max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
			d[i][1]=max(d[i-1][0],d[i-1][2]) + score[1][i];
			d[i][2]=max(d[i-1][0],d[i-1][1]) + score[0][i];
		}
		cout<<max(d[n][0],max(d[n][1],d[n][2]))<<"\n";
	}
}
