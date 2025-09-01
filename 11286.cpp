#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a)==abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main(){
    int N;
    scanf("%d", &N);
    int x;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i=0; i<N; i++){
        scanf("%d", &x);
        if (x == 0){
            if (pq.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
}