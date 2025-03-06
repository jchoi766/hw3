

#include "stack.h"

using namespace std;

void Stack::push(const T& item) {
  //add to end 
  this->push_back(item);
}

// throws std::underflow_error if empty
void Stack::pop() {
  if (size() == 0) throw std::underflow_error;
  //remove from end 
  this->pop_back();

}

// throws std::underflow_error if empty
const T& Stack::top() const {
  if (size() == 0) throw std::underflow_error;
  //return last element 
  return this->back();
}
