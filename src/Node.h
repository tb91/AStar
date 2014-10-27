/*
 * Node.h
 *
 *  Created on: Oct 25, 2014
 *      Author: lia
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

class Node {

private:
	int x;
	int y;
	int z;


public:
	Node(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z=  z;


	}


	~Node() {
		// TODO Auto-generated destructor stub
	}





	bool operator<(const Node &b) const;

	bool operator==(const Node &b) const{
		if (this->x == b.get_x() && this->y == b.get_y() && this->z == b.get_z()) { //FIXME
			//std::cout << "Hallo ==";
			return true;
		}
		return false;
	}

	Node operator=(const Node &b){
	  if(this!=&b){
	    this->x=b.get_x();
	    this->y=b.get_y();
	    this->z=b.get_z();
	  }

	  return *this;
	}

	int get_x() const {
		return x;
	}
	int get_y() const {
		return y;
	}

	int get_z() const {

			return z;
		}

	void print() const {
		std::cout << "(" << this->get_x() << ", " << this->get_y() << ", " << this->get_z() << ")" << std::endl;
	}

//	bool is_free(SimpleGrayImage &img) {
//		return (img[x][y] == 0);
//
//	}

};

#endif /* NODE_H_ */
