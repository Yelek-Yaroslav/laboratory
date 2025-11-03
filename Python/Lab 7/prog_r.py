import string

def create_file(filename):
    try:
        with open(filename, "w", encoding="utf-8") as f:
            f.write("Тиша, спокій і теплий вітер дарують гармонію.\n")
            f.write("Життя прекрасне, коли помічаєш красу довкола. \n")
            f.write("Кожна мить — це можливість побачити щось нове.\n")
            f.write("Посміхнись, і день стане ще кращим!\n")
            f.write("Спробуй підрахувати кількість слів правильно.\n")
        print(f"Файл '{filename}' успішно створено!\n")
    except Exception as e:
        print("Помилка під час створення файлу:", e, "\n")


def analyze_words(input_file, output_file):
    try:
        with open(input_file, "r", encoding="utf-8") as f:
            text = f.read()
    except FileNotFoundError:
        print(f"Помилка: файл '{input_file}' не знайдено!\n")
        return
    except Exception as e:
        print("Помилка під час читання файлу:", e, "\n")
        return

    for p in string.punctuation + "—…«»":
        text = text.replace(p, " ")

    words = text.split()
    word_groups = {}

    for word in words:
        length = len(word)
        if length <= 16:
            word_groups.setdefault(length, []).append(word)

    try:
        with open(output_file, "w", encoding="utf-8") as f:
            for length in sorted(word_groups.keys()):
                count = len(word_groups[length])
                words_list = ", ".join(word_groups[length])
                f.write(f"{length}-символьних слів: {count} ({words_list})\n")
        print(f"Результати записано у файл '{output_file}'!\n")
    except Exception as e:
        print("Помилка запису у файл:", e, "\n")


def print_file(filename):
    try:
        with open(filename, "r", encoding="utf-8") as f:
            print(f"Вміст файлу '{filename}':\n")
            for line in f:
                print(line.strip())
    except FileNotFoundError:
        print(f"Файл '{filename}' не знайдено!\n")
    except Exception as e:
        print("Помилка при відкритті файлу:", e, "\n")


def main():
    file1 = "TF4_1.txt"
    file2 = "TF4_2.txt"

    create_file(file1)
    analyze_words(file1, file2)
    print_file(file2)


if __name__ == "__main__":
    main()
