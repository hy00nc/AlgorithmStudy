#include <iostream>
using namespace std;

#define MAX 10001
int a[MAX];

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	cin>>count;

	int front = 0;
	int back = 0;
	string input;

	for(int i=0;i<count;i++){
		cin>>input;
		if(input=="push"){
			int n;
			cin>>n;
			a[back] = n;
			back++;
		}
		else if(input=="pop"){
			if(front<back){
			cout<<a[front]<<"\n";
			front++;
			}
			else cout<<-1<<"\n";
		}
		else if(input=="size"){
			cout<<back-front<<"\n";
		}
		else if(input=="empty"){
			if(front==back) cout<<1<<"\n";
			else cout<<0<<"\n";
		}
		else if(input=="front"){
			if(front<back)
				cout<<a[front]<<"\n";
			else cout<<-1<<"\n";
		}
		else if(input=="back"){
			if(back==front) cout<<-1<<"\n";
			else cout<<a[back-1]<<"\n";
		}
	}
}
