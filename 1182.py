N, S = map(int, input().split())
l = list(map(int, input().split()))

l.sort()

def solve(depth, size, now):
    sum = 0
    global r
    if depth==size:
        for ele in out:
            sum+= ele
        if sum == S:
            r+=1
        return
    
    for i in range(now, N):
        if not visited[i]:
            visited[i]=True
            out.append(l[i])
            solve(depth+1, size, i+1)
            visited[i]=False
            out.pop()

r = 0
for size in range(1, N+1):
    out = []
    visited = [False]*N
    solve(0, size, 0)

print(r)

    