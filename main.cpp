#include "ndeque.h"
#include <cassert>
#include <iostream>

void test_deque() {
	std::cout << "test_deque\n";
	naiive::deque<int> d;
	assert(d.empty());
	d.push_back(42);
	assert( ! d.empty());
	d.push_back(43);
	assert(d.size() == 2);
	d.push_front(1);
	assert(d.size() == 3);
	assert(d.front() == 1);
	d.pop_front();
	assert(d.front() == 42);
	assert(d.back() == 43);
	d.pop_back();
	assert(d.front() == 42);
	d.pop_back();
	assert(d.empty());
	// fill
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);
	d.push_front(0);
	d.push_front(-1);
	d.push_front(-2);
	d.push_back(7);
	d.push_front(-3);
	while (!d.empty()) {
		std::cout << d.front() << ' ';
		d.pop_front();
	}
	std::cout << "\n";
}

int main() {
	test_deque();
	return 0;
}