N, M = map(int, input().split())
l = list(map(int, input().split()))
l.sort()

visited = [False]*N
out = []

def solve(depth, now):
    if depth == M:
        print(' '.join(map(str, out)))
        return
    for i in range(now, len(visited)):
        if not visited[i]:
            visited[i]= True
            out.append(l[i])
            solve(depth+1, i+1)
            visited[i] = False
            out.pop()

solve(0, 0)
    