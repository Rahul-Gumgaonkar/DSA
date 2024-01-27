#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childrenCount;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childrenCount = 0;
    }
};

void insertNode(TrieNode *root, string word)
{

    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
        root->childrenCount++;
    }
    insertNode(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{

    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    return searchWord(child, word.substr(1));
}

void deleteNode(TrieNode *root, string word)
{

    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }

    deleteNode(child, word.substr(1));
}
void storeSuggestion(TrieNode *curr, vector<string> &temp, string &prefix)
{
    if (curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = curr->children[index];
        if (next != NULL)
        {
            prefix.push_back(ch);
            storeSuggestion(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestion(TrieNode *root, string input)
{
    vector<vector<string>> output;

    if (input.length() == 0)
    {
        return output;
    }

    TrieNode *prev = root;
    string prefix = "";

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        int index = ch - 'a';
        TrieNode *curr = prev->children[index];
        if (curr == NULL)
        {
            break;
        }
        else
        {
            prefix.push_back(ch);
            vector<string> temp;
            storeSuggestion(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main()
{

    // TrieNode *root = new TrieNode('\0');
    // insertNode(root, "love");
    // insertNode(root, "lover");
    // insertNode(root, "loving");
    // insertNode(root, "loved");

    // if (searchWord(root, "love"))
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "NotFound" << endl;
    // }

    // deleteNode(root, "love");
    // if (searchWord(root, "love"))
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "NotFound" << endl;
    // }

    TrieNode *root = new TrieNode('\0');
    vector<string> value;
    value.push_back("love");
    value.push_back("loving");
    value.push_back("lover");
    value.push_back("lane");
    value.push_back("last");
    value.push_back("lost");
    value.push_back("lord");

    string input = "lovi";

    for (int i = 0; i < value.size(); i++)
    {
        insertNode(root, value[i]);
    }

    vector<vector<string>> output = getSuggestion(root, input);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}