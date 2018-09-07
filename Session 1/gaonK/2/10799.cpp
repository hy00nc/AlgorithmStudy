#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cin >> line;
    
    int count = 0;
    int stack = 0;
    int size = line.size();
    for (int i = 0; i < size; i++) {
        if (line[i] == '(') {
            stack++;
        } else {
            if (line[i - 1] == '(') {
                stack--;
                count += stack;
            } else {
                stack--;
                count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}