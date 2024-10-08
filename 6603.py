def solve(depth, now):
    if depth==6:
        print(' '.join(map(str, out)))
        return
    for i in range(now, k):
        if not visited[i]:
            visited[i]=True
            out.append(l[i])
            solve(depth+1, i+1)
            visited[i] = False
            out.pop()



while(1):
    out=[]
    ans = list(map(int, input().split())) 
    k = ans[0]
    l = ans[1:]
    l.sort()
    if k==0:
        break
    visited = [False]*k
    solve(0, 0)
    print()

