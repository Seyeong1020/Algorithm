#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int N;
vector<int> ropes;

int main(){
    scanf("%d", &N);
    ropes.resize(N);
    for (int i=0; i<N; i++){
        scanf("%d", &ropes[i]);
    }
    sort(ropes.begin(), ropes.end());

    int s = accumulate(ropes.begin(), ropes.end(), 0);
    int count = ropes.size();
    int max = 0;
    for (int i=0; i<N; i++){
        int temp = ropes[i] * count;
        if (temp > max) max = temp;
        count--;
    }
    printf("%d", max);
}