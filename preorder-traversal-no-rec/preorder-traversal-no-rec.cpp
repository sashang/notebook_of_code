#include <iostream>
#include <stack>

using namespace std;

class BTreeNode
{
    public:
        BTreeNode* left;
        BTreeNode* right;
        int value;
        BTreeNode(BTreeNode* l, BTreeNode* r, int v) :
            left(l), right(r), value(v) { }
};

void preorder_rec(BTreeNode* root)
{
    if (!root)
        return;
    cout << root->value << endl;
    preorder_rec(root->left);
    preorder_rec(root->right);
}

void preorder(BTreeNode* root)
{
    /**
     * recursive preorder is:
     * print value
     * preoreder(left)
     * preorder(right)
     */
    stack<BTreeNode*> nodes;
    nodes.emplace(root);
    while (!nodes.empty())
    {
        BTreeNode* current = nodes.top();
        nodes.pop();
        cout << current->value << endl;
        if (current->right)
            nodes.emplace(current->right);
        if (current->left)
            nodes.emplace(current->left);
    }
}

int main(int argc, char** argv)
{
    BTreeNode root(
            new BTreeNode(
                new BTreeNode(
                    new BTreeNode(nullptr, nullptr, -10),
                    new BTreeNode(nullptr, nullptr, -7),
                    -8),
                new BTreeNode(
                    new BTreeNode(nullptr, nullptr, 2),
                    new BTreeNode(nullptr, nullptr, 11),
                    4),
                20),
            new BTreeNode(
                new BTreeNode(
                    new BTreeNode(nullptr, nullptr, 0),
                    new BTreeNode(nullptr, nullptr, 7),
                    -8),
                new BTreeNode(
                    new BTreeNode(nullptr, nullptr, 112),
                    new BTreeNode(nullptr, nullptr, -9),
                    8),
                201),
            89);
    preorder_rec(&root);
    cout << endl;
    preorder(&root);
}
