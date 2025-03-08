
#include "heap.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Heap<int> h;
	
	h.push(10);
	h.push(20);
	cout << "top should be 10: "<< h.top()<<endl;

	h.pop();
	cout << "top shoud be 20: " << h.top()<<endl ; 
	
	h.push(30);
	h.push(5);

	h.push(1);
	h.pop();
	h.pop();

	h.push(2);
	h.push(40);
	h.pop();
	h.push(1);
	h.push(2);
	
	cout << "Right before printing the heap: 1 2 20 30 40  "<< endl;
	while (!h.empty()){
		cout << "pop: " << h.top() << endl;
		h.pop();
	}
 
	

}
