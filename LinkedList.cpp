#include <iostream>
using namespace std;

/* Linked list node */
class Node { 
public: 
    int element; 
    Node* next; 
}; 

/* Print contents of linked list starting from the given node */
void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->element << " "; 
        n = n->next; 
    } 
} 

/* Insert a new node at the front of the list O(1) */
void addFront(Node** head_ref, int new_element)  
{  
    // 1. allocate a new node
    Node* new_node = new Node();  
  
    // 2. put an element in the new node
    new_node->element = new_element;  
  
    // 3. make "next" of the new node as head
    new_node->next = (*head_ref);  
  
    // 4. move the head to point to the new node
    (*head_ref) = new_node;  
}  

/* Insert a new node after the given prev_node O(1) */
void insertAfter(Node* prev_node, int new_element) 
{ 
    // 1. check if the given prev_node is NULL
    if (prev_node == NULL)  
    {  
       cout<<"The given previous node cannot be NULL.";        
       return;   
    }   
           
    // 2. allocate a new node
    Node* new_node = new Node();  
   
    // 3. put an element in the new node
    new_node->element = new_element;  
   
    // 4. make "next" of the new node as next of the prev_node
    new_node->next = prev_node->next;  
   
    // 5. move the next of prev_node as new_node
    prev_node->next = new_node; 
} 

/* Append a new node at the end O(n) */
void append(Node** head_ref, int new_element) 
{ 
    // 1. allocate a new node and a last node
    Node* new_node = new Node(); 
    Node *last = *head_ref;  // used in step 5

    // 2. put an element in the new node
    new_node->element = new_element;  
  
    // 3. this new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL; 
  
    // 4. if the Linked List is empty, then make the new node as head
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    // 5. else traverse till the last node
    while (last->next != NULL) 
        last = last->next; 
   
    // 6. Change the next of last node
    last->next = new_node; 
    return;     
} 


int main() 
{ 
    /* Example 1 */
    
    // empty list
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 
    
    head->element = 1; // assign element in first node 
    head->next = second; // Link first node with the second node
    
    second->element = 2; // assign element to second node 
    second->next = third; // Link second node with the third node
    
    third->element = 3; // assign element to third node 
    third->next = NULL; 
    
    // print the list
    cout<<"Linked list 1: "; 
    printList(head1);
    cout<<"\n"; 
    
    
    /* Example 2 */
    
    // empty list
    Node* head2 = NULL; 
    
    // insert 3  (Linked list: 3 -> NULL)  
    append(&head2, 3);  
      
    // insert 0 at the beginning  (Linked list: 0 -> 3 -> NULL) 
    addFront(&head2, 0);  
      
    // insert 6 at the end  (Linked list: 0 -> 3 -> 6 -> NULL)  
    append(&head2, 6);  
      
    // insert 2, after 3  (Linked list: 0 -> 3 -> 2 -> 6 -> NULL)  
    insertAfter(head2->next, 2);  
    
    // print the list
    cout<<"Linked list 2: ";  
    printList(head2);  
       
    
    return 0;
    
}
