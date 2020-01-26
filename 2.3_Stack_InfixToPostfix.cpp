/* C++ implementation to convert infix expression to postfix */

// Note that here we use std::stack  for Stack operations 
#include<bits/stdc++.h> 
using namespace std; 
 
  
/* Function to return precedence of operators */ 

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

  
/* Convert infix expression to postfix expression */

void infixToPostfix(string s) 
{ 
    std::stack<char> strStack; 
    strStack.push('N'); 
    int length = s.length(); 
    string output; 
    for(int i = 0; i < length; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        output += s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
        strStack.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(strStack.top() != 'N' && strStack.top() != '(') 
            { 
                char c = strStack.top(); 
                strStack.pop(); 
                output += c; 
            } 
            if(strStack.top() == '(') 
            { 
                char c = strStack.top(); 
                strStack.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(strStack.top() != 'N' && prec(s[i]) <= prec(strStack.top())) 
            { 
                char c = strStack.top(); 
                strStack.pop(); 
                output += c; 
            } 
            strStack.push(s[i]); 
        } 
  
    } 
    // Pop all the remaining elements from the stack 
    while(strStack.top() != 'N') 
    { 
        char c = strStack.top(); 
        strStack.pop(); 
        output += c; 
    } 
      
    cout << output << endl; 
  
} 
 
  

int main() 
{ 
    string exp = "(a/(c*(b+d)))/(e-a)*c";   // NTU 108 2.
    infixToPostfix(exp); 
    return 0; 
} 



/* Output */

// acbd+*/ea-/c*

