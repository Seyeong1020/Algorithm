#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N; //도시의 갯수
    scanf("%d", &N);
    vector<long int>d(N-1);
    vector<long int>prices(N);

    long long int dis = 0;
    for (int i=0; i<N-1; i++){
        scanf("%ld", &d[i]);
        dis+=d[i];
    }
    for (int i=0; i<N; i++){
        scanf("%ld", &prices[i]);
    }
    prices.pop_back();
    long long ans = 0;
    long int min = prices[0];
    for (int i=0; i<N-1; i++){
        if(prices[i] < min){
            min = prices[i];
        }
        ans+=min*d[i];
    }
    printf("%lld", ans);
}