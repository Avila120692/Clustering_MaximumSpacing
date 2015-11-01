/* Helper class implementation*/
#include "Helper.h"

using namespace std;

// Constructor
Helper::Helper() {}

// Draw an axis with a cone at the end : From CG using OpenGL - Hill and Kelley
void Helper::drawAxis(double length) {
	// Draw line
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, length);
	glEnd();

	glPushMatrix();
		// Draw cone
		glTranslated(0.0, 0.0, length - 0.2);
		glutSolidCone(0.04, 0.2, 12, 9);
	glPopMatrix();
	
}

void Helper::drawPlanes(){
	
	// Ground
	glColor3f(0.53, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3f(-100.0, -0.08, -100.0);
	glVertex3f(-100.0, -0.08, 100.0);
	glVertex3f(100.0, -0.08, 100.0);
	glVertex3f(100.0, -0.08, -100.0);
	glEnd();

	// Wall #1
	glColor3f(0.43, 0.28, 0.019);
	glBegin(GL_QUADS);
	glVertex3f(-0.02, 100.0f, 100.0);
	glVertex3f(-0.02, 100.0f, 0.0);
	glVertex3f(-0.02, 0.0, 0.0);
	glVertex3f(-0.02, 0.0, 100.0);
	glEnd();
	
	// Wall #2
	glColor3f(0.43, 0.28, 0.019);
	glBegin(GL_QUADS);
	glVertex3f(100.0, 100.0, -0.02);
	glVertex3f(0.0, 100.0, -0.02);
	glVertex3f(0.0, 0.0f, -0.02);
	glVertex3f(100.0f, 0.0, -0.02);
	glEnd();
}

// Print graphic enviroment
void Helper::drawGraphicEnviroment(){

	// Draw reference frame
	glLineWidth(4.5);

	// Draw origin
	glColor3f(0.0, 0.0, 0.0);
	glutSolidSphere(0.05, 10, 12);

	// Z axis
	glColor3f(0.0, 0.0, 1.0);
	drawAxis(12.0);

	// X axis
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotated(90.0, 0.0, 1.0, 0.0);
	drawAxis(12.0);
	glPopMatrix();

	// Y axis
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotated(-90.0, 1.0, 0.0, 0.0);
	drawAxis(12.0);
	glPopMatrix();

	// Planes (ground, walls)
	drawPlanes();
}


// Destructor
Helper::~Helper(){}