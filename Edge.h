/* Edge class definition*/
using namespace std;
#include <cstring>

#ifndef __EDGE__

#define __EDGE__

class Edge {

public:
	int src;
	int dest;
	int weight;
	Edge(int src, int dest, int weight);
	~Edge();
	void toString(); // check method
	int compareTo(Edge* another);
};

#endif
