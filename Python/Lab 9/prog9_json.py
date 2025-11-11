import json
import os

FILENAME = "countries.json"
RESULT_FILE = "result.json"


def load_data():
    if not os.path.exists(FILENAME):
        return {}
    with open(FILENAME, "r", encoding="utf-8") as f:
        return json.load(f)


def save_data(countries):
    with open(FILENAME, "w", encoding="utf-8") as f:
        json.dump(countries, f, ensure_ascii=False, indent=4)


def show_all(countries):
    for country, data in countries.items():
        print(f"{country}: площа = {data['площа']} км², населення = {data['населення']} млн, частина світу = {data['частина_світу']}")
    print()


def add_country(countries):
    try:
        name = input("Введіть назву країни: ")
        if name in countries:
            print("Така країна вже існує!")
            return
        area = float(input("Введіть площу (км²): "))
        population = float(input("Введіть населення (млн): "))
        region = input("Введіть частину світу: ")
        countries[name] = {"площа": area, "населення": population, "частина_світу": region}
        save_data(countries)
        print("Країну успішно додано!\n")
    except ValueError:
        print("Помилка введення даних!\n")


def remove_country(countries):
    name = input("Введіть назву країни для видалення: ")
    if name in countries:
        del countries[name]
        save_data(countries)
        print("Країну видалено!\n")
    else:
        print("Такої країни немає!\n")


def show_sorted(countries):
    for country in sorted(countries.keys()):
        data = countries[country]
        print(f"{country}: площа = {data['площа']} км², населення = {data['населення']} млн, частина світу = {data['частина_світу']}")
    print()


def find_africa_asia(countries):
    found = {c: d for c, d in countries.items() if d["частина_світу"].lower() in ("африка", "азія")}
    if found:
        print("Країни, розташовані в Африці або Азії:")
        for name in found.keys():
            print("-", name)
        with open(RESULT_FILE, "w", encoding="utf-8") as f:
            json.dump(found, f, ensure_ascii=False, indent=4)
        print(f"Результати збережено у файл {RESULT_FILE}\n")
    else:
        print("Немає країн з Африки або Азії.\n")


def main():
    if not os.path.exists(FILENAME):
        initial = {
            "Україна": {"площа": 603.7, "населення": 36.7, "частина_світу": "Європа"},
            "Канада": {"площа": 9984, "населення": 39.6, "частина_світу": "Північна Америка"},
            "Єгипет": {"площа": 1001.5, "населення": 112, "частина_світу": "Африка"},
            "Китай": {"площа": 9597, "населення": 1410, "частина_світу": "Азія"},
            "Бразилія": {"площа": 8516, "населення": 214, "частина_світу": "Південна Америка"},
            "Франція": {"площа": 643.8, "населення": 67.5, "частина_світу": "Європа"},
            "Японія": {"площа": 377.9, "населення": 125, "частина_світу": "Азія"},
            "Нігерія": {"площа": 923.8, "населення": 223, "частина_світу": "Африка"},
            "Індія": {"площа": 3287, "населення": 1440, "частина_світу": "Азія"},
            "Австралія": {"площа": 7692, "населення": 26.5, "частина_світу": "Австралія"}
        }
        save_data(initial)

    countries = load_data()

    while True:
        print("Меню:")
        print("1 – Показати всі країни")
        print("2 – Додати країну")
        print("3 – Видалити країну")
        print("4 – Показати країни за алфавітом")
        print("5 – Знайти країни в Африці або Азії")
        print("0 – Вихід")

        choice = input("Ваш вибір: ")
        print()

        if choice == "1":
            show_all(countries)
        elif choice == "2":
            add_country(countries)
        elif choice == "3":
            remove_country(countries)
        elif choice == "4":
            show_sorted(countries)
        elif choice == "5":
            find_africa_asia(countries)
        elif choice == "0":
            print("Роботу завершено.")
            break
        else:
            print("Невірний вибір!\n")


if __name__ == "__main__":
    main()
