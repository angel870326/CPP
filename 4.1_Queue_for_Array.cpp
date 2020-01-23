/* C++ program for array implementation of queue. */ 
#include <bits/stdc++.h> 
using namespace std; 
  
class Queue  
{  
    public: 
    int front, rear, size;  
    unsigned capacity;  
    int* array;  
};  
  

/* Create a queue of given capacity, and initialize its size as 0. */

Queue* createQueue(unsigned capacity)  
{  
    Queue* queue = new Queue(); 
    queue->capacity = capacity;  
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue  
    queue->array = new int[(queue->capacity * sizeof(int))];  
    return queue;  
}  

  
/* Queue is full when size = capacity */

int isFull(Queue* queue)  
{ return (queue->size == queue->capacity); }  

  
/* Queue is empty when size is 0 */

int isEmpty(Queue* queue)  
{ return (queue->size == 0); }  
 
  
/* Add an item to the queue (rear and size changes */ 

void enqueue(Queue* queue, int item)  
{  
    if (isFull(queue))  
        return;  
    queue->rear = (queue->rear + 1) % queue->capacity;  
    queue->array[queue->rear] = item;  
    queue->size = queue->size + 1;  
    cout << item << " enqueued to queue\n";  
}  

  
/* Remove an item from queue (front and size changes) */

int dequeue(Queue* queue)  
{  
    if (isEmpty(queue))  
        return INT_MIN;  
    int item = queue->array[queue->front];  
    queue->front = (queue->front + 1) % queue->capacity;  
    queue->size = queue->size - 1;  
    return item;  
}  
 
  
/* Get front of queue */

int front(Queue* queue)  
{  
    if (isEmpty(queue))  
        return INT_MIN;  
    return queue->array[queue->front];  
}  

  
/* Get rear of queue */

int rear(Queue* queue)  
{  
    if (isEmpty(queue))  
        return INT_MIN;  
    return queue->array[queue->rear];  
}  
  



int main()  
{  
    Queue* queue = createQueue(1000);  
  
    enqueue(queue, 10);  
    enqueue(queue, 20);  
    enqueue(queue, 30);  
    enqueue(queue, 40);  
  
    cout<<dequeue(queue)<<" dequeued from queue\n";  

    cout << "Front item is " << front(queue) << endl;  
    cout << "Rear item is " << rear(queue) << endl;  
  
    return 0;  
}  




/* 

Output:

10 enqueued to queue                                                                                                                   
20 enqueued to queue                                                                                                                   
30 enqueued to queue                                                                                                                   
40 enqueued to queue                                                                                                                   
10 dequeued from queue                                                                                                                 
Front item is 20                                                                                                                       
Rear item is 40

*/
