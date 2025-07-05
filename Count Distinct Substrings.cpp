//https://www.naukri.com/code360/problems/count-distinct-substrings_985292



// Node class banayi gayi hai Trie banane ke liye
class Node {
public:
    // Har node ke paas 26 characters ke liye jagah hoti hai (a-z)
    Node* links[26] = {NULL};

    // Check karta hai ki current character ke liye koi node already hai ya nahi
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Agar koi node nahi hai to naye node ko uss jagah pe set kar deta hai
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Character ke corresponding node ko return karta hai
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

// Ye function total distinct substrings count karta hai
int countDistinctSubstrings(string &s) {
    Node* root = new Node(); // Trie ka root node banate hain
    int count = 0; // Distinct substrings ka count

    // Har index se substring banana start karenge
    for (int i = 0; i < s.size(); i++) {
        Node* node = root;

        // Har substring ke character check karenge
        for (int j = i; j < s.size(); j++) {
            // Agar character ke liye node exist nahi karta to naye substring mila
            if (!node->containsKey(s[j])) {
                count++; // Count badhao
                node->put(s[j], new Node()); // Naya node insert karo
            }

            // Next character ke liye aage badho
            node = node->get(s[j]);
        }
    }

    return count + 1; // Ek empty string bhi hoti hai isliye +1
}


/*
Trie use karke hum sabhi substrings ko insert karte hain.

Jab bhi naya path banta hai Trie mein, matlab ek naya substring mila.

Har baar nayi node banti hai to count++.

End mein +1 isliye, kyunki empty string bhi ek valid substring hoti hai.
*/
