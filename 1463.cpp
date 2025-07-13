#include <stdio.h>
#define min(x, y) (x < y ? x : y)
/*
<초기값>
1 => 0번
2 => 1번 (2로 나눈다)
3 => 1번 (3으로 나눈다)

<그 이후>
4 => 2번 (2로 나누고 또 2로 나누기)
5 => 3번 (1로 빼고 4가 됨)
6 => 2번 (2로 나누고 3으로 나눔)
*/

int dp[1000001];

int main(){
    dp[2] = 1;
    dp[3] = 1;
    int N;
    scanf("%d", &N);
    for (int i =4; i<=N; i++){
        dp[i] = dp[i-1] +1;
        if (i%2 == 0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if (i%3==0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }

    }
    printf("%d", dp[N]);
}