// CPP program to implement double hashing 
#include <bits/stdc++.h> 
using namespace std; 
  
// Hash table size 
#define TABLE_SIZE 16 
  
// Used in second hash function. 
#define PRIME 15 
  
class DoubleHash 
{ 
    // Pointer to an array containing buckets 
    int *hashTable; 
    int curr_size; 
  
public: 
  
    // function to check if hash table is full 
    bool isFull() 
    { 
  
        // if hash size reaches maximum size 
        return (curr_size == TABLE_SIZE); 
    } 
  
    // function to calculate first hash 
    int hash1(int key) 
    { 
        return (key % TABLE_SIZE); 
    } 
  
    // function to calculate second hash 
    int hash2(int key) 
    { 
        // return (PRIME - (key % PRIME));
        return (1 + (key % PRIME)); 

    } 
  
    DoubleHash() 
    { 
        hashTable = new int[TABLE_SIZE]; 
        curr_size = 0; 
        for (int i=0; i<TABLE_SIZE; i++) 
            hashTable[i] = -1; 
    } 
  
    // function to insert key into hash table 
    void insertHash(int key) 
    { 
        // if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % 
                                        TABLE_SIZE; 
  
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
  
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
  
    // function to display the hash table 
    void displayHash() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) 
        { 
            if (hashTable[i] != -1) 
                cout << i << " --> "
                     << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
}; 
  
// 108 NTU 6(b) 
int main() 
{ 
    int a[] = {16, 3, 35, 67, 51, 1, 15, 31, 19, 17}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    // inserting keys into hash table 
    DoubleHash h; 
    for (int i = 0; i < n; i++) 
        h.insertHash(a[i]); 
  
    // display the hash Table 
    h.displayHash(); 
    return 0; 
} 


/*

Output:

0 --> 16                                                                                                                               
1 --> 1                                                                                                                                
2                                                                                                                                      
3 --> 3                                                                                                                                
4 --> 17                                                                                                                               
5 --> 31                                                                                                                               
6         
7                                                                                                                                      
8 --> 19                                                                                                                               
9 --> 35                                                                                                                               
10 --> 51                                                                                                                              
11 --> 67                                                                                                                              
12      
13                                                                                                                                     
14                                                                                                                                     
15 --> 15 

*/
