/* Node Class implementation */

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include "Node.h"

// Constructor
Node::Node(GLfloat radius){
	this->radius = radius;
}

// Sets parameters for 3D position
void Node::setPosition(GLfloat x, GLfloat y, GLfloat z){
	this->x = x;
	this->y = y;
	this->z = z;
}

// Sets parameters for the material
void Node::setMaterial(GLfloat R, GLfloat G, GLfloat B, GLfloat A){
	this->material_surface[0] = R;
	this->material_surface[1] = G;
	this->material_surface[2] = B;
	this->material_surface[3] = A;
}

// Draws the node
void Node::drawBody(void){
	glutWireSphere((GLdouble)radius, 15, 12);
}

// Destructor
Node::~Node(){}