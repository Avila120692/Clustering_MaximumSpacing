/* Node Class definition*/
#include <iostream>
#include "glui.h"

#ifndef __VERTEX__

#define __VERTEX__

class Vertex{

public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat radius;
	GLfloat color_surface[3];
	Vertex(float x, float y, float z);
	~Vertex();

	void setPosition(float x, float y, float z);
	void setColor(float R, float G, float B);
	void draw(float dist_color);
};

#endif