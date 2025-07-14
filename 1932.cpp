#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MAX(a, b) (((a) > (b))? (a) : (b))

using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> dp(n, vector<int>(n));
    int a;
    for (int i=1; i<n+1; i++){
        for (int j=0; j<i; j++){
            scanf("%d", &a);
            if (i == 1) dp[i-1][j] = a;
            else if (j==0) dp[i-1][j] = a + dp[i-2][j];
            else if (j==i-1) dp[i-1][j] = a + dp[i-2][j-1];
            else{
                dp[i-1][j] = a + MAX(dp[i-2][j-1], dp[i-2][j]);
            }
        }
    }

    int max = -999;
    for (int i=0;i<n; i++){
        if (dp[n-1][i] > max) max = dp[n-1][i];
    }
    printf("%d", max);
}