#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
int N, M;
vector<vector<int>> adj;
vector<int> visited;
int visit = 1;

int match[1002]; //match[책] = 학생
bool dfs(int stu){
    if(visited[stu]==visit) return false;
    visited[stu] = visit;
    for (int i=1; i<=N; i++){ //지금 i는 책
        if(adj[stu][i] == 1){
            if(match[i]==-1 || dfs(match[i])/*겹쳤는데 다른 곳으로 옮길 수 있을 때*/){
                match[i] = stu;
                return true;
            }
        }
    }
    return false;
}

void add_adj(int stu, int a, int b){
    
    for (int i=a; i<=b; i++){
        adj[stu][i] = 1;
        //cout << "(" << stu << "," << i << ")" << endl;
    }
}
void solve(){
    
    cin >> N >> M;
    // N : 책 수, M : 학생 수
    adj.assign(M, vector<int>(N+1, 0));
    visited.assign(M, 0);
    memset(match, -1, sizeof(match));
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        add_adj(i, a, b);
    }

    int ans = 0;
    for (int i=0; i<M; i++){
        ans+=dfs(i);
        visit++;
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    for (int t=0; t<T; t++){
        solve();
    }
}