#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;

    node()
    {
        data = 0;
        right = NULL;
        left = NULL;
    }

    node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

void inorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
void preorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);

    preorder_traversal(root->right);
}

void postorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder_traversal(root->left);

    postorder_traversal(root->right);

    cout << root->data << " ";
}

int main()
{
    // Contrust the Tree
    //      4
    //     /  \
    //    3    2
    //   / \    
    //  1   6

    class node *root = new node(4);
    root->left = new node(3);
    root->right = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(6);

    cout << "Preorder traversal of binary tree is " << endl;
    preorder_traversal(root);
    cout << endl;

    cout << "Inorder traversal of binary tree is " << endl;
    inorder_traversal(root);
    cout << endl;

    cout << "Postorder traversal of binary tree is " << endl;
    postorder_traversal(root);
    cout << endl;

    return 0;
}