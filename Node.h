/* Node Class definition*/
#include <windows.h>
#include <GL/gl.h>
#include "glut.h"

#ifndef __NODE__

#define __NODE__

class Node {

public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat radius;
	GLfloat material_surface[];
	Node(GLfloat radius);
	~Node();
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void setMaterial(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
	void drawBody(void);
};

#endif