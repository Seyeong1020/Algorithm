#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int M, N;
// M : 상자 가로 칸 수
// N : 상자 세로 칸수
// NxM의 벡터

typedef struct box{
    int x;
    int y;
}box;

vector<vector<int>> board;
vector<box> tomato;
queue<box> q;




int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int inBoard(int x, int y){
    if (x < M && x >=0 && y <N && y >=0){
        return 1;
    }
    else{
        return 0;
    }
}

void bfs(){
    while(!q.empty()){
        box pbox = q.front();
        int px = pbox.x;
        int py = pbox.y;
        q.pop();
        for (int dir=0; dir<4; dir++){
            box temp;
            int x = px + dx[dir];
            int y = py + dy[dir];
            if (inBoard(x, y) && board[y][x]==0){
                temp.x = x;
                temp.y = y;
                board[y][x] = board[py][px] + 1;
                q.push(temp);
            }
        }
    }
}



int main(){
    scanf("%d %d", &M, &N);
    board.assign(N, vector<int>(M));
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            scanf("%d", &board[i][j]);
            if (board[i][j]==1){
                box t;
                t.x = j;
                t.y = i;
                q.push(t);
            }
        }
    }
    
    bfs();
    int result = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if(board[i][j]==0){
                printf("-1");
                return 0;
            }
            if(result < board[i][j]) result = board[i][j];
        }
    }
    printf("%d", result-1);
}

