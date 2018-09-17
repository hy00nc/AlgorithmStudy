//2178
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int map[101][101];
int isVisited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
int main(){
    cin >> N >> M;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j]-'0';
        }
    }

    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));
    isVisited[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(map[nx][ny]!=0 && !isVisited[nx][ny]){
                    q.push(pair<int, int>(nx, ny));
                    isVisited[nx][ny] = isVisited[x][y] + 1;
                }
            }
        }
    }

    cout << isVisited[N-1][M-1] << '\n';



    return 0;
    
}
