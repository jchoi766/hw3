#include "stack.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Stack<char> s;
	
	s.push('a');
	s.push('b');
	s.push('c');
	cout << "Empty? " << s.empty() << endl;
	cout << "Top: " << s.top() << endl;




}