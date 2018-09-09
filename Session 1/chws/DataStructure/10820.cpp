//10820 문자열 분석
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(getline(cin, str)){
        int lower = 0;
        int upper = 0;
        int num = 0;
        int space = 0;
        for(char x : str){
            if(x>='a' && x<='z'){
                lower++;
            }else if(x>='A' && x<='Z' ){
                upper++;
            }else if(x>='0' && x<='9'){
                num++;
            }else if(x==' '){
                space++;
            }
        }
        cout << lower << ' ' << upper << ' ' << num << ' ' << space << '\n';
    }
    return 0;
}