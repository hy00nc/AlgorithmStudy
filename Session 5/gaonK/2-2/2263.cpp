#include <iostream>
#include <vector>
using namespace std;

vector<int> inorder;
vector<int> postorder;

void findPreorder(int iSt, int iEd, int pSt, int pEd) {
    if (iSt > iEd || pSt > pEd) {
        return;
    }

    cout << postorder[pEd] << ' ';

    int rootIdx;
    for (int i = iSt; i <= iEd; i++) {
        if (inorder[i] == postorder[pEd]) {
            rootIdx = i;
            break;
        }
    }

    int size = rootIdx - iSt;
    findPreorder(iSt, rootIdx - 1, pSt, pSt + size - 1);
    findPreorder(rootIdx + 1, iEd, pSt + size, pEd - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        inorder.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        postorder.push_back(x);
    }

    findPreorder(0, N - 1, 0, N - 1);
    cout << '\n';

    return 0;
}