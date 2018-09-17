//2667
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N;
int graph[26][26];
int isVisited[26][26];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int a, int b, int num){
    isVisited[a][b] = num;

    for(int i=0; i<4; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny<N){
            if(graph[nx][ny] && !isVisited[nx][ny]){
                dfs(nx, ny, num);
            }
        }
    }
    
}

int main(){
    
    
    cin >> N;

    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<N; j++){
            graph[i][j] = s[j]-'0';
            isVisited[i][j] = 0;
        }
    }

    int tot = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j] && !isVisited[i][j])
                dfs(i, j, ++tot);
        }
    }

    cout << tot << '\n';

    vector<int> cnt;
    int num;
    for(int k=1; k<=tot; k++){
        num = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(isVisited[i][j]==k){
                    num++;
                }
            }
        }
        cnt.push_back(num);

    }
    

    sort(cnt.begin(), cnt.end());
    for(int x: cnt){
        cout << x << '\n';
    }

    return 0;
}