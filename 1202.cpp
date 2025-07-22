/* 인터넷 참고하여 풀었음 */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct jewel{
    int weight;
    int price;
}jewel;

vector<jewel> jewels;
vector<int> bags;

int N, K;

bool compare(jewel a, jewel b){
    return a.weight < b.weight;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        jewel input;
        scanf("%d %d", &input.weight, &input.price);
        jewels.push_back(input);
    }
    for (int i=0; i<K; i++){
        int b;
        scanf("%d", &b);
        bags.push_back(b);
    }

    sort(jewels.begin(), jewels.end(), compare);
    sort(bags.begin(), bags.end());

    long long int result = 0;
    priority_queue<int> q;
    int idx = 0;
    for (int i=0; i<K; i++){
        while(idx < N && jewels[idx].weight <= bags[i]){
            q.push(jewels[idx++].price);
        }
        if(q.size()){
            result += q.top();
            q.pop();
        }
    }

    printf("%lld", result);
}