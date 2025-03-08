#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 
#include <iostream> ///for testing 
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

private:
  /// Add whatever helper functions and data members you need below
  void trickleDown(int index);
  void trickleUp(int index);
  int m_; // m-ary heap 
  std::vector<T> items_; // start at 0 index 
  PComparator c_;
	int size_; // how many items in heap 
};


//constuctor 
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : 
  m_(m), c_(c), size_(0) {}
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
  return items_[0];
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
  //std::cout << "Replacing " << items_[0] << "with " << items_.back() << std::endl;

  //remove first item 
  //std::cout<<"Removing " << items_[0] << std::endl;

	items_[0] = items_.back();
	//std::cout << "Top is now " << items_[0] << std::endl;
  items_.pop_back();
  //trickle down the top element to correct spot 
  //std::cout << "Trickle down item0" << std::endl;
	trickleDown(0);
	size_--;
	//std::cout << "Size: " << size_ << std::endl;
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
	size_++;
  //add to last open spot 
  items_.push_back(item);
  //move last item up to correct position 
	//std::cout << "trickling up " << items_[items_.size()-1] << std::endl;
  trickleUp(size_-1);
	//std::cout << "curr top: " << top() << std::endl;
	//std::cout << "Size: " << size_ << std::endl;
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
  while (parent >= 0 && c_(items_[index], items_[parent]) ) {
    std::swap(items_[parent], items_[index]);
    index = parent;
    parent = (index-1)/m_;
  }
  
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index) {
  int bestChild = index*m_ + 1; // index of left child 
  //if index is leaf node (doesn't have left child), stop 
  if (bestChild >= size_ ) return;
  // find best child out of all children 
  for (int i = 1; i < m_; i++){
    int currChild = bestChild+i;

		//std::cout << "currchild : " << currChild << " val: " << items_[currChild] << std::endl;
    //std::cout << "this->size: " << this->size() << std::endl;
		if (currChild < size_) {
      //exists
			//std::cout << "Another child found " << std::endl;
      if (c_(items_[currChild], items_[bestChild])) {
				//std::cout << "Currchild: " << items_[currChild] << " is better than bestChild (replacing): " << items_[bestChild] << std::endl;
        bestChild = currChild;
      }
    }
  }
  
  if(c_(items_[bestChild], items_[index])){
    std::swap(items_[index], items_[bestChild]);
    trickleDown(bestChild);
  }
}

#endif

