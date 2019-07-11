#if 0

#include <functional>
#include "mbtree.hpp"

using namespace std;

template<typename T>
class MBSTreeNode {
	private:
		T value;
	public:
		T& getValue();
		const T&  getCValue() const;

};


template<typename T>
class MBSTree {
	private:
		MBSTreeNode<T> root;

	public:
		bool insert(T value);
		bool traverse_pre_order(function<

#endif
