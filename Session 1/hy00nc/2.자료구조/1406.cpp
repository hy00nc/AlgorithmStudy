#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
//char input[60001];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string input;
	int n;
	cin>>input>>n;
	stack<char> s1,s2;
	//스택에 처음 문자열 모두 push
	for(int i=0;i<input.length();i++){
		s1.push(input[i]);
	}
	while(n--){
		char c;
		cin>>c;
		if(c=='L'){
			if(!s1.empty()){
			char t;
			t = s1.top();
			s1.pop();
			s2.push(t);
		}
		}
		else if(c=='D'){
			if(!s2.empty()){
				char t;
				t = s2.top();
				s2.pop();
				s1.push(t);
			}
		}
		else if(c=='B'){
			if(!s1.empty()){
				s1.pop();
			}
		}
		else if(c=='P'){
			char a;
			cin>>a;
			s1.push(a);
		}
	}
	while(!s1.empty()){
		char t = s1.top();
		s1.pop();
		s2.push(t);
	}
	while(!s2.empty()){
		cout<<s2.top();
		s2.pop();
	}
}
