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
	GLfloat demi_radius;
	GLfloat surface;
	GLfloat color_surface [3];
	Node(GLfloat radius, GLfloat surface);
	~Node();
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void setColor(GLfloat R, GLfloat G, GLfloat B);
	void draw(void);
	void drawBody(void);
};

#endif