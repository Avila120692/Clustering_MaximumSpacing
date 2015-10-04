/* Edge class definition*/
#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include "glut.h"

using namespace std;

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
	int compareTo(Edge another);
	void draw();
};

#endif
