#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node()
    {
        right = NULL;
        left = NULL;
    }
    node(int d)
    {
        right = NULL;
        left = NULL;
        data = d;
    }
};
//--PREORDER TRAVERSAL-root->leftsub tree->rightsub tree
void pretraversal(node *ele)
{
    if (ele != NULL)
    {
        cout << ele->data << " ";
        pretraversal(ele->left);
        pretraversal(ele->right);
    }
    else
    {
    }
}
//--IN ORDER TRAVERSAL-leftsub tree->root->rightsub tree

void intraversal(node *ele)
{
    if (ele != NULL)
    {

        intraversal(ele->left);
        cout << ele->data << " ";
        intraversal(ele->right);
    }
    else
    {
    }
}

//--POSTORDER TRAVERSAL-leftsub tree->rightsub tree->root

void posttraversal(node *ele)
{
    if (ele != NULL)
    {

        posttraversal(ele->left);
        posttraversal(ele->right);
        cout << ele->data << " ";
    }
    else
    {
    }
}

// checking if tree is bst or not;

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

// recursive search of an element in tree

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
}

// iterative search

node *itersearch(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (root == NULL)
    {
        return NULL;
    }
}

// insertion

void insert(node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "element cant be inserted" << endl;
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node *newele = new node(key);
    if (key < prev->data)
    {
        prev->left = newele;
    }
    else
    {
        prev->right = newele;
    }
}

// inorder predecessor

node *inOrderPredecessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
// inorder Succesor

node *inOrderSuccesor(node *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// deletion

node *deletenode(node *root, int val)
{
    node *inopre;
    if (root == NULL)
    {
        cout << "element not found in tree" << endl;
        return NULL;
    }
    else
    {
        if (root->left == NULL && root->right == NULL && root->data == val)
        {
            free(root);
            cout << "element deleted" << endl;
            return NULL;
        }
    }

    if (val < root->data)
    {
        root->left = deletenode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deletenode(root->right, val);
    }
    else
    {
        inopre = inOrderPredecessor(root);
        root->data = inopre->data;
        root->left = deletenode(root->left, inopre->data);
    }
    return root;
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
            node *succescor = inOrderSuccesor(root);
            root->data = succescor->data;
            root->right = deletekey(root->right, succescor->data);
        }
    }
    return root;
}

int main()
{
    node *root = new node(7);
    node *a1 = new node(5); ///---first row a, 2nd wli b and so on.....sabse upar wala root
    node *a2 = new node(9);
    node *a1b1 = new node(3);
    node *a1b2 = new node(6);
    node *b1c1 = new node(2);
    node *b1c2 = new node(4);

    root->left = a1;
    root->right = a2;
    a1->left = a1b1;
    a1b1->left = b1c1;
    a1b1->right = b1c2;

    pretraversal(root);
    cout << endl;
    posttraversal(root);
    cout << endl;
    intraversal(root);
    cout << endl;

    //

    int ans = isBST(root);
    if (ans == 1)
    {
        cout << "it is bst" << endl;
    }
    else
    {
        cout << "it is not bst" << endl;
    }

    //

    node *output = search(root, 3);
    if (output == NULL)
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << "present he" << endl;
    }

    //

    node *out = search(root, 3);
    if (out == NULL)
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << "present he" << endl;
    }

    //

    insert(root, 10);
    intraversal(root);
    cout << endl;
    insert(root, 8);
    intraversal(root);
    cout << endl;

    //

    deletekey(root, 1);
    intraversal(root);
    cout << endl;

    return 0;
}