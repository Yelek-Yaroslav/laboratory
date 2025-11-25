import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("comptage_velo_2011.csv", encoding="utf-8", sep=",")
df = df.drop(columns=[df.columns[1]])  # видаляємо зайвий стовпець
df.columns = df.columns.str.replace(r"[^A-Za-z0-9_/]", "", regex=True).str.strip()

print("Перші 5 рядків датафрейму:\n")
print(df.head())

print("\nІнформація про датафрейм:\n")
print(df.info())

print("\nСтатистичні характеристики:\n")
print(df.describe())

df["Date"] = pd.to_datetime(df["Date"], format="%d/%m/%Y")
df = df.set_index("Date")

df["Month"] = df.index.month
df["Month_name"] = df.index.month_name()

bike_cols = df.columns.drop(["Month", "Month_name"])
df[bike_cols] = df[bike_cols].apply(pd.to_numeric, errors="coerce")

total_year = df[bike_cols].sum().sum()
print(f"\nЗагальна кількість велосипедистів за рік: {total_year}")

total_by_lane = df[bike_cols].sum()
print("\nЗагальна кількість велосипедистів по велодоріжках:")
print(total_by_lane)

print("\nНайпопулярніший місяць для перших трьох велодоріжок:")
for lane in bike_cols[:3]:
    monthly = df.groupby("Month")[lane].sum()
    best_month_name = df.loc[df["Month"] == monthly.idxmax(), "Month_name"].iloc[0]
    print(f"{lane}: {best_month_name}")

plt.figure(figsize=(12, 6))
df[bike_cols].plot(ax=plt.gca())
plt.xlabel("Дата")
plt.ylabel("Кількість велосипедистів")
plt.title("Щоденна кількість велосипедистів по всіх велодоріжках")
plt.legend(title="Велодоріжка", loc="upper left")
plt.grid(True)
plt.show()

lane = bike_cols[0]
monthly_counts = df.groupby("Month")[lane].sum()

plt.figure(figsize=(10, 5))
plt.plot(monthly_counts.index, monthly_counts.values, marker='o')
plt.xlabel("Місяць")
plt.ylabel("Кількість велосипедистів")
plt.title(f"Місячна активність на велодоріжці '{lane}'")
plt.grid(True)
plt.show()
