#include <bits/stdc++.h>
using namespace std;

//  tree is a non linear data structure
//  if tree has n nodes it has n-1 edges
//  total number of direct childs is called degree
//  depth is total number of nodes above the interested node
//  height is total number of nodes below the interested node
//  degree of tree- highest degree
//  binary tree- tree with each node having degree<=2

//..................................types of binary tress(bt)............................//

//.1. full/strict bt
//---->each node have either 0 or 2 childs

//.2. perfect bt
//---->each node has exactly 2 childs and all leaves are at same level

//.3. complete bt
//---->all levels are completely filled except teh last level + last lvl must have its keys as left allign as possible

//.4.degenerate tree
//---->every parent node has exactly one child......futhur classified as left skewed(all child in left) and right skewed.

//.5.BST-binary search tree=..data at left < node < right...and this should happen for all nodes.
//  ..fayde of bst..      1. helps to remove duplicacy..since we dont allow equal to sign.
//                        2. inorder traversal of bst gives ascending sorted array.

//

//...................................deletion in bst........................................//
//...case-1: node is leaf node : direct search and delete
/*...case-2: node is non leaf node(including root):
.            ->search for node
.            ->find inorder predessesor and successor using danda method
.            ->keep replacing and until we have no empty nodes    */

int main()
{
    return 0;
}