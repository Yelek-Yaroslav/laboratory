N = int(input("Введіть N (1 < N < 9): "))

if N <= 1 or N >= 9:
    print("N повинно бути в діапазоні 1 < N < 9")
else:
    for i in range(1, N + 1):
        for j in range(1, i + 1):
            print(j, end=" ")
        print()
