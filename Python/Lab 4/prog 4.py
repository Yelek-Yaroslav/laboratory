def find_subsequence():
    A = list(map(int, input("Введіть список чисел через пробіл: ").split()))
    print("Основний список:", A)

    sub = list(map(int, input("Введіть послідовність для пошуку: ").split()))
    print("Шукаємо послідовність:", sub)

    found = False
    for i in range(len(A) - len(sub) + 1):
        if A[i:i+len(sub)] == sub:
            found = True
            print(f"Послідовність знайдена, починаючи з індекса {i}")
            break

    if not found:
        print("Послідовність не знайдена у списку.")

find_subsequence()
