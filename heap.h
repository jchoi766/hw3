#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

	//for testing: 
	void printItems();
private:
  /// Add whatever helper functions and data members you need below
  void trickleDown(int index);
  void trickleUp(int index);
  int m_; // m-ary heap 
  std::vector<T> items_; // start at 0 index 
  PComparator c_;
	int size_; // how many items in heap 
};

template <typename T, typename PComparator>
void Heap<T,PComparator>::printItems() {
	std::cout << "Items: ";
	for (int i = 0 ; i < size_ ; i++){

		std::cout << items_[i] << ", ";
	}
	std::cout << "\n";
}
//constuctor 
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : 
  m_(m), c_(c), size_(0) {
	}
//destructor  
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_.at(0);
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  //replace top item with last item 

  //remove first item 
	size_--;
	items_[0] = items_.back();
	//std::cout << "Top is now " << items_[0] << std::endl;
  items_.pop_back();
  //trickle down the top element to correct spot 
	trickleDown(0);
	
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
	size_++;
  //add to last open spot 
  items_.push_back(item);
  //move last item up to correct position 
  trickleUp(size_-1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return (size_ == 0);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return size_;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index) {
	
  int parent = (index-1)/m_;
	if (parent < 0 || !c_(items_[index], items_[parent] )) {
		return;
	}
  std::swap(items_[parent], items_[index]);
	trickleUp(parent);
	/*
	int parent = (index-1)/m_;
  while (parent >= 0 && c_(items_[index], items_[parent]) ) {
    std::swap(items_[parent], items_[index]);
    index = parent;
    parent = (index-1)/m_;
  }*/
  
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index) {
	//std::cout << "Trickling down: " << items_[index] << std::endl;
  int bestChild = index*m_ + 1; // index of left child 
	//std::cout << "Left child: " << items_[bestChild] << std::endl;
  //if index is leaf node (doesn't have left child), stop 
  if (bestChild >= size_ ) {
		//std::cout << "Best child is greater than size; exit " << std::endl;
		return;
	}
  // find best child out of all children 
	int currChild = bestChild;
  for (int i = 1; i < m_; i++){
    currChild++;
		if (currChild >= size_) {

			//std::cout << "currChild: " << currChild << " size_ " << size_ << " break here" << std::endl;
			break;
		}
		//std::cout << "Checking " << items_[currChild] << std::endl;
		if (currChild < size_ && c_(items_[currChild], items_[bestChild])) {
      //std::cout << "currChild: " << items_[currChild] << " is better than bestChild: " << items_[bestChild] << std::endl;
			bestChild = currChild;
    }
  }
  if(c_(items_[bestChild], items_[index])){
		//std::cout << "Swap " << items_[index] << " and " << items_[bestChild] << std::endl;
    std::swap(items_[index], items_[bestChild]);
    trickleDown(bestChild);
  }
}

#endif

