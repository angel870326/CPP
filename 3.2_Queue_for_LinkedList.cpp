
/* C++ program for linked list based implementation of queue */
#include <bits/stdc++.h> 
using namespace std; 

  
/* Linked list (LL) node to store a queue entry */

class QNode { 
public: 
    int key; 
    QNode* next; 
}; 

  
/* Queue: front stores the front node of LL and rear stores the last node of LL */

class Queue { 
public: 
    QNode *front, *rear; 
}; 

  
/* Create a new linked list node. */ 

QNode* newNode(int k) 
{ 
    QNode* temp = new QNode(); 
    temp->key = k; 
    temp->next = NULL; 
    return temp; 
} 

  
/* Create an empty queue. */

Queue* createQueue() 
{ 
    Queue* q = new Queue(); 
    q->front = q->rear = NULL; 
    return q; 
} 

  
/* Add a key k to queue q */

void enqueue(Queue* q, int k) 
{ 
    // Create a new LL node 
    QNode* temp = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 

  
/* Remove a key from given queue q */

QNode* dequeue(Queue* q) 
{ 
    // If queue is empty, return NULL 
    if (q->front == NULL) 
        return NULL; 
  
    // Store previous front and move front one node ahead 
    QNode* temp = q->front; 
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
        q->rear = NULL; 
    return temp; 
} 
  


int main() 
{ 
    Queue* q = createQueue(); 
    enqueue(q, 10); 
    enqueue(q, 20); 
    dequeue(q); 
    dequeue(q); 
    enqueue(q, 30); 
    enqueue(q, 40); 
    enqueue(q, 50); 
    QNode* n = dequeue(q); 
    if (n != NULL) 
        cout << "Dequeued item is " << n->key; 
    return 0; 
} 




/*

Output:

Dequeued item is 30

*/

