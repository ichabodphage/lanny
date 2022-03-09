#pragma once
#include <vector>
#include <memory>


/*
	a simple memory pooling class designed for quick insertion of new elements.
	fixed size
*/
template<class T>
class MemoryPool {
private:

	//item struct for items in the memory pool
	struct PoolItem {
		//value of the index
		T value;
		//index of the next free index in the pool
		size_t next;
		PoolItem(T val) :value(val) {};
	};


	//next free element
	size_t nextFree;

	//memory block holding the memory pool
	std::vector<PoolItem> block;

	//value to set deallocated values to
	T defaltValue;
	//size of the pool
	size_t poolSize;

public:
	MemoryPool(size_t maxSize, T defaultVal) :
	poolSize(maxSize), 
	defaltValue(defaultVal),
	nextFree(0){
		
		//set the size of the memory block to maxSize
		block.reserve(maxSize);
		
		//fill the memory pool with free items that have the default value
		for (size_t i = 0; i < maxSize - 1; i++) {
			block[i].value = defaltValue;
			block[i].next = i + 1;
		}
		
		//skip adding a next value for the last item
		block[maxSize - 1].value = defaltValue;
		
	}

	//returns the current amountof values allocated into the pool
	size_t size() {
		return poolSize;
	}

	//allocates a new value and returns its index
	size_t allocate(T value) {
		
		//get the current next free index and the next free index after that one
		size_t oldindex = nextFree;
		size_t newNext = block[nextFree].next;

		/*
			assign the next free index with value and remove
			its next free index value to mark it as occupied
		*/
		block[nextFree].value = value;
		block[nextFree].next = 0;
		//get the new next free index since the current one is now occupied
		nextFree = newNext;

		//return the index of the allocated value
		return oldindex;

		
	}
	//marks a specific index
	void deallocate(size_t index) {
		
		//set the next free index to index if the memory pool is full
		if (nextFree == 0) {
			nextFree = index;
		}
		//otherwise assign the index to point to the previous free index
		else if(block[index].next == 0){
			block[index].next = nextFree;
			nextFree = index;
			
		}
		
		//set the value at the index to the default value
		block[index].value = defaltValue;
		
	}
	//returns a value of a block at a certian index
	T getValue(size_t index) {
		return block[index].value;
	}

};