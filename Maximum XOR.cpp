// https://www.naukri.com/code360/problems/maximum-xor_973113

//Maximum XOR  Coding ninjas Problem 

// iss problem mai 2 array given hai 

// Node class har bit ke liye child pointer rakhta hai (0 aur 1)
struct Node {
    Node* links[2];

    // Check karta hai ki bit present hai ya nahi
    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    // bit ke corresponding node return karta hai
    Node* get(int bit) {
        return links[bit];
    }

    // bit ke liye new node set karta hai
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

// Trie class banate hain jisme root node hoti hai
class Trie {
private:
    Node* root;

public:
    // Constructor me root node create karte hain
    Trie() {
        root = new Node();
    }

    // Number ko Trie me insert karte hain
    void insert(int num) {
        Node* node = root;
        // 32 bit ke number ke liye loop chalate hain
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Agar bit ke liye node nahi hai to create karo
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            // Next node me move karo
            node = node->get(bit);
        }
    }

    // Maximum XOR find karne ke liye function
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Agar opposite bit milta hai to maxNum me 1 set kar do
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                // Warna same bit ke path me jao
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// Do arrays ke beech maximum XOR find karne ka function
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie trie;
    // Pehle array1 ke sare numbers Trie me insert karo
    for (auto &it : arr1) {
        trie.insert(it);
    }

    int maxi = 0;
    // Array2 ke har number ke liye maximum XOR find karo
    for (auto &it : arr2) {
        maxi = max(maxi, trie.getMax(it));
    }

    return maxi;
}








// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

// 421. Maximum XOR of Two Numbers in an Array  LeetCode Problem 



class Node {
public:
    Node* links[2]; // 0 aur 1 dono bit ke liye pointer

    // Check karta hai ki bit already exist karti hai ya nahi
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    // bit ke corresponding node return karta hai
    Node* get(int bit) {
        return links[bit];
    }

    // bit ke corresponding node set karta hai
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    // Constructor me root node create karte hain
    Trie() {
        root = new Node();
    }

    // Number ko Trie me insert karte hain
    void insert(int num) {
        Node* node = root;
        // 31 se 0 tak har bit ko insert karte hain (total 32 bits)
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // i-th bit nikalte hain
            if (!node->containsKey(bit)) {
                node->put(bit, new Node()); // agar bit nahi hai to new node banao
            }
            node = node->get(bit); // next node me move karo
        }
    }

    // Diye gaye number ke saath maximum XOR nikalte hain
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // i-th bit nikalte hain
            // Opposite bit agar mil jaye to wahi choose karo
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i); // maxNum me 1 set kar do is position pe
                node = node->get(1 - bit); // opposite bit wale path me jao
            } else {
                node = node->get(bit); // warna same bit wale path me jao
            }
        }
        return maxNum; // final XOR value return karo
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        // Sabhi numbers ko Trie me insert karo
        for (int num : nums) {
            trie.insert(num);
        }

        int maxXor = 0;

        // Har number ke liye maximum XOR nikalte hain
        for (int num : nums) {
            maxXor = max(maxXor, trie.getMax(num));
        }

        return maxXor; // sabse bada XOR value return karo
    }
};


