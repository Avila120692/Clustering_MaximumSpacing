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
	GLfloat mat_ambient[4];
	GLfloat mat_diffuse[4];
	GLfloat mat_specular[4];
	GLfloat mat_shininess[1];
	GLfloat mat_emissive[4];
	Vertex(float x, float y, float z);
	~Vertex();

	void setPosition(float x, float y, float z);
	void setMaterial(float R, float G, float B);
	void setEmission(float glow_R, float glow_G, float glow_B);
	float getPosition_X();
	void draw();
};

#endif