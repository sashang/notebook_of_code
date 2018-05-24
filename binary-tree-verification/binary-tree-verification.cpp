
#include <iostream>
#include <stack>
#include <limits>

using namespace std;

class BinaryTreeNode
{
public:
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int value) :
		value(value),
		left(nullptr),
		right(nullptr)
	{
	}

	~BinaryTreeNode()
	{
		delete left;
		delete right;
	}

	BinaryTreeNode * insertLeft(int value)
	{
		this->left = new BinaryTreeNode(value);
		return this->left;
	}

	BinaryTreeNode * insertRight(int value)
	{
		this->right = new BinaryTreeNode(value);
		return this->right;
	}

	int get_val() const { return value; }
	BinaryTreeNode* get_left() const { return left;  }
	BinaryTreeNode* get_right() const { return right; }
};

class NodeBound
{
    public:
        const BinaryTreeNode* node;
        int upper_bound;
        int lower_bound;

        NodeBound(const BinaryTreeNode* n, int upper, int lower):
            node(n), upper_bound(upper), lower_bound(lower)
        {}
};

bool is_valid(const BinaryTreeNode* root)
{
	if (root == nullptr)
		return true;

    stack<NodeBound> s;
    NodeBound root_bound(root, std::numeric_limits<int>::max(), std::numeric_limits<int>::min());

    s.emplace(root_bound);

    while (!s.empty())
    {
        NodeBound current = s.top();
        s.pop();
        if (current.node->value > current.upper_bound || current.node->value < current.lower_bound)
        {
            cout << "value = " << current.node->value << " lower_bound = " << current.lower_bound << ", upper_bound " << current.upper_bound << endl;
            return false;
        }

        if (current.node->left)
        {
            NodeBound left_bound(current.node->left, current.node->value, current.lower_bound);
            s.emplace(left_bound);
        }
        if (current.node->right)
        {
            NodeBound right_bound(current.node->right, current.upper_bound, current.node->value);
            s.emplace(right_bound);
        }
    }
    return true;
}

int main()
{
	BinaryTreeNode* root = new BinaryTreeNode(10);
	BinaryTreeNode* right = root->insertRight(11);
	BinaryTreeNode* left = root->insertLeft(2);

    right->insertRight(20);
    right->insertLeft(-1);


	if (is_valid(root))
		cout << "valid" << endl;
	else
		cout << "not valid" << endl;
	cin.get();

    return 0;
}

