import math

def calc_z(m):
    return 1 / math.sqrt(m + 2)

def total_distance(n):
    distance = 10
    total = 0
    for _ in range(n):
        total += distance
        distance *= 1.1
    return total

m = int(input("Введіть число m: "))
print("z =", calc_z(m))

n = int(input("Введіть кількість днів: "))
print("Сумарний шлях спортсмена =", total_distance(n))
