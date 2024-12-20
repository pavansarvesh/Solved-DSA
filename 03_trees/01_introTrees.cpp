#include <iostream>
// #include <vector>
using namespace std;

class node
{
public:
    int data;
    node *right, *left;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter data : ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << " Enter data for the left of node of " << data << endl;
    root->left = buildTree(root->left);

    cout << " Enter data for the right node of" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    return 0;
}
