/* Node Class implementation */
#include "Vertex.h"

// Constructor
Vertex::Vertex(GLfloat radius, GLfloat surface){
	this->radius = radius;
	this->surface = surface;
	demi_radius = radius - 0.4;
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
	glutWireSphere(radius, 10, 11);
	glPopMatrix();
}

// Draw the node with a constructed body
void Vertex::drawBody(void){
	// Color for polygons forming the node
	glColor3f(color_surface[0], color_surface[1], color_surface[2]);

	// Draw the polygon(s)
	glBegin(GL_POLYGON);
	// Face # 1
	glVertex3f((x), (y), (z + radius)); // Face middle point
	glVertex3f((x - surface / 2), (y - surface / 2), (z + demi_radius));
	glVertex3f((x + surface / 2), (y - surface / 2), (z + demi_radius));
	glVertex3f((x + surface / 2), (y + surface / 2), (z + demi_radius));
	glVertex3f((x - surface / 2), (y + surface / 2), (z + demi_radius));
	glVertex3f((x - surface / 2), (y - surface / 2), (z + demi_radius));

	// Face # 2
	glVertex3f((x - surface / 2), (y - surface / 2), (z + demi_radius));
	glVertex3f((x - demi_radius), (y - surface / 2), (z - surface / 2));
	glVertex3f((x - demi_radius), (y + surface / 2), (z - surface / 2));
	glVertex3f((x - radius), (y), (z)); // Face middle point
	glVertex3f((x - demi_radius), (y + surface / 2), (z + surface / 2));
	glVertex3f((x - demi_radius), (y + surface / 2), (z - surface / 2));


	//Face # 3
	glVertex3f((x - surface / 2), (y + surface / 2), (z - demi_radius));
	glVertex3f((x - surface / 2), (y + surface / 2), (z - demi_radius));
	glEnd();
}

// Destructor
Vertex::~Vertex(){}