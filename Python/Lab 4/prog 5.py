def search():
    A = input("Enter a text: ")
    B = A.lower()
    print("Text:", B)

    vowels = set('aeiouy')
    consonants = set('abcdefghijklmnopqrstuvwxyz') - vowels

    letters = set(ch for ch in B if ch.isalpha())

    vowels_in_text = letters & vowels
    consonants_in_text = letters & consonants

    vowels_count = sum(1 for ch in B if ch in vowels)
    consonants_count = sum(1 for ch in B if ch in consonants)

    # вивід
    print("Множина літер:", *sorted(letters))
    print("Голосні у тексті:", *sorted(vowels_in_text))
    print("Приголосні у тексті:", *sorted(consonants_in_text))

    if vowels_count > consonants_count:
        print(f"У тексті більше голосних літер: {vowels_count} > {consonants_count}")
    elif vowels_count < consonants_count:
        print(f"У тексті більше приголосних літер: {consonants_count} > {vowels_count}")
    else:
        print(f"Кількість голосних і приголосних однакова: {vowels_count}")

search()