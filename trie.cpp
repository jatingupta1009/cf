class TrieNode
{
    public:
    TrieNode* children[26];
    int isEnd;

    public:
    TrieNode()
    {
        for(int i=0; i<26; i++) children[i]= NULL;
        isEnd= 0;
    }
};

class Trie
{
    public:
    TrieNode* root;
    public:
    Trie()
    {
        root= new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* node= root;
        for(auto ele: word)
        {
            int index= ele-'a';

            if(node->children[index]==0) node->children[index]= new TrieNode();
            node= node->children[index];
        }

        node->isEnd=1;
    }

    int search(string word)
    {
        TrieNode* node= root;
        for(auto ele: word)
        {
            int index= ele-'a';

            if(node->children[index]==0) return 0;

            node= node->children[index];
        }

        return node->isEnd;
    }
    
    int prefix(string word)
    {
        TrieNode* node= root;   
        for(auto ele: word)
        {
            int index= ele-'a';

            if(node->children[index]==0) return 0;

            node= node->children[index];
        }
        return 1;
    }
};
