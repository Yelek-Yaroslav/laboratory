n = int(input("Ввведіть довжину масиву:"))

array = []
for i in range(n):
    num = float(input(f"Ведіть елемен {i + 1}:") )
    array.append(num)

negative_numbers = [x for x in array if x < 0]

if len(negative_numbers) > 0:
    average = sum(negative_numbers) / len(negative_numbers)
    print("Середнє арифметичне від’ємних елементів:", average)
else:
    print("У масиві немає від’ємних елементів.")
