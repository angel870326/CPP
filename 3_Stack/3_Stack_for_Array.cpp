/* C++ program to implement basic stack operations */
#include <bits/stdc++.h> 
using namespace std; 

// Last in, first out.

/* Implementing Stack using Array */
  
#define MAX 1000 

class Stack { 
    int top; 
  
public: 
    int arr[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 


/* push (add item) */ 

bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        arr[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 


/* pop (remove item) */ 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = arr[top--]; 
        return x; 
    } 
} 


/* peek (return top item) */ 

int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = arr[top]; 
        return x; 
    } 
} 


/* isEmpty (return true if stack is empty) */ 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
  


int main() 
{ 
    cout << "Stack for array: \n";
    class Stack stackArr; 
    stackArr.push(10); 
    stackArr.push(20); 
    stackArr.push(30);
    cout << stackArr.pop() << " popped from stack\n";   
    return 0; 
    
} 


/*
    
Output:
    
Stack for array:                                                                                                                       
10 pushed into stack                                                                                                                   
20 pushed into stack                                                                                                                   
30 pushed into stack                                                                                                                   
30 popped from stack  
    
*/

