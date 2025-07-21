#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct meet{
    int start;
    int end;
}meet;

int N;
vector<meet> meets;

bool compare(meet a, meet b){
    if (a.end == b.end){
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        meet m;
        scanf("%d %d", &m.start, &m.end);
        meets.push_back(m);
    }
    sort(meets.begin(), meets.end(), compare);

    
    int end_time = 0;
    int count = 0;
    for (int i=0; i<N; i++){
        if(meets[i].start >= end_time){
            count++;
            end_time = meets[i].end;
        }
    }
    printf("%d", count);
}