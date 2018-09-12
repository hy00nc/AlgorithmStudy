#include <iostream>
#include <vector>
using namespace std;

struct node {
    int left;
    int right;
};

void preorder(vector<node> v, int idx) {
    cout << (char) (idx + 'A');
    if (v[idx].left != -1) {
        preorder(v, v[idx].left);
    }
    if (v[idx].right != -1) {
        preorder(v, v[idx].right);
    }
}

void inorder(vector<node> v, int idx) {
    if (v[idx].left != -1) {
        inorder(v, v[idx].left);
    }
    cout << (char) (idx + 'A');
    if (v[idx].right != -1) {
        inorder(v, v[idx].right);
    }
}

void postorder(vector<node> v, int idx) {
    if (v[idx].left != -1) {
        postorder(v, v[idx].left);
    }
    if (v[idx].right != -1) {
        postorder(v, v[idx].right);
    }
    cout << (char) (idx + 'A');
}

int main() {
    int N;
    cin >> N;

    vector<node> v(N);

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        root -= 'A';
        if (left == '.') {
            left = -1;
        } else {
            left -= 'A';
        }
        if (right == '.') {
            right = -1;
        } else {
            right -= 'A';
        }

        v[root].left = left;
        v[root].right = right;
    }

    preorder(v, 0);
    cout << '\n';
    inorder(v, 0);
    cout << '\n';
    postorder(v, 0);
    cout << '\n';

    return 0;
}