N = int(input())
visited = [False]*N
out = []
def solve(depth):
    if depth==N:
        print(" ".join(map(str, out)))
        return
    else:
        for i in range(N):
            if (visited[i]==False):
                visited[i]=True
                out.append(i+1)
                solve(depth+1)
                out.pop()
                visited[i]=False
solve(0)