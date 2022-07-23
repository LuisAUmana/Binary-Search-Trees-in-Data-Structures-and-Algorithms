#include <iostream>
#include "bst.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{  
   root = nullptr;
}
   
void BinarySearchTree::insert(int key, string val) 
{  
   Node* new_node = new Node;
   new_node->key = key;
   new_node->val = val;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { 
      root = new_node; 
   } else { 
      insertHelper(root, new_node); 
   }
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node) 
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node); }
   }
   else if (new_node->key > parent->key) {  
      if (parent->right == nullptr) {
         parent->right = new_node; 
      }
      else { 
         insertHelper(parent->right, new_node);
      }
   }
}

string BinarySearchTree::find(int key) const {
// Your code here....Iterative
    string tree = "";
    Node* organize = root;
    while(organize) {
    if(organize->key == key) {
        tree = organize->val;
        break;
       }
       else if(organize->key > key) organize = organize->left;
       else organize = organize->right;
    
}

   return tree;

}




void BinarySearchTree::printInOrder() const {
	if (root == nullptr) {
		cout << endl;
	}
	printInOrderHelper(root);
	cout << endl;

}
   
void BinarySearchTree::printInOrderHelper(Node* n) const {
// Your code here....Recursive
  if(!n) return;

   printInOrderHelper(n->left);

   cout << n->val << " ";

   printInOrderHelper(n->right);


}
   