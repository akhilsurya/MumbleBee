#include "model.hpp"
#include <iostream>

namespace model {
	void makeLeg() {
		glNewList(5,GL_COMPILE);
			glScalef(0.5,0.2,0.2);
			glTranslatef(-1,0,0);

			glBegin(GL_POLYGON);               // Begin drawing the color cube with 6 quads
			// Top face (y = 1.0f)
			// Define vertices in counter-clockwise (CCW) order with normal pointing out
				glColor3f(0.0f, 1.0f, 0.0f);     // Green
				glVertex3f( 1.0f, 1.0f, -1.0f);
				glVertex3f(1.0f, 1.0f, 1.0f);
				glVertex3f(-1.0f, 1.0f,  1.0f);
				glVertex3f( -1.0f, 1.0f,  -1.0f);
			glEnd();
			// Front face  (z = 1.0f)
			glBegin(GL_POLYGON); 
				glColor3f(1.0f, 0.0f, 0.0f);     // Red
				glVertex3f( 1.0f,  1.0f, 1.0f);
				glVertex3f(1.0f,  -1.0f, 1.0f);
				glVertex3f(-1.0f, -1.0f, 1.0f);
				glVertex3f( -1.0f, 1.0f, 1.0f);
			glEnd();

			//Bottom face (y=-1.0f)
			glBegin(GL_POLYGON); 
				glColor3f(1.0f, 0.5f, 0.0f);     // Orange
				glVertex3f( 1.0f, -1.0f,  1.0f);
				glVertex3f(1.0f, -1.0f,  -1.0f);
				glVertex3f(-1.0f, -1.0f, -1.0f);
				glVertex3f( -1.0f, -1.0f, 1.0f);
			glEnd(); 


			// Back face (z = -1.0f)
			glBegin(GL_POLYGON); 
				glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
				glVertex3f( 1.0f, -1.0f, -1.0f);
				glVertex3f(-1.0f, -1.0f, -1.0f);
				glVertex3f(-1.0f,  1.0f, -1.0f);
				glVertex3f( 1.0f,  1.0f, -1.0f);
			glEnd(); 
			// Left face (x = -1.0f)
			glBegin(GL_POLYGON); 
				glColor3f(0.0f, 0.0f, 1.0f);     // Blue
				glVertex3f(-1.0f,  1.0f,  1.0f);
				glVertex3f(-1.0f,  1.0f, -1.0f);
				glVertex3f(-1.0f, -1.0f, -1.0f);
				glVertex3f(-1.0f, -1.0f,  1.0f);
			glEnd(); 
			// Right face (x = 1.0f)
			glBegin(GL_POLYGON); 
				glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
				glVertex3f(1.0f,  1.0f, -1.0f);
				glVertex3f(1.0f,  1.0f,  1.0f);
				glVertex3f(1.0f, -1.0f,  1.0f);
				glVertex3f(1.0f, -1.0f, -1.0f);
			glEnd();
		glEndList();
	}
}