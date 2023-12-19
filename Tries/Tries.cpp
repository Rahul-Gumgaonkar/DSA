#include <iostream>

using namespace std;

class TreeNode
{
public:
    char data;
    TreeNode *children[26];
    bool isTerminal;

    TreeNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insertNode(TreeNode *root, string word)
{

    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char d = word[0];
    int index = d - 'a';
    TreeNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TreeNode(d);
        root->children[index] = child;
    }

    insertNode(child, word.substr(1));
}

bool searchWord(TreeNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char d = word[0];
    int index = d - 'a';
    TreeNode *child;

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

void deleteNode(TreeNode *root, string word)
{

    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char d = word[0];
    int index = d - 'a';
    TreeNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }

    deleteNode(child, word.substr(1));
}

int main()
{

    TreeNode *root = new TreeNode('-');

    insertNode(root, "coding");
    insertNode(root, "code");
    insertNode(root, "coder");
    insertNode(root, "codehelp");
    insertNode(root, "babbar");
    insertNode(root, "baby");
    insertNode(root, "baba");
    insertNode(root, "badboy");

    if (searchWord(root, "code"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    deleteNode(root, "code");

    if (searchWord(root, "code"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    return 0;
}
