/* Edge class definition*/
#include <windows.h>
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include "glut.h"
#include "Vertex.h"

using namespace std;

#ifndef __EDGE__

#define __EDGE__

class Edge {

public:
	GLint src;
	GLint dest;
	GLfloat weight;
	Edge(GLint src, GLint dest, GLfloat weight);
	~Edge();
	void toString(); // check method
	int compareTo(Edge another);
	void draw(vector<Vertex> vertices);
};

#endif
