import nltk
from nltk.corpus import gutenberg, stopwords
from nltk.probability import FreqDist
import string
import matplotlib.pyplot as plt

# nltk.download('gutenberg')
# nltk.download('punkt')
# nltk.download('stopwords')

text = gutenberg.raw('austen-sense.txt')
tokens = nltk.word_tokenize(text)
print("Total words (tokens):", len(tokens))

tokens_no_punct = [word.lower() for word in tokens if word.isalpha()]

freq_no_punct = FreqDist(tokens_no_punct)
top10_no_punct = freq_no_punct.most_common(10)

print("\nTop 10 frequent words (without punctuation):")
print(top10_no_punct)

plt.figure(figsize=(10, 5))
plt.bar([word for word, freq in top10_no_punct], [freq for _, freq in top10_no_punct])
plt.title("Top 10 Most Frequent Words (without punctuation)")
plt.xlabel("Word")
plt.ylabel("Frequency")
plt.show()

stop_words = set(stopwords.words('english'))
punct = set(string.punctuation)

cleaned_tokens = [
    word.lower() for word in tokens
    if word.lower() not in stop_words
    and word.isalpha()
]

cleaned_freq = FreqDist(cleaned_tokens)
top10_clean = cleaned_freq.most_common(10)

print("\nTop 10 frequent words (cleaned text - no stopwords & punctuation):")
print(top10_clean)

plt.figure(figsize=(10, 5))
plt.bar([word for word, freq in top10_clean], [freq for _, freq in top10_clean])
plt.title("Top 10 Most Frequent Words (Cleaned Text)")
plt.xlabel("Word")
plt.ylabel("Frequency")
plt.show()
