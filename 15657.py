N, M = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
out = []

def solve(depth, now):
    if depth==M:
        print(' '.join(map(str, out)))
        return
    for i in range(now, N):
        out.append(l[i])
        solve(depth+1, i)
        out.pop()

solve(0, 0)