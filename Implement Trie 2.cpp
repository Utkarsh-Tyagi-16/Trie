//https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=SUBMISSION

 Implement Trie 2


#include <bits/stdc++.h>
using namespace std;

// Node structure jo Trie ka ek node represent karta hai
struct Node {
    Node* links[26];          // 26 letters ke liye pointers (a-z)
    int CountEndWith = 0;     // Kitne words is node par khatam hote hain
    int CountPrefix = 0;      // Kitne words is node tak prefix ke roop mein aate hain

    // Check karta hai ki current character ka link exist karta hai ya nahi
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // Current character ke corresponding node return karta hai
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Naya node current character ke liye set karta hai
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Jab koi word is node par end hota hai tab count badha dete hain
    void increaseEnd() {
        CountEndWith++;
    }

    // Jab koi word is node se ho kar guzarta hai to prefix count badha dete hain
    void increasePrefix() {
        CountPrefix++;
    }

    // Jab word delete karte hain to end count kam kar dete hain
    void deleteEnd() {
        CountEndWith--;
    }

    // Jab word delete karte hain to prefix count bhi kam karte hain
    void reducePrefix() {
        CountPrefix--;
    }

    // Is node par kitne words end hote hain, uska count return karta hai
    int getEnd() {
        return CountEndWith;
    }

    // Is node tak kitne words prefix ke roop mein aaye hain, uska count return karta hai
    int getPrefix() {
        return CountPrefix;
    }
};

// Trie class jo multiple words ko store karne ke liye use hoti hai
class Trie {
private:
    Node* root; // Root node of Trie

public:
    Trie() {
        root = new Node(); // Root node initialize kar diya
    }

    // Ek word ko Trie mein insert karta hai
    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node()); // Agar link nahi hai to naya node bana kar link karo
            }
            node = node->get(word[i]); // Next character ke node par chale jao
            node->increasePrefix();    // Prefix count badhao
        }
        node->increaseEnd(); // Word yahan khatam ho raha hai to end count badhao
    }

    // Ek word ke equal hone wale words ka count batata hai
    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0; // Word exist nahi karta
            }
        }
        return node->getEnd(); // Kitni baar yeh word insert kiya gaya tha
    }

    // Jo words kisi prefix se start hote hain unka count batata hai
    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]); // Next node par jao
            } else {
                return 0; // Prefix match nahi hua
            }
        }
        return node->getPrefix(); // Kitne words is prefix se start hote hain
    }

    // Kisi word ko Trie se hataata hai
    void erase(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix(); // Prefix count kam karo
            } else {
                return; // Word exist hi nahi karta
            }
        }
        node->deleteEnd(); // End count kam karo kyunki word delete ho gaya
    }
};
