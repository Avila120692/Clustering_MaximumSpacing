/* Generator Class definition*/
#include <time.h>
#include <vector>
#include "Node.h"
#include "Edge.h"

using namespace std;

#ifndef __GENERATOR__

#define __GENERATOR__

class Generator {

public:
	int random_factor;
	Generator(int random_factor);
	~Generator();
	void generateNodes(int n);
	vector<Edge> generateEdges(int numEdges);
};

#endif