from collections import defaultdict

words = [word for word in open("/usr/share/dict/words")]

word_lengths = defaultdict(set)

for word in words:
    word_lengths[len(word)].add(word)

print(word_lengths)

# numbers = [i for i in range(1, 1000)]
# print(numbers)
