/* C++ program for different tree traversals (bottom-up) */
#include <iostream> 
using namespace std; 

 
/* A binary tree node has element, pointer to left child and a pointer to right child */

struct Node 
{ 
    int element; 
    struct Node* left, *right; 
    Node(int element) 
    { 
        this->element = element; 
        left = right = NULL; 
    } 
}; 

  
/* Given a binary tree, print its nodes according to the "bottom-up" postorder traversal. */

void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->element << " "; 
} 

  
/* Given a binary tree, print its nodes in inorder*/

void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the element of node */
    cout << node->element << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 

 
/* Given a binary tree, print its nodes in preorder*/

void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print element of node */
    cout << node->element << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  

  

int main() 
{ 
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    return 0; 
} 


/*

Output:

Preorder traversal of binary tree is                                                                                                   
1 2 4 5 3                                                                                                                              
Inorder traversal of binary tree is                                                                                                    
4 2 5 1 3                                                                                                                              
Postorder traversal of binary tree is                                                                                                  
4 5 2 3 1               

*/
