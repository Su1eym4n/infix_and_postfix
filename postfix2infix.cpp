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
  freopen("input_postfix2infix.txt", "r", stdin);
  string input;
  string solution;
  int line_counter = 0;
  while(cin >> solution){
    cin >> input;
    Stack<string> stack;
    string result;

    for(int i=0; i<input.length(); ++i){
      char a = input[i];
      
      if(isOperand(a)){
          string op(1,a);
          stack.push(op);
      }
      if (isOperator(a))
      {
        string op(1,a);
        string rOperand = stack.peek();
        stack.pop();
        string lOperand = stack.peek();
        stack.pop();
        //creating an expression and addint it to the stack
        stack.push("("+lOperand+op+rOperand+")");

     }
    }
    result = stack.peek();


    

    
    //Checking whether the result you got is correct
    if(solution == result){
      cout << "line " << line_counter << ": OK [" << solution << " " << result << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << result << "]" << endl;
    }
    line_counter++;
  }
}
