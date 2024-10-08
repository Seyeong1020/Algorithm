N, M = map(int, input().split())
out = []

def solve(depth, now):
    if depth==M:
        print(' '.join(map(str, out)))
        return
    for i in range(now, N+1):
        out.append(i)
        solve(depth+1, i)
        out.pop()

solve(0, 1)

