N, M = map(int, input().split())
out = []

def solve(depth):
    if depth==M:
        print(' '.join(map(str, out)))
        return
    for i in range(N):
        out.append(i+1)
        solve(depth+1)
        out.pop()

solve(0)

