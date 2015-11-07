/* Edge class definition*/
#include <windows.h>
#include <iostream>
#include <vector>
#include "Vertex.h"

using namespace std;

#ifndef __EDGE__

#define __EDGE__

class Edge {

public:
	int src;
	int dest;
	float weight;
	Edge(GLint src, GLint dest, GLfloat weight);
	~Edge();

	void toString();
	int compareTo(Edge another);
	void draw(vector<Vertex> vertices, GLfloat mat_env);
};

#endif
