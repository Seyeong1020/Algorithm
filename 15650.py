N, M = map(int, input().split())
visited = [False]*(N+1)
out = []

def solve(depth, start, N, M):
    if depth == M:
        print(' '.join(map(str, out)))
        return
    for i in range(start, N+1):
        #start를 넣어주면서 현재보다 큰 숫자만 탐색
        if not visited[i]:
            visited[i] = True
            out.append(i)
            solve(depth+1, i+1, N, M)
            visited[i] = False
            out.pop()

solve(0, 1, N, M)