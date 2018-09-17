//7576
#include <iostream>
#include <queue>
using namespace std;
int N, M;
int tomato[1001][1001];
int isRipe[1001][1001];//time
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> M >> N;

    queue<pair<int, int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x;
            cin >> x;
            tomato[i][j] = x;
            isRipe[i][j] = -1;
            

            if(x == 1){
                q.push(pair<int, int>(i, j));
                isRipe[i][j] = 0;
            }
        }
    }




    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(tomato[nx][ny]==0  && isRipe[nx][ny]==-1){
                    q.push(pair<int, int>(nx, ny));
                    isRipe[nx][ny] = isRipe[a][b] + 1;
                }
            }
        }
    }




 
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tomato[i][j]==0 && isRipe[i][j] == -1){
                cout << -1 << '\n';
                return 0;
            }

            if(tomato[i][j]==0 && isRipe[i][j]!=0){
                if(result < isRipe[i][j])
                    result = isRipe[i][j];
            }
        }
    }

    cout << result << '\n';
    return 0;

    
}

