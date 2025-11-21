word=input("enter a word:").lower()
freq={}
for ch in word:
    if ch.isalpha():
        freq[ch]=freq.get(ch,0)+1
        print("freq of alphabet: ",freq)
names=input("enter first names: ").split()
count_a=sum(1 for names in names if names.lower().startswith('a'))
print("Num of names:",count_a)
line=input("enter a line of text: ")
words = line.split()
print("words in line: ")
for w in words:print(w)
