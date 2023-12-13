# Auto Suggest Program using Trie Data Structure

![image](https://github.com/Avadhesh817/Auto-Suggest-Program-using-Trie-data-structure/assets/95118796/a0d260a1-590e-44fa-82dd-16d37b86a87a)


This program implements an auto-suggest feature using a Trie data structure to efficiently retrieve suggestions based on a given prefix. It reads words from a file (`wordlist.txt`) and provides suggestions for words starting with the given prefix.

## Algorithm

The core algorithm utilizes a Trie data structure, a tree-like data structure used for efficient retrieval of a key in a dataset of strings. In this program:

- The `TrieNode` struct represents each node in the Trie, with an array of children nodes and a boolean flag to mark the end of a word.
- `insert` function inserts words into the Trie by traversing through the characters of the word.
- `search` function finds the node corresponding to the given prefix and calls `traverseTrie` to collect suggestions.
- `traverseTrie` recursively traverses the Trie to collect all words that match the given prefix.

## Complexity

- Inserting a word into the Trie takes O(m) time, where m is the length of the word.
- Searching for suggestions for a given prefix takes O(n + m*k) time:
  - n is the number of nodes in the Trie.
  - k is the average number of children per node.
  - m is the length of the longest word with the given prefix.

## File Structure

- `auto_suggest.cpp`: Contains the C++ code for the auto-suggest program.
- `wordlist.txt`: Input file containing a list of words.

## Sample Input

The `wordlist.txt` file should contain words, each on a new line, representing the dictionary used to generate suggestions.

