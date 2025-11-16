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

    years = [int(col.split()[0]) for col in header[4:]]  # "2005 [YR2005]" → 2005

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

country_input = input("Enter country name (Ukraine / United States): ").strip()

if country_input not in data:
    print("No data for this country!")
else:
    plt.figure(figsize=(10, 6))
    plt.bar(years, data[country_input])

    plt.xlabel("Year")
    plt.ylabel("Children out of school, primary")
    plt.title(f"Bar Chart for {country_input}")
    plt.grid(True)
    plt.tight_layout()
    plt.show()
