#include <iostream>

using namespace std;

class Node { 
public: 
    int element; 
    Node* next; 
}; 

// Print contents of linked list starting from the given node 
void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->element << " "; 
        n = n->next; 
    } 
} 

int main() 
{ 
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
    
    printList(head);
    
    return 0;
    
}
