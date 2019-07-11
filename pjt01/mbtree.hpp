#ifndef __MBTREE_HPP
#define __MBTREE_HPP

#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class BSTreeNode {
	private:
		T value;

	public:
		T getValue();
		void setValue(T value);
		T& getCValue() const;
};

template <typename T>
class BSTree {
	public:
		bool insert(T value, function<T(T&, T&)> comparator);
		void traverse_pre_order(function<void(T&)>& printer);
		void traverse_in_order(function<void(T&)>& printer);
	private:
		bool internal_insert(BSTreeNode<T>*& current, T value, function<int(T&, T&)>& comp); 
		void internal_traverse_pre_order(BSTreeNode<T>* current, function<void(T&)> printer);
		void internal_traverse_in_order(BSTreeNode<T>* current, function<void(T&)> printer);
};


int ts_mbtree(int argc, char* argv[]);

#endif
