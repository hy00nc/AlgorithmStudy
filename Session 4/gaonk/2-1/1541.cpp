#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int size = str.size();

	int numSt = 0;
	int numEd = 0;
	bool minusFlag = false;
	int ans = 0;
	for (int i = 1; i <= size; i++) {
		if (str[i] == '+' || str[i] == '-' || i == size) {
			numEd = i;
			int num = stoi(str.substr(numSt, numEd - numSt));
			numSt = i + 1;
				
			if (minusFlag) {
				ans -= num;
			}
			else {
				ans += num;
			}

			if (i == size) break;

			if (str[i] == '-') {
				minusFlag = true;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}