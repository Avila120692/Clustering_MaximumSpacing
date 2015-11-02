/* Generator Class definition*/
#include <time.h>
#include <cmath>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

#ifndef __GENERATOR__

#define __GENERATOR__

class Generator {

public:
	Generator();
	~Generator();

	int lcg(int m, int a, int c, int x0);
	int mcg(int m, int a, int x0);
	int randomPosition_X(bool mult_generator);
	int randomPosition_Y(bool mult_generator);
	int randomPosition_Z(bool mult_generator);
	int randomEdge(bool mult_generator, int numEdges);
	
	vector<Vertex> generateVertices(int numVertices, bool gcm);
	vector<Edge> generateEdges(vector<Vertex> vertices, int numEdges, bool gcm);
	float distance(Vertex v1, Vertex v2);
};

#endif