#pragma once
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cassert>

// NOTE doesn't destroy removed elements
// push_back: delegates the work to the vector to grow at the end O(1)
// push_front: asks for a bigger vector and moves the elements to the back of it to allow grow in the front
namespace naiive {

template<class T>
class deque {
public:
	typedef std::vector<T> Container;
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::size_type size_type;

	deque() : array_(), begin_(array_.begin()) {}

	void push_front(const T& val) {
		if (begin_ == array_.begin()) {
			size_type deque_size = size();
			array_.resize(array_.size() * 2);
			begin_ = array_.begin();
			std::copy_backward(begin_, begin_ + deque_size, array_.end());
			begin_ = array_.end() - deque_size;
		}
		--begin_;
		*begin_ = val;
	}

	void push_back(const T& val) {
		int pos = begin_ - array_.begin();
		array_.push_back(val);
		begin_ = array_.begin() + pos;
	}

	size_type size() const { return array_.end() - begin_; }

	bool empty() const { return size() == 0; }

	void pop_front() {
		assert(!empty());
		++begin_;
	}

	void pop_back() {
		assert(!empty());
		array_.resize(array_.size() - 1);
	}

	T& front() { 
		assert(!empty());
		return *begin_;
	}
	const T& front() const {
		assert(!empty());
		return *begin_;
	}

	T& back() {
		assert(!empty());
		return *(array_.begin() + array_.size() - 1);
	}
	const T& back() const {
		assert(!empty());
		return *(array_.begin() + array_.size() - 1);
	}

private:
	Container array_;
	iterator begin_;
};

} // namespace