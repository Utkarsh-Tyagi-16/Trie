//https://www.naukri.com/code360/problems/complete-string_8230849


#include <bits/stdc++.h>
using namespace std;

// Node class har character ke liye ek node ko represent karta hai
struct Node {
    Node* links[26]; // 'a' to 'z' tak ke 26 characters ke liye pointers
    bool flag = false; // ye batata hai ki word yahin end hota hai ya nahi

    // check karta hai ki current character ka node exist karta hai ya nahi
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // current character ka node return karta hai
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // current character ke liye new node set karta hai
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // jab word yaha end hota hai tab flag ko true set kar dete hai
    void setEnd() {
        flag = true;
    }

    // check karta hai ki kya ye node kisi word ka end hai
    bool isEnd() {
        return flag;
    }
};

// Trie class jismein root node se words insert aur check kiye jaate hai
class Trie {
private:
    Node* root;

public:
    // Constructor jismein root node initialize hota hai
    Trie() {
        root = new Node();
    }

    // word ko trie mein insert karta hai
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            // agar current character ka node nahi hai to new node banao
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            // next character ke node pe move karo
            node = node->get(word[i]);
        }
        // word end hone pe flag true set karo
        node->setEnd();
    }

    // check karta hai ki word ke har prefix pehle se trie mein maujood hai ya nahi
    bool checkIfPrefix(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            // agar character exist karta hai to next node pe jao
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                // agar current tak ka prefix end nahi hota to false return karo
                if (!node->isEnd()) return false;
            } else {
                // agar character exist hi nahi karta to false return karo
                return false;
            }
        }
        // agar sab prefix exist karte hain to true return karo
        return true;
    }
};

// main function jo longest word return karta hai jiske saare prefix bhi trie mein hon
string completeString(int n, vector<string> &a) {
    Trie trie;
    
    // pehle saare words ko trie mein insert karo
    for (auto &it : a) {
        trie.insert(it);
    }

    string longest = "";
    
    // har word ke liye check karo ki kya uske saare prefix exist karte hain
    for (auto &it : a) {
        if (trie.checkIfPrefix(it)) {
            // agar word lamba hai to update karo
            if (it.length() > longest.length()) {
                longest = it;
            }
            // agar length barabar hai to lexicographically smaller word choose karo
            else if (it.length() == longest.length() && it < longest) {
                longest = it;
            }
        }
    }

    // agar koi bhi valid word nahi mila to "None" return karo
    if (longest == "") return "None";
    return longest;
}



/*
Saare words ko insert karta hai trie mein.

Fir check karta hai kaunsa word aisa hai jiske har prefix bhi ek valid word ho.

Aisa sabse longest (aur agar tie ho to lexicographically smallest) word return karta hai.

Agar koi nahi mila to "None" return karta hai.
*/
