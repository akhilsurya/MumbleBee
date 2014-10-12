#include "model.hpp"

model::model(){
	leftShoulderAngle=0;
    leftElbowAngle=0;
    rightShoulderAngle=0;
    rightElbowAngle =0;

    leftThighAngle = 0;
    rightThighAngle = 0;

    leftLegAngle = 0;
    rightLegAngle = 0;
    
    neckAngle = 0;
    headAngle = 0;

	makeModel();
}

void model::makeModel() {
	makeCube();
	makeUpperArm();
	makeLowerArm();
	makeTorso();
	makeThigh();
	makeLeg();
	makeNeck();
	makeHead();
}


void model::drawModel() {
	/* The torso */
	glPushMatrix();
	{
		glScalef(2,2,2);
		glCallList(3);
	}
	glPopMatrix();

	/* The right arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(0.8,0.65,0.0);
		glRotatef(-rightShoulderAngle,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(-rightElbowAngle,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();

	/* The left arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.8,0.65,0.0);
		glRotatef(-180,0,0,1);
		glRotatef(leftShoulderAngle,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(leftElbowAngle,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();
	
	/* Left Leg */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(leftThighAngle,0.0,1.0,0.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(leftLegAngle,0, 1.0,0.0);
		glCallList(5);
	}
	glPopMatrix();
	
	/* Right Leg */

	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(+0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(rightThighAngle,0.0,1.0,0.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(rightLegAngle,0.0,1.0,0.0);
		glCallList(5);
	}
	glPopMatrix();
	
	/* Neck and head */
	
	glPushMatrix();
	{
		glTranslatef(0.0, 0.4, 0.0);
		
		glRotatef(neckAngle, 1.0, 0.0, 0.0);
		
		glPushMatrix();
		{
			glCallList(6);
		}
		glPopMatrix();
		glTranslatef(0.0, 0.2, 0.0);
		
		glRotatef(headAngle, 0.0, 1.0, 0.0);
		
		glCallList(7);
		
	}
	glPopMatrix();
}

void model::makeHead() {
	glNewList(7, GL_COMPILE);
		glScalef(0.15,0.15,0.15);
		
		glCallList(9);
	glEndList();
}

void model::makeTorso() {
	glNewList(3, GL_COMPILE);
		glScalef(0.2,0.2,0.1);
		glCallList(9);
	glEndList();
}

void model::makeLeg() {
	glNewList(5, GL_COMPILE);
		glScalef(0.5,0.2,0.2);
		glTranslatef(-1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeThigh() {
	glNewList(4, GL_COMPILE);
		glScalef(0.5,0.2,0.2);
		glTranslatef(-1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeLowerArm() {
	glNewList(2, GL_COMPILE);
		glScalef(0.5,0.1,0.1);
		glTranslatef(1,0,0);
		glCallList(9);
	glEndList();
}

void model::makeUpperArm() {
	glNewList(1, GL_COMPILE);
		glScalef(0.5,0.1,0.1);
		glTranslatef(0.9,0,0);
		glCallList(9);
	glEndList();
}

void model::makeNeck() {
	glNewList(6, GL_COMPILE);
		glScalef(0.1,0.1,0.1);
		glCallList(9);
	glEndList();
}



void model::makeCube() {
	glNewList(9, GL_COMPILE);
		glBegin(GL_POLYGON);             
			glColor3f(0.0f, 1.0f, 0.0f);     // Green
			glVertex3f( 1.0f, 1.0f, -1.0f);
			glVertex3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f,  1.0f);
			glVertex3f(-1.0f, 1.0f,  -1.0f);
		glEnd();
		// Front face  (z = 1.0f)
		glBegin(GL_POLYGON); 
			glColor3f(1.0f, 0.0f, 0.0f);     // Red
			glVertex3f( 1.0f,  1.0f, 1.0f);
			glVertex3f(1.0f,  -1.0f, 1.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
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


