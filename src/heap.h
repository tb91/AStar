/*
 * heap.h
 *
 *  Created on: Oct 23, 2014
 *      Author: timmy
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "Node.h"
#include <vector>


#include <unordered_map>



class heap {

private:

	std::vector<Node> values;

	std::unordered_map<std::string, bool> hash;


	std::string build_key(const Node &n){
		std::string s=std::to_string(n.get_x());
		s+="," + std::to_string(n.get_y());
		s+="," + std::to_string(n.get_z());

		return s;

	}

	int getParent(int i) {
		if (i == 0) {
			return -1;
		} else {
			return (i - 1) / 2;
		}

	}

	void swap(int from, int to) {
		Node help = values[from];
		values[from] = values[to];
		values[to] = help;
	}

	void sift_up(int pos) {
		if (pos == 0) {
			return;
		}
		int ppos = getParent(pos);
		if (values[pos] < values[ppos]) {
			swap(pos, ppos);
			sift_up(ppos);
		}
	}

	void sift_down(int p) {
		unsigned int left = 2 * p + 1;
		unsigned int right = 2 * p + 2;
		if (left >= values.size() && right >= values.size()) {
			return;
		}
		if (right >= values.size() || values[left] < values[right]) {
			swap(left, p);
			sift_down(left);
		} else {
			swap(right, p);
			sift_down(right);
		}
	}
	void reheap() {

		swap(values.size() - 1, 0);

		values.erase(values.end());

		sift_down(0);


	}

public:
	/** Constructor */
	heap() {


	}


	/** Destructor */
	~heap() {
		delete this;
	}

	/** Copy Assignment Operator */
	heap& operator=(heap other) // note: argument passed by value
			{
		std::swap(values, other.values);
		return *this;
	}

	void push_back(Node t) {
		//std::cout << "es wird gepusht";
		//t.print();
		values.push_back(t);
		hash[build_key(t)]=true;
		//std::cout << "fertig gepusht";
		//t.print();
		sift_up(values.size() - 1);

	}

	Node* pop() {
		if (!is_empty()) {
		Node root = values.front();

		hash[build_key(root)]=false;
		reheap();


       		return &root;
		}
		return NULL;
	}

	bool find(const Node &n) {

		return hash[build_key(n)];

	}

	bool is_empty() {
		return values.empty();
	}

	int size() {
		return values.size();
	}

	void print() {
		for (unsigned int var = 0; var < values.size(); ++var) {
			values[var].print();
		}
	}

};

#endif /* HEAP_H_ */

