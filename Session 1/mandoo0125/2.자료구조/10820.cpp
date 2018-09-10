#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int count[4]={0,};
    string str;
    while (getline(cin, str)) {
        for(int i=0;i<str.size();i++){
            if(str[i]==' ') count[3]++;
            else if(str[i]>='0'&&str[i]<='9') count[2]++;
            else if(str[i]>='A' && str[i]<='Z') count[1]++;
            else count[0]++;
        }
        for(int i=0;i<4;i++) cout<<count[i]<<" ";
        cout<<"\n";
        for(int i=0;i<4;i++) count[i]=0;
    }
}