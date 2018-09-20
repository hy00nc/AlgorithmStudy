#include <cstdio>
#include <vector>
using namespace std;

int arr[500001];

long long solve(int st, int ed) {
    if (st == ed) {
        return 0;
    }

    int mid = (st + ed) / 2;
    long long ans = solve(st, mid) + solve(mid + 1, ed);

    int i = st, j = mid + 1;
    vector<int> tmp;
    
    while (i <= mid || j <= ed) {
        if (i <= mid && (j > ed || arr[i] <= arr[j])) {
            tmp.push_back(arr[i++]);
        } else {
            ans += mid + 1 - i;
            tmp.push_back(arr[j++]);
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        arr[st + i] = tmp[i];
    }

    return ans;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    long long ans = solve(0, N - 1);

    printf("%lld\n", ans);

    return 0;
}