//10824 네 수
#include <iostream>
#include <string>
using namespace std;
int main(){

    string a, b, c, d;
    cin >> a >> b >> c >> d;
    string r1 = a+b;
    string r2 = c+d;

    long long f1 = stoll(r1);
    long long f2 = stoll(r2);

    cout << f1+f2 << '\n';
    return 0;

}