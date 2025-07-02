#include <stdio.h>
#include <vector>

int N;
int result = 0; //가능한경우의 수
std::vector<std::vector<int>> visited;
std::vector<int> place_row;

int isPossible(int depth, int i){
    if (depth == 0) return 1;
    for (int y = 0; y < depth; y++){
        if (place_row[y] == i) return 0;
        if (place_row[y] == i-(depth-y) || place_row[y] == i+(depth-y)) return 0;
    }
    return 1;
}

void dfs(int depth, int k){
    if (depth == N) {
        result++;
        return;
    }
    for (int i =0; i<N; i++){
        visited[depth][i] = 0;
    }

    for (int i =0; i<N; i++){
        if (visited[depth][i] == 1) continue;
        else{
            visited[depth][i] = 1;
            if (isPossible(depth, i)){
                //printf("add %d %d\n", depth, i);
                place_row[depth] = i;
                dfs(depth+1, 0);
                place_row[depth] = -1; 
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    visited.assign(N, std::vector<int>(N, 0));
    place_row.assign(N, -1);
    dfs(0, 0);
    printf("%d", result);
}
