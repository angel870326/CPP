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
        printf("%d ", root->key); 
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


/* Given a non-empty BST, return the node with minimum key value found in that tree. 
   Note that the entire tree does not need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    // loop down to find the leftmost leaf
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Delete the key and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then this is the node to be deleted 
    else
    { 
        // 1. node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // 2. node with two children: Get the inorder successor (smallest in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
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
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    // print inoder traversal of the BST 
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    // delete 20 (leaf)
    root = deleteNode(root, 20); 
    printf("\n\nBST after deleting 20 (leaf) \n"); 
    inorder(root); 
    
    // delete 30 (node with one child)
    root = deleteNode(root, 30); 
    printf("\n\nBST after deleting 30 (node with one child) \n"); 
    inorder(root); 

    // delete 50 (node with two children)
    root = deleteNode(root, 50); 
    printf("\n\nBST after deleting 50 (node with two children) \n"); 
    inorder(root); 
    
    
    // Search for a given key in BST
    printf("\n\nSearch for 70: %d\n", search(root, 70)->key);
   
    return 0; 
} 


/*

Output:

Inorder traversal of the given tree                                                                                                    
20 30 40 50 60 70 80                                                                                                                   
                                                                                                                                       
BST after deleting 20 (leaf)                                                                                                           
30 40 50 60 70 80                                                                                                                      
                                                                                                                                       
BST after deleting 30 (node with one child)
40 50 60 70 80                                                                                                                         
                                                                                                                                       
BST after deleting 50 (node with two children)                                                                                         
40 60 70 80                                                                                                                            
                                                                                                                                       
Search for 70: 70  

*/




