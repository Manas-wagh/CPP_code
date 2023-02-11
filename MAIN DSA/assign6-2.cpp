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

node *insertkey(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }
    else if (root->data > key)
    {
        root->left = insertkey(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insertkey(root->right, key);
    }

    return root;
}

node *find_sucessor(node *root)
{

    node *temp = root->right;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *deletekey(node *root, int key)
{

    if (root == NULL)
    {
        return root;
    }

    else if (root->data > key)
    {
        root->left = deletekey(root->left, key);
    }

    else if (root->data < key)
    {
        root->right = deletekey(root->right, key);
    }

    else
    {
        // cout << "1" << endl;
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete (root);
            return temp;
        }

        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete (root);
            return temp;
        }

        else
        {
            node *succescor = find_sucessor(root);
            root->data = succescor->data;
            root->right = deletekey(root->right, succescor->data);
        }
    }
    return root;
}

int main()
{

    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertkey(root, x);
    }

    inorder_traversal(root);
    cout << endl;

    root = deletekey(root, 4);

    inorder_traversal(root);
    // cout << root->data;

    return 0;
}