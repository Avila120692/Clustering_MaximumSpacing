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

void Edge::draw(vector<Vertex> vertices, GLfloat mat_env){
	// Extract the vertices associated to the edge
	Vertex v1 = vertices.at(src);
	Vertex v2 = vertices.at(dest);

	// Line width
	glLineWidth(1.2);
	
	// Line for the edge
	GLfloat mat_ambientZ[] = { mat_env, mat_env, mat_env, 1.0 };
	GLfloat mat_diffuseZ[] = { 0.0, 0.50980392, 0.50980392, 1.0 };
	GLfloat mat_specularZ[] = { 0.50196078, 0.50196078, 0.50196078, 1.0 };
	GLfloat mat_shininessZ[] = { 0.25 };
	GLfloat mat_emissive[] = { 0.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientZ);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseZ);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularZ);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininessZ);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);

	// Draw line
	glBegin(GL_LINES);
		glVertex3d(v1.x, v1.y, v1.z);
		glVertex3d(v2.x, v2.y, v2.z);
	glEnd();
}

// Destructor
Edge::~Edge(){}