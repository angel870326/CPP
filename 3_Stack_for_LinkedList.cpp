/* C++ program to implement basic stack operations */
#include <bits/stdc++.h> 
using namespace std; 

// Last in, first out.

/* Implementing Stack using Linked List */

class StackNode { 
public: 
    int element; 
    StackNode* next; 
}; 
  
StackNode* newNode(int element) 
{ 
    StackNode* stackNode = new StackNode(); 
    stackNode->element = element; 
    stackNode->next = NULL; 
    return stackNode; 
} 


/* Check if root (a node) is empty */ 

int isEmpty(StackNode* root) 
{ 
    return !root; 
} 


/* push (add item) */ 

void push(StackNode** root, int element) 
{ 
    StackNode* stackNode = newNode(element); 
    stackNode->next = *root; 
    *root = stackNode; 
    cout << element << " pushed into stack\n"; 
} 


/* pop (remove item) */ 
  
int pop(StackNode** root) 
{ 
    if (isEmpty(*root)) 
        return INT_MIN; 
    StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->element; 
    free(temp); 
  
    return popped; 
} 


/* peek (return top item of stack, last popped item in the stack) */ 
  
int peek(StackNode* root) 
{ 
    if (isEmpty(root)) 
        return INT_MIN; 
    return root->element; 
} 



  
int main() 
{
    cout << "Stack for Linked List: \n";

    StackNode* root = NULL;   // root is like head
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
    cout << pop(&root) << " popped from stack\n"; 
  
    cout << "Top element is " << peek(root) << endl; 
  
    return 0; 
} 


/*

Output:

Stack for Linked List:                                                                                                                 
10 pushed into stack                                                                                                                   
20 pushed into stack                                                                                                                   
30 pushed into stack                                                                                                                   
30 popped from stack                                                                                                                   
Top element is 20 

*/
