//4963
#include <iostream>
using namespace std;
int map[51][51];
bool isVisited[51][51];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, -1, 1, -1, 0, 1};
int W, H;
void dfs(int x, int y){
    isVisited[x][y] = true;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<H && ny>=0 && ny<W){
            if(map[nx][ny] && !isVisited[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    
    while(cin >> W >> H && !(W==0 && H==0)){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> map[i][j];
            }
        }

        int cnt = 0;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j] && !isVisited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

 

        cout << cnt << '\n';

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                map[i][j] = 0;
                isVisited[i][j] = 0;
            }
        }
    }
    return 0;
}