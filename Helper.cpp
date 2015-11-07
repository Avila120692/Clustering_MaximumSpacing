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

	// Set material properties -> GOLD
	GLfloat mat_ambient[] = { 0.2125, 0.1275, 0.054, 1.0 };
	GLfloat mat_diffuse[] = { 0.714, 0.4284, 0.18144, 1.0 };
	GLfloat mat_specular[] = { 0.393548, 0.271906, 0.166721, 0.2 };
	GLfloat mat_shininess[] = { 0.4 * 128}; 
	GLfloat mat_emissive[] = { 0.0, 0.0, 0.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);

	// Ground
	glBegin(GL_QUADS);
	glVertex3f(-100.0, -0.08, -100.0);
	glVertex3f(-100.0, -0.08, 100.0);
	glVertex3f(100.0, -0.08, 100.0);
	glVertex3f(100.0, -0.08, -100.0);
	glEnd();

	// Set material properties -> SILVER
	GLfloat mat_ambient1[] = { 0.19225, 0.19225, 0.19225, 1.0 };
	GLfloat mat_diffuse1[] = { 0.50754, 0.50754, 0.50754, 1.0 };
	GLfloat mat_specular1[] = { 0.508273, 0.508273, 0.508273, 1.0 };
	GLfloat mat_shininess1[] = { 0.4 * 128}; // phong exponent

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);

	// Wall #1
	glBegin(GL_QUADS);
	glVertex3f(-0.02, 100.0f, 100.0);
	glVertex3f(-0.02, 100.0f, 0.0);
	glVertex3f(-0.02, 0.0, 0.0);
	glVertex3f(-0.02, 0.0, 100.0);
	glEnd();
	
	// Wall #2
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

	// Z axis
	// Set material properties -> CYAN PLASTIC
	GLfloat mat_ambientZ[] = { 0.0, 0.1, 0.06, 1.0 };
	GLfloat mat_diffuseZ[] = { 0.0, 0.50980392, 0.50980392, 1.0 };
	GLfloat mat_specularZ[] = { 0.50196078, 0.50196078, 0.50196078, 1.0 };
	GLfloat mat_shininessZ[] = { 0.25 };
	GLfloat mat_emissive[] = { 0.0, 0.0, 0.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientZ);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseZ);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularZ);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininessZ);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emissive);
	drawAxis(12.0);

	// Draw origin
	glutSolidSphere(0.05, 10, 12);

	// X axis
	// Set material properties -> RED PLASTIC
	GLfloat mat_ambientX[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuseX[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat mat_specularX[] = { 0.7, 0.6, 0.6, 1.0 };
	GLfloat mat_shininessX[] = { 0.25 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientX);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseX);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularX);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininessX);
	
	// Draw axis
	glPushMatrix();
	glRotated(90.0, 0.0, 1.0, 0.0);
	drawAxis(12.0);
	glPopMatrix();

	// Y axis
	// Set material properties -> GREEN PLASTIC
	GLfloat mat_ambientY[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuseY[] = { 0.1, 0.35, 0.1, 1.0 };
	GLfloat mat_specularY[] = { 0.45, 0.55, 0.45, 1.0 };
	GLfloat mat_shininessY[] = { 0.25 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientY);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseY);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularY);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininessY);

	glPushMatrix();
	glRotated(-90.0, 1.0, 0.0, 0.0);
	drawAxis(12.0);
	glPopMatrix();

	// Planes (ground, walls)
	drawPlanes();
}


// Destructor
Helper::~Helper(){}