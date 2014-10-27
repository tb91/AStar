///*
// * pathplanning.cpp
// *
// *  Created on: Oct 14, 2014
// *      Author: lia
// */
//
//
//
#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <cmath> //abs
#include <algorithm>
#include <stack>

#include "heap.h"
#include "Node.h"



using namespace std;


typedef std::unordered_map<std::string, std::string> parent_map;

typedef std::unordered_map<std::string, int> g_map;


heap opennew;

heap closed;

//std::vector<Node> newopen;

std::vector<Node> newclosed;
g_map gvalues;

parent_map parents;


 Node start(1, 1, 0);

 Node ende(20,20,2);



std::string build_key(const Node &n){
	std::string s=std::to_string(n.get_x());
	s+="," + std::to_string(n.get_y());
	s+="," + std::to_string(n.get_z());

	return s;
}

int calc_f(const Node &n) {
	int g = gvalues[build_key(n)];
	int h = abs(n.get_x() - ende.get_x()) + abs(n.get_y() - ende.get_y())
			+ abs(n.get_z() - ende.get_z());
	return g + h*10;//euklidische distanz?  vllt weniger expands
}


bool Node::operator <(const Node &n1) const {
	return (calc_f(*this) < calc_f(n1));
}

void addNode(const Node &n, const Node &parent,int penalty) {
	if (closed.find(n) == true) {
		return;
	}

//	for (unsigned i = 0; i < newopen.size(); i++) {
//		if (newopen[i] == n) {
//			int t = gvalues[build_key(parent)] + penalty;
//			if (gvalues[build_key(newopen[i])] > t) {
//				newopen[i] = n;
//				gvalues[build_key(n)] = t;
//				parents[build_key(n)] = build_key(parent);
//
//			}
//			return;
//		}
//	}

	if(opennew.find(n)==true){
		//found node  update its cost and set new parent
		//is this really neccessary?

	        int t=gvalues[build_key(parent)]+penalty;
	        if(gvalues[build_key(n)]>t){
	          gvalues[build_key(n)]=t;
	          parents[build_key(n)]=build_key(parent);
	        }
		return;
	}


	parents.insert(std::pair<std::string, std::string>(build_key(n), build_key(parent)));

	gvalues.insert(std::pair<std::string, int>(build_key(n), gvalues[build_key(parent)] + penalty));

	opennew.push_back(n);
//	std::push_heap(newopen.begin(), newopen.end());

}

bool isFree(const Node &n){
	return true;
}


