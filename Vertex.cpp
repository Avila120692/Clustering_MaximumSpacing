/* Node Class implementation */
#include "Vertex.h"

using namespace std;

// Constructor
Vertex::Vertex(float x, float y, float z){
	this->radius = 0.1;
	this->x = (GLfloat) x;
	this->y = (GLfloat) y;
	this->z = (GLfloat) z;
	this->color_surface[0] = 0.05;
	this->color_surface[1] = 0.46;
	this->color_surface[2] = 0.37;
}

// Sets parameters for 3D position
void Vertex::setPosition(float x, float y, float z){
	this->x = (GLfloat) x;
	this->y = (GLfloat) y;
	this->z = (GLfloat) z;
}

// Set parameters for the material
void Vertex::setColor(float R, float G, float B){
	this->color_surface[0] = (GLfloat) R;
	this->color_surface[1] = (GLfloat) G;
	this->color_surface[2] = (GLfloat) B;
}

// Draw the node with a predefined body (Wire sphere)
void Vertex::draw(float dist_color){

	// Color for node
	glColor3f((color_surface[0] * dist_color)/255, color_surface[1], color_surface[2]);

	// Draw the node
	glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidSphere(radius, 10, 11);
	glPopMatrix();
}


// Destructor
Vertex::~Vertex(){}