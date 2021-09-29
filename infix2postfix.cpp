#include "stack.hpp"

using namespace std;

// Auxiliary method, you probably find it useful
// Operands are all lower case and upper case characters
bool isOperand(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isOperator(char c){
   switch (c) {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 1;
    case '^':
        return 1;
    case '/':
        return 1;
    case '(':
        return 1;
    }
    return 0;
}
// Auxiliary method, you probably find it useful
int precedence(char c)
{
  if(c == '+' || c == '-'){
    return 0;
  }
  if(c == '*' || c == '/'){
    return 1;
  }
  if(c == '^'){
    return 2;
  }
  return -1;
}

int main(){
  freopen("input_infix2postfix.txt", "r", stdin);
  string input;
  string solution;
  int line_counter = 0;
  while(cin >> solution){
    cin >> input;
    Stack<char> stack;
    string result;

     //The input file is in the format "expected_solution infix_expression", 
     //where expected_solution is the infix_expression in postfix format

    for(int i=0; i<input.length(); ++i){
      char a = input[i];
      // WRITE CODE HERE to store in 'result' the postfix transformation of 'input'
      
      //if char is operand add to string
      if(isOperand(a)){
        result+=a;
      }
      //if char is closing bracket
      else if(a==')'){
             while (stack.peek()!='(')
             {
               result+=stack.peek();
               stack.pop();
             }
              stack.pop();
           }
       else if(isOperator(a)){
           if(stack.size()==0 || precedence(a)>precedence(stack.peek())||a=='('){
             stack.push(a);
           }else{
             while (stack.size() != 0 && precedence(a)<=precedence(stack.peek())||a=='(')
             {
               result+=stack.peek();
               stack.pop();
             }
             stack.push(a);
             
           }
    
           }

     }

    // You need to do some extra stuff here to store in 'result' the postfix transformation of 'input'
    //adding all elemnts that left from stack to result
    while (stack.size()!=0)
    {
      result+=stack.peek();
      stack.pop();
    }

    

    
    //Checking whether the result you got is correct
    if(solution == result){
      cout << "line " << line_counter << ": OK [" << solution << " " << result << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << result << "]" << endl;
          cout<<result<<endl;
    }
    line_counter++;
  }
}
