#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    string s;

    if (R % 2 == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C - 1; j++) {
                if (i % 2 == 0) {
                    s.append("R");
                } else {
                    s.append("L");
                }
            }
            if (i != R - 1) {
                s.append("D");
            }
        }
    }

    if (R % 2 == 0 && C % 2 == 1) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R - 1; j++) {
                if (i % 2 == 0) {
                    s.append("D");
                } else {
                    s.append("U");
                }
            }
            if (i != C - 1) {
                s.append("R");
            }
        }
    }

    if (R % 2 == 0 && C % 2 == 0) {
        int tarX, tarY;
        int min = 10000;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if ((i + j) % 2 == 1) {
                    if (min > map[i][j]) {
                        min = map[i][j];
                        tarX = i;
                        tarY = j;
                    }
                }
            }
        }
        
        string s2;
        int r1 = 0, r2 = R - 1;
        while (r2 - r1 > 1) {
            if (r1 != tarX && r1 + 1 != tarX) {
                for (int i = 0; i < C - 1; i++) {
                    s.append("R");
                }
                s.append("D");
                for (int i = 0; i < C - 1; i++) {
                    s.append("L");
                }
                s.append("D");
                r1 += 2;
            }

            if (r2 != tarX && r2 - 1 != tarX) {
                for (int i = 0; i < C - 1; i++) {
                    s2.append("R");
                }
                s2.append("D");
                for (int i = 0; i < C - 1; i++) {
                    s2.append("L");
                }
                s2.append("D");
                r2 -= 2;
            }
        }

        int c1 = 0, c2 = C - 1;
        while (c2 - c1 != 1) {
            if (c1 != tarY && c1 + 1 != tarY) {
                s.append("DRUR");
                c1 += 2;
            }
            if (c2 != tarY && c2 - 1 != tarY) {
                s2.append("DRUR");
                c2 -= 2;
            }
        }

        if (r1 == tarX) {
            s.append("DR");
        } else {
            s.append("RD");
        }

        reverse(s2.begin(), s2.end());
        s.append(s2);
    }
    cout << s << '\n';

    return 0;
}