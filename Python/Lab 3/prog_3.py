sentence = input("Введіть речення: ")
sentence = sentence.lower()
words = sentence.split()

count = 0
for word in words:
    if word.startswith('н'):
        count += 1

print("Кількість слів, які починаються з літери 'н':", count)
