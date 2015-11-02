/* Edge class implementation*/
#include "Edge.h"

using namespace std;

// Constructor
Edge::Edge(GLint src, GLint dest, GLfloat weight) {
	this->src = src;
	this->dest = dest;
	this->weight = weight;
}

// Print edge info
void Edge::toString() {
	printf("\n Edge : %i - $i Weight : ", src, dest, weight);
}

// Compares two edges
int Edge::compareTo(Edge another){
	return (this->weight - another.weight);
}

void Edge::draw(vector<Vertex> vertices){
	// Extract the vertices associated to the edge
	Vertex v1 = vertices.at(src);
	Vertex v2 = vertices.at(dest);

	// Line width
	glLineWidth(1.2);
	
	// Draw line
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3d(v1.x, v1.y, v1.z);
		glVertex3d(v2.x, v2.y, v2.z);
	glEnd();
}

// Destructor
Edge::~Edge(){}