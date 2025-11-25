import pandas as pd

countries = {
    "Україна": {"площа": 603.7, "населення": 36.7, "частина_світу": "Європа"},
    "Канада": {"площа": 9984, "населення": 39.6, "частина_світу": "Північна Америка"},
    "Єгипет": {"площа": 1001.5, "населення": 112, "частина_світу": "Африка"},
    "Китай": {"площа": 9597, "населення": 1410, "частина_світу": "Азія"},
    "Бразилія": {"площа": 8516, "населення": 214, "частина_світу": "Південна Америка"},
    "Франція": {"площа": 643.8, "населення": 67.5, "частина_світу": "Європа"},
    "Японія": {"площа": 377.9, "населення": 125, "частина_світу": "Азія"},
    "Нігерія": {"площа": 923.8, "населення": 223, "частина_світу": "Африка"},
    "Індія": {"площа": 3287.0, "населення": 1440, "частина_світу": "Азія"},
    "Австралія": {"площа": 7692.0, "населення": 26.5, "частина_світу": "Австралія"}
}

for c in countries:
    площа = countries[c]["площа"]
    населення = countries[c]["населення"]
    countries[c]["густина"] = round((населення * 1_000_000) / площа, 2)

df = pd.DataFrame.from_dict(countries, orient="index")
df.reset_index(inplace=True)
df.rename(columns={"index": "країна"}, inplace=True)

def print_menu():
    print("\n" + "=" * 55)
    print("        Аналіз даних про країни")
    print("=" * 55)
    print("1. Показати перші 3 рядки")
    print("2. Показати типи даних")
    print("3. Кількість рядків та стовпців")
    print("4. Описова статистика")
    print("5. Вивести всю таблицю")
    print("6. Країни з населенням > 200 млн")
    print("7. Сортування за площею (спадання)")
    print("8. Середня площа по частинах світу")
    print("9. Максимальна густина по частинах світу")
    print("0. Вихід")
    print("=" * 55)

def task1():
    print("\nПерші 3 рядки таблиці:\n")
    print(df.head(3).reset_index(drop=True).rename_axis(None).set_index(pd.Index([1,2,3])))

def task2():
    print("\nТипи даних у стовпцях:\n")
    print(df.dtypes)

def task3():
    rows, cols = df.shape
    print(f"\nКількість рядків: {rows}")
    print(f"Кількість стовпців: {cols}\n")

def task4():
    print("\nОписова статистика числових стовпців:\n")
    print(df.describe())

def task5():
    print("\nПовна таблиця даних:\n")
    print(df.to_string(index=False))

def task6():
    print("\nКраїни з населенням понад 200 млн:\n")
    result = df[df["населення"] > 200]
    if result.empty:
        print("Немає таких країн.")
    else:
        print(result.to_string(index=False))

def task7():
    print("\nКраїни за площею у порядку спадання:\n")
    print(df.sort_values(by="площа", ascending=False).head(10).to_string(index=False))

def task8():
    print("\nМаксимальна площа по частинам світу:\n")
    max_area = df.groupby("частина_світу")["площа"].max()
    print(max_area)

def task9():
    unique_continents = df["частина_світу"].unique()
    count = len(unique_continents)
    print("\nУнікальні частини світу:\n")
    for i, continent in enumerate(unique_continents, start=1):
        print(f"{i}. {continent}")
    print(f"\nВсього унікальних частин світу: {count}")


def main():
    while True:
        print_menu()
        choice = input("\nВаш вибір: ").strip()

        if choice == "1":
            task1()
        elif choice == "2":
            task2()
        elif choice == "3":
            task3()
        elif choice == "4":
            task4()
        elif choice == "5":
            task5()
        elif choice == "6":
            task6()
        elif choice == "7":
            task7()
        elif choice == "8":
            task8()
        elif choice == "9":
            task9()
        elif choice == "0":
            print("Роботу завершено.")
            break
        else:
            print("Помилка вводу! Спробуйте ще раз.")
main()
