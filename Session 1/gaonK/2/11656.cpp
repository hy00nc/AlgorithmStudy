#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int size = str.size();
    vector<string> dict;
    for (int i = 0; i < size; i++) {
        dict.push_back(str.substr(i, size));
    }

    sort(dict.begin(), dict.end());
    for (int i = 0; i < size; i++) {
        cout << dict[i] << '\n';
    }
    return 0;
}