def add():
    A = list(map(int, input('Enter a list: ').split()))
    print("Початковий список:", A)

    k = int(input('Enter index to insert: '))
    value = int(input('Enter value to insert: '))

    A.insert(k, value)

    print("Результат:", A)
    return A

add()
