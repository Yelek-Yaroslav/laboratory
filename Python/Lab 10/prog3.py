import json
import matplotlib.pyplot as plt

FILENAME = "result.json"

with open(FILENAME, "r", encoding="utf-8") as file:
    data = json.load(file)

countries = list(data.keys())
populations = [data[country]["населення"] for country in countries]

def make_autopct(values):
    def autopct(pct):
        total = sum(values)
        val = pct * total / 100
        return f"{val:.1f} млн\n({pct:.1f}%)"
    return autopct

plt.figure(figsize=(8, 8))
plt.pie(
    populations,
    labels=countries,
    autopct=make_autopct(populations),
    startangle=90,
    shadow=True
)

plt.title("Розподіл населення країн (млн та у %)")
plt.axis("equal")
plt.show()
