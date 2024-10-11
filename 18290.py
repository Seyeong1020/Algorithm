N, M, K = map(int, input().split())
board = []

for _ in range(N):
    board.append(list(map(int, input().split())))

# 선택할 수 있는지 여부
# 선택 가능: 0, 선택 불가: 1 2
check = []
for _ in range(N):
    check.append(list(0 for _ in range(M)))

# 선택한 값을 저장할 곳
out = []

results= set()
def solve(depth, start_i, start_j):
    if sum([row.count(0) for row in check]) < K - depth:
        return
    if depth == K:
        results.add(sum(out))
        return
    
    for i in range(start_i, N):
        for j in range(start_j if i == start_i else 0, M):
            if check[i][j] == 0:

                # 지금 칸 선택하기
                check[i][j]+=1
                out.append(board[i][j])

                # 인접한 곳 처리
                for dx in [1, -1]:
                    nx = i+dx
                    if (0<= nx < N):
                        check[nx][j]+=1
                for dy in [1, -1]:
                    ny = j+dy
                    if (0<= ny < M):
                        check[i][ny]+=1

                solve(depth + 1, i, j + 1)

                #백트래킹
                check[i][j]-=1
                for dx in [1, -1]:
                    nx = i+dx
                    if 0<= nx < N:
                        check[nx][j]-=1
                for dy in [1, -1]:
                    ny = j+dy
                    if 0<= ny < M:
                        check[i][ny]-=1
                out.pop()

solve(0, 0, 0)
print(max(results))