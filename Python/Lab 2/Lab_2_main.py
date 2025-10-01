import math
from mod import total_distance

def calc_z(m):
    return 1 / math.sqrt(m + 2)

m = int(input("Введіть число m: "))
print("z =", calc_z(m))

n = int(input("Введіть кількість днів: "))
print("Сумарний шлях спортсмена =", total_distance(n))