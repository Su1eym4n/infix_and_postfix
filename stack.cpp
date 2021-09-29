#include "stack.hpp"

using namespace std;

template<class T>
void Stack<T>::push(T c){
  if(topIndex > MAXSIZE-1){
    cout<<"Stack overflow"<<endl;
    return;
  }
  arr[topIndex + 1] = c;
  topIndex++;
}

template<class T>
T Stack<T>::pop(){
  if(topIndex < 0){
    cout<<"Cannot delete. Stack empty."<<endl;
  }

  return arr[topIndex--];
}

template<class T>
T Stack<T>::peek(){
  if(topIndex < 0){
    cout<<"Cannot peek. Stack empty."<<endl;
  }
  return arr[topIndex];
}

template<class T>
int Stack<T>::size(){
  return topIndex+1;
}

template<class T>
void Stack<T>::display(){
  for(int i=topIndex; i>=0; --i){
    cout<<arr[i]<<"\t";
  }
  cout<<endl;
}

template class Stack<char>;
template class Stack<int>;
//this is needed for postfix2toindex
template class Stack<string>;
