#include "stack.hpp"

using namespace std;

int main(){
  freopen("input_balanced.txt", "r", stdin);
  string s,r;
  int line_counter;
  while(cin >> r){
    cin>>s;
    Stack<char> stack;
    bool isBalanced = true;
    bool solution;
    if(r[0] == 'Y' || r[0] == 'y'){
      solution = true;
    }else{
      solution = false;
    }

    // The input file is in the format "expected_solution expression"
    // so variable solution tells you whether 'expression' is balanced or not
    char temp;
    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE so that isBalanced indicates whether 's' is balanced
      
      //add char is it is an openin bracket
      if (s[i] == '(' || s[i] == '[' || s[i]=='{')
      {
        stack.push(s[i]);
       // cout<<stack.size()<<std::endl;
      } 

      //stops if nothing is added;
      if(stack.size()==0){
          isBalanced = false;
          break;
      }

      if (isBalanced){    
      if(s[i] == ')'){
          temp = stack.pop();
          if (temp == '[' || temp == '{')
          {
            isBalanced = false;
          } 
      }
      if(s[i] == ']'){
          temp = stack.pop();
          if (temp == '(' || temp == '{')
          {
            isBalanced = false;
          } 
      } 
      if(s[i] == '}'){
          temp = stack.pop();
          if (temp == '(' || temp == '[')
          {
            isBalanced = false;
          } 
      }     
      }
    }
      
   
    if (stack.size()==0)
    {
      isBalanced=true;
    }
    

    // checking if you stored in isBalanced the correct value
    if(isBalanced == solution){
      cout << "line " << line_counter << ": OK [" << solution << " " << isBalanced << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << isBalanced << "]" << endl;
    }
    line_counter++;
  }
}
