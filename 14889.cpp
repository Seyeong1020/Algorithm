#include <stdio.h>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

std::stack<int> star;

std::vector<std::vector<int>> arr;
std::vector<int> visited;
std::vector<int> team;
int min = 999;
int N;


std::vector<int> others(std::vector<int> team){
    std::vector<int> others;
    for (int i =0; i<N; i++){
        others.push_back(i);
    }

    for (int i =0; i<team.size(); i++){
        others.erase(std::remove(others.begin(), others.end(), team[i]), others.end());     
    }
    return others;

}

int calculate(std::vector<int> team_tmp){
    int result = 0;
    for (int i =0; i<team_tmp.size(); i++){
        for (int j = 0; j<team_tmp.size(); j++){
            result += arr[team_tmp[i]][team_tmp[j]];
        }
    }
    return result;
}

void dfs(int N, int k){
    if (team.size()==N/2){
        int a = calculate(team);
        int b = calculate(others(team));
        int diff = abs(a - b);
        if (diff < min) min = diff;
        return;
    }
    for (int i =k; i<N; i++){
        if (visited[i]) continue;
        visited[i] = 1;
        team.push_back(i);
        dfs(N, i+1);
        team.pop_back();
        visited[i] = false;

    }
}

int main(){
    scanf("%d", &N);
    visited.assign(N, 0);
    std::vector<int> temp(N);
    for (int i =0; i<N; i++){
        for (int j = 0; j<N;j++){
            scanf("%d", &temp[j]);
        }
        arr.push_back(temp);
    }

    team.push_back(0);
    dfs(N, 1);
    printf("%d", min);
}