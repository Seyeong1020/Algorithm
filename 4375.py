while (1):
    try:
        n = int(input())
    except:
        break
    num = 0
    p = 0
    while (1):
        num = num*10 + 1
        p += 1
        if num%n == 0:
            break
    print(p)
        