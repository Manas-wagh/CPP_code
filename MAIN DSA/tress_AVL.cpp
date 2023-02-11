/*
What are AVL trees?
AVL trees are height balanced binary search trees. Because most of the operations work on O(h), we would want the value of h to be minimum possible, which is log(n).
Height difference between the left and the right subtrees is less than 1 or equal in an AVL tree.
For AVL trees, there is a balance factor BF, which is equal to the height of the left subtree subtracted from the height of the right subtree. If we consider the below binary search tree, you can see the balance factor mentioned beside each node. Carefully observe each of those.
*/