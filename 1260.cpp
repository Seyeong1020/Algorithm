#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int N, M, V;

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (int next : graph[v]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    vector<bool> visited_bfs(N + 1, false);
    q.push(v);
    visited_bfs[v] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (int next : graph[cur]) {
            if (!visited_bfs[next]) {
                visited_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    graph.assign(N+1, vector<int>());
    int a, b;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited.assign(N + 1, false);
    dfs(V);

    printf("\n");

    bfs(V);
    return 0;
}
