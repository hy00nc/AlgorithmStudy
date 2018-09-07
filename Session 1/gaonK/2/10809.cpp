#include <iostream>
#include <string>
using namespace std;

int alphabet[26];

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < 26; i++) {
        alphabet[i] = -1;
    }

    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (alphabet[str[i] - 'a'] == -1) {
            alphabet[str[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}