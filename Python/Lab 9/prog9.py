import csv

def read_csv_file(filename):
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            data = [row for row in reader if any(cell.strip() for cell in row)]

        header_index = None
        for i, row in enumerate(data):
            if "Country Name" in row:
                header_index = i
                break

        if header_index is None:
            print("Помилка: не знайдено заголовок із назвами стовпців.")
            return None, None

        header = data[header_index]
        rows = data[header_index + 1:]
        return header, rows

    except FileNotFoundError:
        print(f"Помилка: файл '{filename}' не знайдено.")
        return None, None
    except Exception as e:
        print(f"Помилка при читанні файлу: {e}")
        return None, None


def write_csv_file(filename, header, data):
    try:
        with open(filename, 'w', newline='', encoding='utf-8') as file:
            writer = csv.writer(file)
            writer.writerow(header)
            writer.writerows(data)
        print(f"Результати збережено у файл: {filename}")
    except Exception as e:
        print(f"Помилка при записі файлу: {e}")


def main():
    input_file = "GDP_per_capita.csv"
    output_file = "GDP_filtered.csv"

    header, data = read_csv_file(input_file)
    if not data:
        return

    print("=== Вміст CSV файлу (перші 5 рядків) ===")
    for row in data[:5]:
        print(row)
    print("...")

    try:
        threshold = float(input("Введіть мінімальне значення GDP per capita для пошуку: "))
    except ValueError:
        print("Помилка: введіть числове значення.")
        return

    try:
        year_index = header.index("2016")
    except ValueError:
        print("Не знайдено стовпець з даними за 2016 рік.")
        return

    filtered_data = []
    for row in data:
        try:
            value = float(row[year_index])
            if value > threshold:
                filtered_data.append(row)
        except (ValueError, IndexError):
            continue

    write_csv_file(output_file, header, filtered_data)
    print(f"Знайдено {len(filtered_data)} країн з показником > {threshold}")


if __name__ == "__main__":
    main()
