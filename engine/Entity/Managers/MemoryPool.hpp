#pragma once
#include <vector>
#include <memory>


/*
	a simple memory pooling class designed for quick insertion of new elements

*/
template<class T>
class MemoryPool {
private:
	//item struct for items in the memory pool
	struct PoolItem {
		T value;
		size_t next;
		PoolItem(T val) :value(val) {};
	};
	//next free element
	size_t nextFree;
	std::vector<PoolItem> block;
	T defaltValue;
	//size of the pool
	size_t poolSize;
public:
	MemoryPool(size_t maxSize, T def) :poolSize(maxSize), defaltValue(def) {
		nextFree = 0;
		block.reserve(maxSize);
		for (size_t i = 0; i < maxSize - 1; i++) {
			block[i].value = def;
			block[i].next = i + 1;
		}
		block[maxSize - 1].value = def;
	}
	size_t size() {
		return poolSize;
	}

	//allocates a new value and returns its index
	size_t allocate(T value) {
		size_t oldindex = nextFree;
		size_t newNext = block[nextFree].next;
		block[nextFree].value = value;
		block[nextFree].next = 0;
		nextFree = newNext;
		return oldindex;
	}
	//marks a specific index
	void deallocate(size_t index) {
		if (nextFree == 0) {
			nextFree = index;
		}
		else {
			if (block[index].next == 0) {
				block[index].next = nextFree;
				nextFree = index;
			}
		}
		block[index].value = defaltValue;
	}
	T getValue(size_t index) {
		return block[index].value;
	}

};