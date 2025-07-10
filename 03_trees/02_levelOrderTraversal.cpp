#include <iostream>
#include <queue>
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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " -> ";
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    cout << "end" << endl;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    return 0;
}
