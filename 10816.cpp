#include <stdio.h>
#include <vector>
#include <algorithm>

int main(){
    int N;
    scanf("%d", &N);
    std::vector<int> arr(N);
    for (int i =0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    int M;
    scanf("%d", &M);
    std::vector<int> toFind(M);
    for (int i =0; i<M; i++){
        scanf("%d", &toFind[i]);
    }

    sort(arr.begin(), arr.end());

    for (int i =0; i<M; i++){
        printf("%d ", upper_bound(arr.begin(), arr.end(), toFind[i])-lower_bound(arr.begin(), arr.end(), toFind[i]));
    }
}