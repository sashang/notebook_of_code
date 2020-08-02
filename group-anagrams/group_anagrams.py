import collections

def hashkey(w):
    arr = [0] * 26
    for x in w:
        arr[ord(x) - ord('a')] += 1
    return tuple(arr)

def group_anagrams(words):
    groups = collections.defaultdict(list)
    for x in words:
        groups[hashkey(x)].append(x)

    return tuple(groups.values())

l = ["abc","cad", "bac", "aakde", "akdee", "fed", "kaade",  "def"]
print(group_anagrams(l))