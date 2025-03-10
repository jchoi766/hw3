
#include "heap.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Heap<int> h(4);
	
	
	h.push(20);
	//h.printItems();

	h.push(30);
	//h.printItems();

	h.push(40);
	//h.printItems();

	h.push(1);
	//h.printItems();

	h.push(2);
	//h.printItems();

	h.push(3);
	//h.printItems();

	h.push(4);
	//h.printItems();

	h.push(5);
	//h.printItems();

	h.pop();
	//h.printItems();
	
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
	
	h.push(47);
	h.printItems();

	cout << "Right before printing the heap: "<< endl;
	while (!h.empty()){

		cout << "pop: " << h.top() << endl;

		h.pop();
		//h.printItems();
	}
 
	

}
