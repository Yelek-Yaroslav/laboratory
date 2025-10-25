n = 7

a = [[(j - (n - i - 2)) * (j >= n - i - 1) for j in range(n)] for i in range(n)]

for r in a:
    print(*r)
