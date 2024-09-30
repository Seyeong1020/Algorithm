import sys
T = int(input())
for _ in range(T):
    check =1
    p = sys.stdin.readline().strip('\n')
    n = int(sys.stdin.readline())
    arr = sys.stdin.readline().strip('[]\n').split(',')
    arr = [int(i) for i in arr if i.isdigit()]
    for i in p:
        if (i=='R'):
            arr.reverse()
        elif (i=='D'):
            if (len(arr)==0):
                check = 0
                print("error")
                break
            del arr[0]
    if (check):
        print(arr)