void expandNode(const Node &n) {

	Node n1 = Node(n.get_x() + 1, n.get_y(), n.get_z());
	Node n2 = Node(n.get_x(), n.get_y() + 1, n.get_z());
	Node n3 = Node(n.get_x() - 1, n.get_y(), n.get_z());
	Node n4 = Node(n.get_x(), n.get_y() - 1, n.get_z());
	Node n5 = Node(n.get_x()+1, n.get_y() + 1, n.get_z());
	Node n6 = Node(n.get_x()-1, n.get_y() - 1, n.get_z());
	Node n7 = Node(n.get_x()+1, n.get_y() - 1, n.get_z());
	Node n8 = Node(n.get_x()-1, n.get_y() + 1, n.get_z());

	Node n9 = Node(n.get_x() + 1, n.get_y(), n.get_z()+1);
	Node n10 = Node(n.get_x(), n.get_y() + 1, n.get_z()+1);
	Node n11 = Node(n.get_x() - 1, n.get_y(), n.get_z()+1);
	Node n12 = Node(n.get_x(), n.get_y() - 1, n.get_z()+1);
	Node n13 = Node(n.get_x()+1, n.get_y() + 1, n.get_z()+1);
	Node n14 = Node(n.get_x()-1, n.get_y() - 1, n.get_z()+1);
	Node n15 = Node(n.get_x()+1, n.get_y() - 1, n.get_z()+1);
	Node n16 = Node(n.get_x()-1, n.get_y() + 1, n.get_z()+1);

	Node n17 = Node(n.get_x() + 1, n.get_y(), n.get_z()-1);
	Node n18 = Node(n.get_x(), n.get_y() + 1, n.get_z()-1);
	Node n19 = Node(n.get_x() - 1, n.get_y(), n.get_z()-1);
	Node n20 = Node(n.get_x(), n.get_y() - 1, n.get_z()-1);
	Node n21 = Node(n.get_x()+1, n.get_y() + 1, n.get_z()-1);
	Node n22 = Node(n.get_x()-1, n.get_y() - 1, n.get_z()-1);
	Node n23 = Node(n.get_x()+1, n.get_y() - 1, n.get_z()-1);
	Node n24 = Node(n.get_x()-1, n.get_y() + 1, n.get_z()-1);

	Node n25 = Node(n.get_x(), n.get_y(), n.get_z()-1);
	Node n26 = Node(n.get_x(), n.get_y(), n.get_z()+1);



	if(isFree(n1)){
		addNode(n1, n,10);
	}


	if(isFree(n2)){
		addNode(n2, n,10);
	}

	if(isFree(n3)){
		addNode(n3, n,10);
	}

	if(isFree(n4)){
		addNode(n4, n,10);
	}

	//
	if(isFree(n5)){
		addNode(n5, n,14);
	}


	if(isFree(n6)){
		addNode(n6, n,14);
	}

	if(isFree(n7)){
		addNode(n7, n,14);
	}

	if(isFree(n8)){
		addNode(n8, n,14);
	}



	if(isFree(n9)){
		addNode(n9, n,14);
	}


	if(isFree(n10)){
		addNode(n10, n,14);
	}

	if(isFree(n11)){
		addNode(n11, n,14);
	}

	if(isFree(n12)){
		addNode(n12, n,14);
	}


	if(isFree(n13)){
		addNode(n13, n,14);
	}


	if(isFree(n14)){
		addNode(n14, n,14);
	}

	if(isFree(n15)){
		addNode(n15, n,14);
	}

	if(isFree(n16)){
		addNode(n16, n,14);
	}



	if(isFree(n17)){
		addNode(n17, n,14);
	}


	if(isFree(n18)){
		addNode(n18, n,14);
	}

	if(isFree(n19)){
		addNode(n19, n,14);
	}

	if(isFree(n20)){
		addNode(n20, n,14);
	}


	if(isFree(n21)){
		addNode(n21, n,14);
	}


	if(isFree(n22)){
		addNode(n22, n,14);
	}

	if(isFree(n23)){
		addNode(n23, n,14);
	}

	if(isFree(n24)){
		addNode(n24, n,14);
	}

	if(isFree(n25)){
		addNode(n25, n,10);
	}

	if(isFree(n26)){
		addNode(n26, n,10);
	}


}

std::stack<std::string> pathfinding(float s1,float s2, float s3, float z1, float z2, float z3) {

        start=Node(s1,s2,s3);
        ende=Node(z1,z2,z3);
        opennew.push_back(start);

	//parents.insert(std::pair<std::string, std::string>(build_key(start), build_key(start)));
	gvalues.insert(std::pair<std::string, int>(build_key(start), 0));

int count=0;
	stack<std::string> path;
	do {

//		cout << "open [";
//		for (unsigned i = 0; i < newopen.size(); i++) {
//			cout << "f: " << calc_f(newopen[i]);
//
//			newopen[i].print();
//		}
//		cout << " ]";


		Node curr = *opennew.pop();

		//cout << "curr vor expan";
		//curr.print();
curr.print();

cout<< calc_f(curr) <<endl;
		if (curr == ende) {
			std::string currs=build_key(curr);
			//std::map<std::string, std::string>::iterator it;
//			std::cout << "PFAAAAAAAD";

//			for (g_map::iterator it = gvalues.begin(); it != gvalues.end(); ++it) {
//
//						cout<<it->first;
//						cout<<", " << it->second<<endl;
//
//
//			}

			while((currs.compare(build_key(start)))!=0){
				currs=parents[currs];
				std::cout << currs<<endl;
				path.push(currs);
			}
			cout<<"count"<<" = "<<count<<endl;
			return path;
		}
		closed.push_back(curr);


		expandNode(curr);
		count++;
		//cout << "curr";
		//curr.print();

	} while (!opennew.is_empty());
	return path;

}



#endif
