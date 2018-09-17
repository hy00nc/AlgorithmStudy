#include <iostream>
#include <string>
using namespace std;





int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;

	int arr[1000001] = { 0,0,1,1,2,};

	for(int i = 5;i<=n;i++){
		arr[i] = arr[i-1] + 1 ;
		if(i % 2 == 0 && arr[i]>arr[i/2]+1)
			arr[i] = arr[i/2] +1;
		if(i % 3 == 0 && arr[i]>arr[i/3]+1)
			arr[i] = arr[i/3] +1;
		}

	cout<<arr[n];


}
