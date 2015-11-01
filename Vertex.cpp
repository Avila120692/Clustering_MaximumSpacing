/* Node Class implementation */
#include "Vertex.h"

using namespace std;

// Constructor
Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z){
	this->radius = 0.1;
	this->x = x;
	this->y = y;
	this->z = z;
	this->color_surface[0] = 0.05;
	this->color_surface[1] = 0.46;
	this->color_surface[2] = 0.37;
}

// Sets parameters for 3D position
void Vertex::setPosition(GLfloat x, GLfloat y, GLfloat z){
	this->x = x;
	this->y = y;
	this->z = z;
}

// Set parameters for the material
void Vertex::setColor(GLfloat R, GLfloat G, GLfloat B){
	this->color_surface[0] = R;
	this->color_surface[1] = G;
	this->color_surface[2] = B;
}

// Draw the node with a predefined body (Wire sphere)
void Vertex::draw(void){

	// Color for node
	glColor3f(color_surface[0], color_surface[1], color_surface[2]);

	// Draw the node
	glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidSphere(radius, 10, 11);
	glPopMatrix();
}


// Destructor
Vertex::~Vertex(){}