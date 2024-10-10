N, M = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
out = []
visited = [False]*N
def solve(depth):
    check = 0
    if depth == M:
        print(' '.join(map(str, out)))
        return 
    for i in range(N):
        if not visited[i] and check!=l[i]:
            visited[i] = True;
            out.append(l[i])
            check = l[i]
            solve(depth+1)
            visited[i] = False;
            out.pop()
solve(0)