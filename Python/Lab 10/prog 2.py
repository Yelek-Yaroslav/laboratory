import csv
import matplotlib.pyplot as plt

FILENAME = "worldbank_data.csv"
INDICATOR = "SE.PRM.UNER"
COUNTRY1 = "Ukraine"
COUNTRY2 = "United States"
data = {}

with open(FILENAME, "r", encoding="utf-8-sig") as file:
    reader = csv.reader(file)
    header = next(reader)

    years = [int(col.split()[0]) for col in header[4:]]

    for row in reader:
        if len(row) < 5:
            continue
        if row[3].strip() != INDICATOR:
            continue

        country = row[0].strip()
        values_raw = row[4:]

        values = []
        for v in values_raw:
            v = v.strip()
            if v == ".." or v == "":
                values.append(None)
            else:
                values.append(float(v))

        data[country] = values

plt.figure(figsize=(10, 6))
plt.plot(years, data[COUNTRY1], marker="o", linewidth=2, label=COUNTRY1)
plt.plot(years, data[COUNTRY2], marker="o", linewidth=2, label=COUNTRY2)

plt.xlabel("Year")
plt.ylabel("Children out of school, primary")
plt.title("Dynamics of SE.PRM.UNER for Ukraine and USA (2005–2024)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

while True:
    country_input = input(
        "Enter country name (Ukraine, United States) or 'exit' to stop: "
    ).strip()

    if country_input.lower() == "exit":
        print("Exiting...")
        break

    if country_input not in data:
        print("No data for this country!")
        continue

    filtered_years = []
    filtered_values = []

    for y, v in zip(years, data[country_input]):
        if v is not None:
            filtered_years.append(y)
            filtered_values.append(v)

    if not filtered_values:
        print("No numeric data for this country!")
        continue

    plt.figure(figsize=(10, 6))
    plt.bar(filtered_years, filtered_values)

    for x, y_val in zip(filtered_years, filtered_values):
        plt.text(x, y_val, str(int(y_val)), ha="center", va="bottom", fontsize=8)

    plt.xlabel("Year")
    plt.ylabel("Children out of school, primary")
    plt.title(f"Bar Chart for {country_input}")
    plt.grid(True)
    plt.tight_layout()
    plt.show()