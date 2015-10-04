/* Edge class implementation*/
#include "Edge.h"

using namespace std;

// Constructor
Edge::Edge(int src, int dest, int weight) {

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

void Edge::draw(){

	// Draw reference frame
	glLineWidth(0.8);
	
	// Draw line
	glBegin(GL_LINES);
		glVertex3d(src, 0.0, 0.0);
		glVertex3d(dest, 0.0, 0.0);
	glEnd();

	glPushMatrix();
		// Draw cone
		glTranslated(0.0, 0.0, weight - 0.2);
		glutSolidCone(0.04, 0.2, 12, 9);
	glPopMatrix();
}

// Destructor
Edge::~Edge(){}