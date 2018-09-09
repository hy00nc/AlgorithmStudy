//11655 ROT13
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    for(char x : str){
        int dif;
        if(x>='A' && x<='M'){
            cout << char(x+13);
        }else if(x>='a' && x<='m'){
            cout << char(x+13);
        }else if(x>='N' && x<='Z'){
            cout << char(x-13);
        }else if(x>='n' && x<='z'){
            cout << char(x-13);
        }else if(x == ' '){
            cout << ' ';
        }else{
            cout << char(x);
        }
    }
    cout << '\n';
    return 0;
}