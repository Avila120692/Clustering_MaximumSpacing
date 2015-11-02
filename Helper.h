/* Helper class definition*/
#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include "glut.h"

using namespace std;

#ifndef __HELPER__

#define __HELPER__

class Helper {

public:
	Helper();
	~Helper();

	void drawAxis(double length);
	void drawPlanes();
	void drawGraphicEnviroment();
};

#endif
