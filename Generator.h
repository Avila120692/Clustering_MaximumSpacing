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
	GLint lcg(GLint m, GLint a, GLint c, GLint x0);
	GLint mcg(GLint m, GLint a, GLint x0);
	GLint randomPosition_X(GLboolean mult_generator);
	GLint randomPosition_Y(GLboolean mult_generator);
	GLint randomPosition_Z(GLboolean mult_generator);
	GLint randomEdge(GLboolean mult_generator, GLint numEdges);
	vector<Vertex> generateVertices(GLint numVertices, GLboolean gcm);
	vector<Edge> generateEdges(GLint numEdges, vector<Vertex> vertices, GLboolean mult_generator);
	GLfloat distance(Vertex v1, Vertex v2);
};

#endif