struct Node 
{
    Node* links[26]; // For 26 lowercase letters a-z
    bool flag = false; // True means this is the end of a valid word

    // Checks if there is a path (node) for the given character
    bool containsKey(char ch) 
    {
        return links[ch - 'a'] != NULL;
    }

    // Creates a new node path for the character
    void put(char ch, Node* node) 
    {
        links[ch - 'a'] = node;
    }

    // Returns the next node (child) for the character
    Node* get(char ch) 
    {
        return links[ch - 'a'];
    }

    // Marks this node as the end of a word
    void setEnd() 
    {
        flag = true;
    }

    // Checks if this node is the end of a word
    bool isEnd() 
    {
        return flag;
    }
};

// Trie class that uses Node to store words
class Trie 
{
private:
    Node* root; // Starting node of the Trie

public:
    // Constructor: creates the root node
    Trie() 
    {
        root = new Node();
    }

    // Inserts a word into the Trie
    void insert(string word) 
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) 
        {
            // If the current character doesn't exist, create it
            if (!node->containsKey(word[i])) 
            {
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    // Searches for a word in the Trie
    bool search(string word) 
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) 
        {
            // If the current character doesn't exist, word not found
            if (!node->containsKey(word[i])) 
            {
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if this is the end of a valid word
        return node->isEnd();
    }

    // Checks if any word starts with the given prefix
    bool startsWith(string prefix) 
    {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) 
        {
            // If the current character doesn't exist, prefix not found
            if (!node->containsKey(prefix[i])) 
            {
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // All characters of prefix found
        return true;
    }
};
