#include <iostream>
#include <vector>
using namespace std;
int N, M; 
// N : 직원의 수(1~N번), M : 일의 개수(1~M번)

vector<vector<int>> adj;
void add_adj(int employee, int work){
    adj[employee][work] = 1;
}

int visited[1001] = {0,};
int visit = 1;

int match[1001] = {0, };
// match[일] = 사람

bool dfs(int employee){
    if(visited[employee]==visit) return false;
    visited[employee] = visit;
    for(int work=1; work<=M; work++){
        if(adj[employee][work]){
            if(match[work]==0 || dfs(match[work])){
                match[work] = employee;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    adj.assign(N+1, vector<int>(M+1, 0));
    int num;
    int work;
    for (int employee=1; employee<=N; employee++){
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> work;
            add_adj(employee, work);
        }
    }

    int ans = 0;
    for (int i=1; i<=N; i++){
        ans += dfs(i);
        visit++;
    }
    cout << ans << endl;
}