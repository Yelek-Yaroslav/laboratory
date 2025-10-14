word = input("Введіть слово: ")
word = word.lower()

from collections import Counter
freq = Counter(word)

duplicates = [ch for ch, c in freq.items() if c >= 2]

if not duplicates:
    print("У слові немає літер, що повторюються двічі або більше.")
else:
    print("Знайдені повторювані літери:")
    for ch in duplicates:
        positions = [i+1 for i, x in enumerate(word) if x == ch]
        print(f"'{ch}': кількість = {freq[ch]}, позиції = {positions}")
