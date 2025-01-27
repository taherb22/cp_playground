# Python Program to find the Longest Common Prefix 
# of the given strings using Trie
class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.childCount = 0
        self.isLeaf = False

# If not present, inserts the key into the trie
# If the key is a prefix of trie node, just mark leaf node
def insert(root, key):
    curr = root
    for ch in key:
        idx = ord(ch) - ord('a')
        if curr.children[idx] is None:
            curr.children[idx] = TrieNode()
            curr.childCount += 1

        curr = curr.children[idx]

    # mark last node as leaf
    curr.isLeaf = True

# Perform a walk on the trie and return the
# longest common prefix string
def walkTrie(root, s):
    curr = root
    i = 0
    
    while curr.childCount == 1 and not curr.isLeaf:
        idx = ord(s[i]) - ord('a')
        i += 1
        curr = curr.children[idx]

    return s[:i]

# A Function that returns the longest common prefix
# from the array of strings
def longestCommonPrefix(arr):
    root = TrieNode()

    # Insert all strings to the trie
    for s in arr:
        insert(root, s)

    # Perform a walk on the trie
    return walkTrie(root, arr[0])

if _name_ == "_main_":
    arr = ["geeksforgeeks", "geeks", "geek", "geezer"]
    print(longestCommonPrefix(arr))