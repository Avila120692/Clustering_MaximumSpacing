/* Node Class implementation */
#include "Vertex.h"

using namespace std;

// Constructor
Vertex::Vertex(float x, float y, float z){
	this->radius = 0.1;
	
	this->x = (GLfloat) x;
	this->y = (GLfloat) y;
	this->z = (GLfloat) z;
	
	// Default material -> RED RUBY
	// Ambient
	this->mat_ambient[0] = 0.01175;
	this->mat_ambient[1] = 0.01175;

	this->mat_ambient[3] = 1.0;
	// Diffuse
	this->mat_diffuse[0] = 0.61424;
	this->mat_diffuse[1] = 0.04136;
	this->mat_diffuse[2] = 0.04136;
	this->mat_diffuse[3] = 1.0;
	// Specular
	this->mat_specular[0] = 0.727811;
	this->mat_specular[1] = 0.626959;
	this->mat_specular[2] = 0.626959;
	this->mat_specular[3] = 1.0;
	// Shiness
	this->mat_shininess[0] = 0.6 * 128; // phong exponent
	// Emmisive
	this->mat_emissive[0] = 1.0;
	this->mat_emissive[1] = 0.0;
	this->mat_emissive[2] = 0.0;
	this->mat_emissive[3] = 1.0;

}

// Sets parameters for 3D position
void Vertex::setPosition(float x, float y, float z){
	this->x = (GLfloat) x;
	this->y = (GLfloat) y;
	this->z = (GLfloat) z;
}

// Set parameters for the material
void Vertex::setMaterial(float MatEnv_R, float MatEnv_G, float MatEnv_B){
	// Modify material paremeters
	this->mat_ambient[0] = (GLfloat) MatEnv_R;
	this->mat_ambient[1] = (GLfloat) MatEnv_G;
	this->mat_ambient[2] = (GLfloat) MatEnv_B;
	this->mat_ambient[3] = 1.0;
}

// Draw the node with a predefined body (Wire sphere)
void Vertex::draw(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);

	// Draw the node
	glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidSphere(radius, 10, 11);
	glPopMatrix();
}


// Destructor
Vertex::~Vertex(){}