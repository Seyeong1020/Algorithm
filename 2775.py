T = int(input())

dp = [[-1]*15 for _ in range(15)]

for i in range(1, 15):
    dp[0][i] = i
    dp[i][1] = 1
    
for x in range(1, 15):
    for y in range(2, 15):
        dp[x][y] = dp[x][y-1]+dp[x-1][y]
            
for _ in range(T):
    k = int(input())
    n = int(input())
    
    
    print(dp[k][n])
    