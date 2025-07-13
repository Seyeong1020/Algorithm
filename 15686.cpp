#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
// N => NxN인 도시
// M => 치킨집 중에서 최대 M개 고르기 나머지는 다 폐업

vector<vector<int>> city;
typedef struct point{
    int point_i;
    int point_j;
}point;

vector<point> chicken;
int num_chicken = 0;

vector<point> home;
int num_home = 0;

vector<int> visited;
int minimum = 9999999;
vector<int> choose;

void calcul(vector<int> choose){
    //인덱스 => home 인덱스, 값=> 집에서 가장 가까운 치킨집과의 거리
    vector<int> distance(num_home);
    int d;
    int tmp;
    int sum = 0;;
    for (int i=0; i<num_home; i++){
        d = 99999999;
        for(int j =0; j<M; j++){
            tmp = abs(home[i].point_i - chicken[choose[j]].point_i) + abs(home[i].point_j - chicken[choose[j]].point_j);
            if (tmp < d) d = tmp;
        }
        sum += d;
    }
    if (sum<minimum) minimum = sum;
}

void dfs(int depth, int k){
    if (depth == M){
        calcul(choose);
        return;
    }

    for (int i =k; i<num_chicken; i++){
        choose.push_back(i);
        dfs(depth+1, i+1);
        choose.pop_back();
    }
}


int main(){
    scanf("%d %d", &N, &M);
    city.assign(N, vector<int>(N));

    // 0 => 빈 칸, 1 => 집, 2 => 치킨집
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d", &city[i][j]);
            // 입력받을 때 입력받은 값이 2이면 (치킨집이면)
            // 치킨집 위치 정보 저장, 치킨집 갯수 키우기
            if (city[i][j] == 2){
                point c;
                c.point_i = i;
                c.point_j = j;
                chicken.push_back(c);
                num_chicken++;
            }
            else if (city[i][j] == 1){
                point c;
                c.point_i = i;
                c.point_j = j;
                home.push_back(c);
                num_home++;
            }
        }
    }
    visited.assign(num_chicken, 0);
    dfs(0, 0);
    printf("%d", minimum);
    return 0;
}

