a = float(input("Введіть a: "))
while a < 0:
    a = float(input("Введіть ще раз a (повинно бути додатним): "))

b = float(input("Введіть b: "))
while b < 0:
    b = float(input("Введіть ще раз b (повинно бути додатним): "))

if a < b:
    X = a / b + 5
elif a == b:
    X = -5
else:
    X = (a * a - b) / b

print("X =", X)

