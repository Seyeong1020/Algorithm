#include <iostream>
#include <vector>
using namespace std;

int N, M; // N: 소, M: 축사 수
vector<vector<int>> cows; //인접행렬느낌
vector<int> visited;
int visit = 1;
vector<int>match; //match[축사] = 소

int dfs(int cow){
    if(visited[cow]==visit) return false;
    visited[cow] = visit;
    for (int i=1; i<=M; i++){
        if(cows[cow][i]==1){
            if(match[i]==-1||dfs(match[i])){
                match[i] = cow;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    cows.resize(N+1, vector<int>(M+1, 0));
    visited.resize(N+1);
    match.assign(M+1, -1);
    for (int i=1; i<=N; i++){
        int num;
        cin >> num; //축사 개수
        for (int j=0; j<num; j++){
            int tmp;
            cin >> tmp; //선호하는 축사 번호
            cows[i][tmp] = 1;
        }
    }

    int ans = 0;
    for (int cow=1; cow<=N; cow++){
        ans += dfs(cow);
        visit++;
    }
    cout << ans << endl;
}