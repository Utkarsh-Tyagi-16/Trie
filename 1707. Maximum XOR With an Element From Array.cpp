// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

//1707. Maximum XOR With an Element From Array leetcode question 


// Trie Node banane ke liye class
class Node {
public:
    Node* links[2]; // 0 aur 1 ke liye pointers

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

// Trie class jisme hum numbers ko bitwise store karenge
class Trie {
private:
    Node* root;

public:
    // Constructor me root node initialize karte hain
    Trie() {
        root = new Node();
    }

    // Number ko Trie me insert karte hain
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // har bit nikal rahe hain
            if (!node->containsKey(bit)) {
                node->put(bit, new Node()); // agar bit nahi hai to new node banate hain
            }
            node = node->get(bit); // aage move karte hain
        }
    }

    // Diye gaye number ke saath maximum XOR find karte hain
    int getMaxXor(int num) {
        Node* node = root;
        if (!node) return -1;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // opposite bit mile to use le lo (XOR badh jayega)
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit); // warna wahi bit le lo
            }
        }
        return maxXor;
    }
};

// Main Solution class
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1); // sab queries ka answer -1 se initialize

        // nums ko chhote se bade order me sort karte hain
        sort(nums.begin(), nums.end());

        // Queries ke sath unka index store karte hain
        vector<tuple<int, int, int>> offlineQueries;
        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back(make_tuple(queries[i][1], queries[i][0], i)); // (mi, xi, index)
        }

        // Queries ko mi ke basis par sort karte hain
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        int idx = 0;

        // Har query ko process karte hain
        for (auto &[mi, xi, qIndex] : offlineQueries) {
            // Jab tak nums[idx] ≤ mi ho, use Trie me insert karo
            while (idx < nums.size() && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }

            // Agar Trie me koi number insert hua ho to max XOR find karo
            if (idx > 0) {
                ans[qIndex] = trie.getMaxXor(xi);
            }
            // Agar Trie empty hai to answer -1 hi rahega
        }

        return ans; // final answers return karte hain
    }
};


