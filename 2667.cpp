#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> board;
int num; // num => 단지수

typedef struct house{
    int x;
    int y;
}house;

vector<int> visited;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(house v){
    num++;
    visited[v.y*N+v.x] =1;
    board[v.y][v.x] = 0;
    for (int dir = 0; dir<4; dir++){
        house temp;
        temp.x = v.x + dx[dir];
        temp.y = v.y + dy[dir];
        if(temp.x >=0 && temp.x <N && temp.y >=0 && temp.y < N){
            if((board[temp.y][temp.x] == 1) && (visited[temp.y*N+temp.x]==0)){
                dfs(temp);
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    board.assign(N, vector<int>(N));
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%1d", &board[i][j]);
        }
    }
    visited.assign(N*N, 0);

    vector<int> result;
    int find;
    while(1){
        find = 0;
        int i, j ;
        for (i=0; i<N; i++){
            for (j=0; j<N; j++){
                if (board[i][j] == 1){
                    find = 1;
                    break;
                }
            }
            if (find == 1) break;
        }
        if (find == 0) break;
        num = 0;
        house start;
        start.x = j;
        start.y = i;
        dfs(start);
        result.push_back(num);
    }

    printf("%d\n", result.size());
    sort(result.begin(), result.end());
    for (int n : result){
        printf("%d\n", n);
    }
}