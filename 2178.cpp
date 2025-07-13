#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int>visited;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct room{
    int x;
    int y;
    int count;
}room;

int bfs(){
    room start;
    start.x = 0;
    start.y = 0;
    start.count = 0;
    room end;
    end.x = M-1;
    end.y = N-1;


    queue<room> queue;
    visited[start.y*M+start.x] = 1;
    queue.push(start);
    room cur;
    while(!queue.empty()){
        cur = queue.front();
        queue.pop();
        if (cur.x == end.x && cur.y == end.y){
            break;
        }

        for (int dir=0; dir<4; dir++){
            room temp;
            temp.x = cur.x + dx[dir];
            temp.y = cur.y + dy[dir];
            if (temp.x >=0 && temp.x <M && temp.y >=0 && temp.y < N){
                if ( (graph[temp.y][temp.x]== 1) &&(visited[temp.y*M+temp.x]==0)){
                    visited[temp.y*M+temp.x] =1;
                    temp.count = cur.count+1;
                    queue.push(temp);
                }
            }
        }
    }

    return cur.count;
}

int main(){
    scanf("%d %d", &N, &M);
    graph.assign(N, vector<int>(M));
    visited.assign(N*M, 0);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    printf("%d", bfs()+1);
}
