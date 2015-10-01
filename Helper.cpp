/* Helper class implementation*/
#include "Helper.h"

using namespace std;

// Constructor
Helper::Helper(int n) {

}

// Draw an axis with a cone at the end : From CG using OpenGL - Hill and Kelley
void Helper::drawAxis(double length) {
	
	glPushMatrix();

	// Draw line
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, length);
	glEnd();

	// Draw cone
	glTranslated(0.0, 0.0, length - 0.2);
	glutSolidCone(0.04, 0.2, 12, 9);

	glPopMatrix();
}

// Print graphic enviroment
void Helper::drawGraphicEnviroment(){

	// Draw reference frame
	glLineWidth(1.0);

	// Z axis
	glColor3f(1.0, 0.0, 0.0);
	drawAxis(3.0);

	// X axis
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotated(90.0, 0.0, 1.0, 0.0);
	drawAxis(3.0);
	glPopMatrix();

	// Y axis
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotated(-90.0, 1.0, 0.0, 0.0);
	drawAxis(2.5);
	glPopMatrix();
}


// Destructor
Helper::~Helper(){}