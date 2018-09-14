#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a, int &b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> minus;
	vector<int> zero;
	vector<int> plus;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x < 0) minus.push_back(x);
		else if (x == 0) zero.push_back(x);
		else plus.push_back(x);
	}

	sort(minus.begin(), minus.end(), cmp);
	sort(plus.begin(), plus.end());

	int ans = 0;
	while (!plus.empty()) {
		int x = plus.back();
		plus.pop_back();
		if (!plus.empty()) {
			int y = plus.back();
			plus.pop_back();
			if (y != 1) ans += x * y;
			else ans += x + y;
		}
		else {
			ans += x;
		}
	}

	while (!minus.empty()) {
		int x = minus.back();
		minus.pop_back();
		if (!minus.empty()) {
			int y = minus.back();
			minus.pop_back();
			ans += x * y;
		}
		else {
			if (zero.empty()) {
				ans += x;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}