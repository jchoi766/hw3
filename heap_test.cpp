
#include "heap.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Heap<int> h(4);

	
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
	h.push(3);
	h.push(4);
	h.push(5);
	h.pop();
	h.push(18);
	h.push(17);
	h.push(44);
	h.push(19);
	h.push(20);
	h.push(46);
	h.push(10);
	h.push(17);
	h.push(60);
	h.push(12);
	h.push(2);
	h.push(47);

	
	cout << "Right before printing the heap: "<< endl;
	while (!h.empty()){
		cout << "pop: " << h.top() << endl;
		h.pop();
	}
 
	

}
