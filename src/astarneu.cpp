//============================================================================
// Name        : astarneu.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "astar.h"
#include <chrono>
using namespace std;

namespace {
double getCurrentTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch()).count();
}
}

int main(int argc, char **argv) {
	cout << "jetzt gehts los" << endl<<endl;

	double t = getCurrentTime();
	pathfinding(0, 0, 0, 100, 100, 100);
	double e = getCurrentTime();
	e -= t;
	e /= 1000;
	cout << "Hat " << e << " Sekunden gebraucht.\n";

	return 0;
}
