/*  Search, Insert, and Delete in Binary Search Tree (BST) */
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
/* Create a new BST node */
struct node *newNode(int item) 
{ 
    struct node *temp =  new node();   // (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
/* Inorder traversal of BST */
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 

/* Search a given key in a given Binary Search Tree (BST) */
struct node* search(struct node* root, int key) 
{ 
    // If root is null or key is present at root, return NULL
    if (root == NULL || root->key == key) 
       return root; 
     
    // If key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // If key is smaller than root's key 
    return search(root->left, key); 
} 
   
/* Insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key); 
  
    // Otherwise, recur down the tree
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    // return the (unchanged) node pointer
    return node; 
} 




   
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    
    insert(root, 25); 
  
    // print inoder traversal of the BST 
    inorder(root); 
    
    printf("Search for 50: %d\n", search(root, 50)->key);
   
    return 0; 
} 


/*

Output:

20 
25
30                                                                                                                                     
40                                                                                                                                     
50                                                                                                                                     
60                                                                                                                                     
70                                                                                                                                     
80 
Search for 50: 50                                                                                                                      

*/



