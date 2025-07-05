# Trie Data Structure - Complete Implementation Guide

## 📚 Table of Contents
- [What is a Trie?](#what-is-a-trie)
- [Basic Trie Structure](#basic-trie-structure)
- [Applications](#applications)
- [Implementations in this Repository](#implementations-in-this-repository)
- [Complexity Analysis](#complexity-analysis)
- [Visual Diagrams](#visual-diagrams)

## 🌳 What is a Trie?

A **Trie** (pronounced "try") is a tree-like data structure used to store and retrieve strings. The name comes from the word "retrieval." It's also known as a **prefix tree** because it allows efficient prefix-based operations.

### Key Characteristics:
- **Prefix-based**: All descendants of a node have a common prefix
- **Space-efficient**: Shared prefixes are stored only once
- **Fast operations**: O(m) time complexity for search, insert, and delete where m is the string length
- **Ordered**: Can be used to sort strings lexicographically

## 🏗️ Basic Trie Structure

### Node Structure
```cpp
struct Node {
    Node* links[26];          // For 26 lowercase letters (a-z)
    bool flag = false;        // Marks end of word
    int countEndWith = 0;     // Count of words ending at this node
    int countPrefix = 0;      // Count of words with this prefix
};
```

### Basic Operations
1. **Insert**: Add a string to the trie
2. **Search**: Check if a string exists
3. **Delete**: Remove a string from the trie
4. **Prefix Search**: Find all strings with a given prefix

## 🎯 Applications

1. **Autocomplete**: Suggest words as user types
2. **Spell Checker**: Check if words exist in dictionary
3. **IP Routing**: Longest prefix matching
4. **XOR Problems**: Bitwise operations on numbers
5. **String Processing**: Substring counting, pattern matching

## 📁 Implementations in this Repository

This repository contains 5 different Trie implementations solving various algorithmic problems:

### 1. **Implement Trie 2** (`Implement Trie 2.cpp`)
**Problem**: [Naukri.com - Implement Trie](https://www.naukri.com/code360/problems/implement-trie_1387095)

**Features**:
- Complete Trie implementation with insert, search, and delete operations
- Count words equal to a given string
- Count words starting with a given prefix
- Delete words from the trie

**Key Methods**:
```cpp
void insert(string &word)           // Insert a word
int countWordsEqualTo(string &word) // Count exact matches
int countWordsStartingWith(string &word) // Count prefix matches
void erase(string &word)            // Delete a word
```

### 2. **Count Distinct Substrings** (`Count Distinct Substrings.cpp`)
**Problem**: [Naukri.com - Count Distinct Substrings](https://www.naukri.com/code360/problems/count-distinct-substrings_985292)

**Features**:
- Counts all distinct substrings of a given string
- Uses Trie to avoid duplicate counting
- Efficient O(n²) solution where n is string length

**Algorithm**:
- Generate all possible substrings starting from each index
- Insert each substring into Trie
- Count only new paths (new nodes created)

### 3. **Complete String** (`Complete String.cpp`)
**Problem**: [Naukri.com - Complete String](https://www.naukri.com/code360/problems/complete-string_8230849)

**Features**:
- Finds the longest word where all its prefixes are also valid words
- Returns lexicographically smallest if multiple words have same length
- Returns "None" if no valid word found

**Algorithm**:
- Insert all words into Trie
- For each word, check if all its prefixes are valid words
- Select the longest (and lexicographically smallest) valid word

### 4. **Maximum XOR** (`Maximum XOR.cpp`)
**Problem**: 
- [Naukri.com - Maximum XOR](https://www.naukri.com/code360/problems/maximum-xor_973113)
- [LeetCode 421 - Maximum XOR of Two Numbers](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

**Features**:
- Binary Trie for bitwise operations
- Finds maximum XOR between two numbers
- Uses 32-bit representation for integers

**Algorithm**:
- Convert numbers to binary representation
- Insert binary representations into Trie
- For each number, find the path that maximizes XOR (opposite bits)

### 5. **Maximum XOR With Element From Array** (`1707. Maximum XOR With an Element From Array.cpp`)
**Problem**: [LeetCode 1707 - Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/)

**Features**:
- Advanced XOR problem with constraints
- Offline query processing
- Sorted insertion for efficiency

**Algorithm**:
- Sort queries by constraint value
- Insert numbers into Trie as constraints allow
- Process queries in sorted order

## ⏱️ Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert    | O(m)           | O(m)             |
| Search    | O(m)           | O(1)             |
| Delete    | O(m)           | O(1)             |
| Prefix Search | O(m)       | O(1)             |

Where `m` is the length of the string being operated on.

## 🎨 Visual Diagrams

### 1. Basic Trie Structure
```
        Root
       /  |  \
      a   b   c
     /    |    \
    p     a     a
   /      |      \
  p       t       t
 /        |        \
e         e         e
|
s
```

**Example**: Inserting words "app", "bat", "cat", "apple"

### 2. Binary Trie for XOR Operations
```
        Root
       /    \
      0      1
     / \    / \
    0   1  0   1
   / \ / \ / \ / \
  0  1 0 1 0 1 0 1
```

**Example**: Numbers 5 (101), 3 (011), 7 (111) stored in binary Trie

### 3. Trie with Count Information
```
        Root (prefix: 4, end: 0)
       /  |  \
      a   b   c
     /    |    \
    p     a     a
   /      |      \
  p       t       t
 /        |        \
e         e         e
|         |         |
s         s         s
(prefix: 1, end: 1) (prefix: 1, end: 1) (prefix: 1, end: 1)
```

**Example**: Words "app", "bat", "cat", "apple" with prefix and end counts

### 4. Substring Counting Process
```
String: "abc"

Step 1: Start from index 0
Root -> a -> b -> c (count: 3)

Step 2: Start from index 1  
Root -> b -> c (count: 2)

Step 3: Start from index 2
Root -> c (count: 1)

Total distinct substrings: 6 + 1 (empty string) = 7
```

## 🚀 Usage Examples

### Basic Trie Operations
```cpp
Trie trie;
trie.insert("apple");
trie.insert("app");
trie.insert("bat");

cout << trie.countWordsEqualTo("app");     // Output: 1
cout << trie.countWordsStartingWith("ap"); // Output: 2
trie.erase("app");
```

### XOR Operations
```cpp
Trie trie;
trie.insert(5);  // 101 in binary
trie.insert(3);  // 011 in binary
trie.insert(7);  // 111 in binary

int maxXor = trie.getMax(6);  // Find max XOR with 6
```

## 🔧 Key Implementation Details

### 1. Character Mapping
```cpp
// For lowercase letters (a-z)
int index = ch - 'a';  // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25

// For binary digits (0-1)
int index = bit;  // 0 -> 0, 1 -> 1
```

### 2. Bitwise Operations for XOR
```cpp
// Extract i-th bit
int bit = (num >> i) & 1;

// Set i-th bit
maxNum |= (1 << i);

// Opposite bit
int oppositeBit = 1 - bit;
```

### 3. Memory Management
- Each node uses dynamic allocation
- Consider using smart pointers for production code
- Implement destructor for proper cleanup

## 🎯 Problem-Solving Patterns

### 1. String Problems
- Use character-based Trie (26 children per node)
- Track end-of-word flags
- Count prefixes and exact matches

### 2. Bitwise Problems
- Use binary Trie (2 children per node)
- Process bits from most significant to least significant
- Use opposite bits for maximum XOR

### 3. Constraint Problems
- Sort queries/constraints
- Process in order
- Insert elements as constraints allow

## 📝 Best Practices

1. **Memory Efficiency**: Use arrays instead of maps for fixed character sets
2. **Time Efficiency**: Process bits/characters in optimal order
3. **Code Clarity**: Separate node operations from Trie operations
4. **Error Handling**: Check for null pointers and invalid inputs
5. **Testing**: Test with edge cases (empty strings, single characters, etc.)

